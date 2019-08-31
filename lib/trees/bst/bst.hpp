#ifndef RL_ALGORITHMS_LIB_TREES_BST_HPP
#define RL_ALGORITHMS_LIB_TREES_BST_HPP

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

namespace trees
{

/**
 * Node representation.
 * Currently key and value are the same and can only hold int values.
 */
class Node
{
public:
  int key;
  Node *left;
  Node *right;

  Node(int key) : key(key), left(nullptr), right(nullptr) { }
  };

/**
 * Bst representation.
 */
class BST
{
private:
  Node *_root;

private:
  Node *put(Node *n, int key)
  {
    if (n == nullptr)
    {
      return new Node(key);
    }

    if (n->key == key)
    {
      return n;
    }

    if (key > n->key)
    {
      n->right = put(n->right, key);
    }
    else
    {
      n->left = put(n->left, key);
    }

    return n;
  }

  int floor(Node *n, int input)
  {
    if (n == nullptr)
    {
      return -1;
    }

    if (input == n->key)
    {
      return input;
    }

    if (input < n->key)
    {
      return floor(n->left, input);
    }

    int f = floor(n->right, input);
    if (f != -1)
    {
      return f;
    }

    return n->key;
  }

  int ceiling(Node *n, int input)
  {
    if (n == nullptr)
    {
      return -1;
    }

    if (input == n->key)
    {
      return input;
    }

    if (input > n->key)
    {
      return ceiling(n->right, input);
    }

    int c = ceiling(n->left, input);
    if (c != -1)
    {
      return c;
    }

    return n->key;
  }

  Node *remove(Node *n, int key)
  {
    if (n == nullptr)
    {
      return nullptr;
    }

    if (key > n->key)
    {
      n->right = remove(n->right, key);
    }
    else if (key < n->key)
    {
      n->left = remove(n->left, key);
    }
    else
    {
      // At this point, we found the node to be deleted.
      // We need to take care of 4 cases:
      //   1. Node has 0 children.
      if (n->left == nullptr && n->right == nullptr)
      {
        delete n;
        return nullptr;
      }

      //   2. Node has only right child.
      if (n->left == nullptr)
      {
        Node *ret = n->right;
        delete n;
        return ret;
      }

      //   3. Node has only left child.
      if (n->right == nullptr)
      {
        Node *ret = n->left;
        delete n;
        return ret;
      }

      //   4. Node has both children.
      // in this case we will:
      //   1. find the smallest elem on the right subtree
      //   2. delete this node from the right subtree
      //   3. replace the node to be deleted with the minimum of the right subtree
      Node *replacement = min_node(n->right);
      Node *new_node = new Node(replacement->key);
      new_node->right = remove(n->right, replacement->key);
      new_node->left = n->left;

      delete n;
      n = new_node;
    }

    return n;
  }

  int max_depth(Node *n)
  {
    if (n == nullptr)
    {
      return 0;
    }

    return 1 + std::max(max_depth(n->left), max_depth(n->right));
  }

  int min_depth(Node *n)
  {
    if (n == nullptr)
    {
      return 0;
    }

    return 1 + std::min(min_depth(n->left), min_depth(n->right));
  }

  void print_in_order(Node *n)
  {
    if (n == nullptr)
    {
      return;
    }

    print_in_order(n->left);
    cout << n->key << " ";
    print_in_order(n->right);
  }

public:
  BST() : _root(nullptr) {}

  ~BST()
  {
    while (_root)
    {
      _root = remove(_root, _root->key);
    }
  }

  /**
   * Get key from bst.
   */
  int get(int key)
  {
    auto iter = _root;

    while (iter)
    {
      if (key == iter->key)
      {
        return iter->key;
      }

      if (key > iter->key)
      {
        iter = iter->right;
      }
      else
      {
        iter = iter->left;
      }
    }

    return -1;
  }

  /**
   * Add new key to bst.
   */
  void put(int key)
  {
    _root = put(_root, key);
  }

  /**
   * Remove a node from bst.
   * (Hibbard method)
   */
  void remove(int key)
  {
    _root = remove(_root, key);
  }

  /**
   * Min value inside bst.
   */
  int min()
  {
    Node *n = min_node();
    if (n == nullptr)
    {
      return -1;
    }
    return n->key;
  }

  Node *min_node(Node *n)
  {
    if (n == nullptr)
    {
      return nullptr;
    }

    while (n->left)
    {
      n = n->left;
    }

    return n;
  }

  Node *min_node()
  {
    return min_node(_root);
  }

  /**
   * Max key inside bst.
   */
  int max()
  {
    Node *n = _root;

    int max = -1;
    while (n)
    {
      max = n->key;
      n = n->right;
    }

    return max;
  }

  /**
   * Largest key <= @key.
   */
  int floor(int input)
  {
    return floor(_root, input);
  }

  /**
   * Smallest key >= @key.
   */
  int ceiling(int input)
  {
    return ceiling(_root, input);
  }

  int max_depth()
  {
    return max_depth(_root);
  }

  int min_depth()
  {
    return min_depth(_root);
  }

  /**
   * Print bst in order (sorted).
   */
  void print_in_order()
  {
    print_in_order(_root);
    cout << endl;
  }
};

}; // namespace trees

#endif
