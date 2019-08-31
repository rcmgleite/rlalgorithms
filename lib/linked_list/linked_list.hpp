#ifndef RL_ALGORITHMS_LINKED_LIST_LINKED_LIST_HPP
#define RL_ALGORITHMS_LINKED_LIST_LINKED_LIST_HPP

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

namespace linked_list
{

class Node
{
public:
  Node(int value) : value(value), next(nullptr) {}
  int value;
  Node *next;
};

class Linked_list
{
private:
  Node *head;
  int _size;

public:
  Linked_list() : head(nullptr), _size(0) {}
  ~Linked_list()
  {
    Node *p = head;

    while (p)
    {
      Node *d = p;
      p = p->next;
      delete d;
    }
  }
  void push_back(int value)
  {
    Node **cur = &head;
    while (*cur)
    {
      cur = &((*cur)->next);
    }

    *cur = new Node(value);
    _size++;
  }

  void push_front(int value)
  {
    Node *p = head;
    Node *n = new Node(value);
    head = n;
    n->next = p;
    _size++;
  }

  void remove_node(Node **n)
  {
    Node *aux = *n;
    *n = (*n)->next;
    delete aux;
    _size--;
  }

  void remove(int value)
  {
    Node **cur = &head;
    while (*cur)
    {
      Node *entry = *cur;
      if (entry->value == value)
      {
        remove_node(cur);
        return;
      }

      cur = &(*cur)->next;
    }
  }

  void remove_duplicates_map()
  {
    map<int, Node **> duplicates;
    Node **cur = &head;

    while (*cur)
    {
      if (duplicates[(*cur)->value])
      {
        remove_node(cur);
      }
      else
      {
        duplicates[(*cur)->value] = cur;
        cur = &(*cur)->next;
      }
    }
  }

  int get_nth(int n)
  {
    int counter = 0;
    Node *cur = head;
    while (cur && counter != n)
    {
      cur = cur->next;
      counter++;
    }

    if (cur)
    {
      return cur->value;
    }

    return -1;
  }

  void print()
  {
    Node *p = head;
    while (p)
    {
      cout << p->value << " ";
      p = p->next;
    }

    cout << endl;
  }

  int size()
  {
    return _size;
  }
};

}; // namespace linked_list
#endif
