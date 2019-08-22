#ifndef RL_ALGORITHMS_LIB_TREES_RED_BLACK_TREE_HPP
#define RL_ALGORITHMS_LIB_TREES_RED_BLACK_TREE_HPP
#include <iostream>

using std::cout;
using std::endl;

namespace trees
{

class Node
{
public:
  int key;
  Node *left;
  Node *right;

  // If link from parent is red, we mark Node as red.
  bool color; // true === RED, false === BLACK

  Node(int key)
  {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
  }

  bool isRed()
  {
    return this->color;
  }
};

/**
 * Left leaning rb tree implementation.
 */
class Red_black_tree
{
private:
  Node *_root;

private:
  /**
   * The idea of rotating left is to fix red links leaning right.
   */
  Node *rotateLeft(Node *n)
  {
    // TODO
    return nullptr;
  }

public:
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
};

} // namespace trees
#endif
