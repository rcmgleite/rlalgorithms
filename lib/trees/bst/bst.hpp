#ifndef RL_ALGORITHMS_LIB_TREES_BST_HPP
#define RL_ALGORITHMS_LIB_TREES_BST_HPP

#include <iostream>

using std::cout;
using std::endl;

namespace trees {

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

void print_in_order(Node* n) {
  if (n == nullptr) {
    return;
  }

  print_in_order(n->left);
  cout << n->key << " ";
  print_in_order(n->right);
}

public:
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

  void put(int key) {
    _root = put(_root, key);
  }

  void remove(int key) {

  }

  void print_in_order() {
    print_in_order(_root);
    cout << endl;
  }
};

};

#endif