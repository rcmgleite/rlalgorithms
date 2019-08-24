#ifndef RL_ALGORITHMS_LINKED_LIST_LINKED_LIST_HPP
#define RL_ALGORITHMS_LINKED_LIST_LINKED_LIST_HPP

#include <iostream>

using std::cout;
using std::endl;

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

public:
  Linked_list() : head(nullptr) {}
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
  }

  void push_front(int value)
  {
    Node *p = head;
    Node *n = new Node(value);
    head = n;
    n->next = p;
  }

  void remove(int value)
  {
    Node **cur = &head;
    while (*cur)
    {
      Node *entry = *cur;
      if (entry->value == value)
      {
        *cur = entry->next;
        delete entry;
        return;
      }

      cur = &(*cur)->next;
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
};

}; // namespace linked_list
#endif
