#ifndef RL_ALGORITHMS_LIB_TREES_BST_HPP
#define RL_ALGORITHMS_LIB_TREES_BST_HPP

#include <iostream>

using std::cout;
using std::endl;

namespace trees {

/**
 * Node representation.
 * Currently key and value are the same and can only hold int values.
 */
class Node {
public:
  int key;
  Node* left;
  Node* right; 

  Node(int key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
  }
};

/**
 * Bst representation.
 */
class BST {
private:
  Node* _root;

private:

Node* put(Node* n, int key) {
  if (n == nullptr) {
    return new Node(key);
  }

  if (n->key == key) {
    return n;
  }

  if (key > n->key) {
    n->right = put(n->right, key);
  } else {
    n->left = put(n->left, key);
  }

  return n;
}

int floor(Node* n, int input) {
  if (n == nullptr) {
    return -1;
  }

  if (input == n->key) {
    return input;
  }

  if (input < n->key) {
    return floor(n->left, input);
  }

  int f = floor(n->right, input);
  if (f != -1) {
    return f;
  }

  return n->key;
}

int ceiling(Node* n, int input) {
  if (n == nullptr) {
    return -1;
  }

  if (input == n->key) {
    return input;
  }

  if (input > n->key) {
    return ceiling(n->right, input);
  }

  int c = ceiling(n->left, input);
  if (c != -1) {
    return c;
  }

  return n->key;
}

void print_in_order(Node* n) {
  if (n == nullptr) {
    return;
  }

  print_in_order(n->left);
  cout << n->key << " ";
  print_in_order(n->right);
}

public:
  /**
   * Get key from bst.
   */
  int get(int key) {
    auto iter = _root;

    while(iter) {
      if (key == iter->key) {
        return iter->key;
      }

      if (key > iter->key) {
        iter = iter->right;
      } else {
        iter = iter->left;
      }
    }

    return -1;
  }

  /**
   * Add new key to bst.
   */
  void put(int key) {
    _root = put(_root, key);
  }

  /**
   * Remove a node from bst.
   */
  void remove(int key) {
    // TODO
  }

  /**
   * Min value inside bst.
   */
  int min() {
    Node* n = _root;

    int min = -1;
    while(n) {
      min = n->key;
      n = n->left;
    }

    return min;
  }

  /**
   * Max key inside bst.
   */
  int max() {
    Node* n = _root;

    int max = -1;
    while(n) {
      max = n->key;
      n = n->right;
    }

    return max;
  }

  /**
   * Largest key <= @key.
   */
  int floor(int input) {
    return floor(_root, input);
  }

  /**
   * Smallest key >= @key.
   */
  int ceiling(int input) {
    return ceiling(_root, input);
  }

  /**
   * Print bst in order (sorted).
   */
  void print_in_order() {
    print_in_order(_root);
    cout << endl;
  }
};

};

#endif
