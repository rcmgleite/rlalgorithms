#ifndef RL_ALGORITHMS_LIB_TREES_SORTED_ARRAY_TO_BST_HPP
#define RL_ALGORITHMS_LIB_TREES_SORTED_ARRAY_TO_BST_HPP

#include <vector>
#include "bst.hpp"
/*
 * Given a sorted (increasing order) array, write an algorithm to create a binary tree with
 * minimal height.
 * 
 * Example 1:
 * A = [1, 2, 3, 4, 5, 6, 7]
 *      0, 1, 2, 3, 4, 5, 6
 * 
 *       4
 *     /   \
 *    2     6
 *   / \   /  \
 *  1   3 5    7
 * 
 * Example 2
 * A = [1, 2, 3, 4, 5, 6, 7, 8]
 *      0, 1, 2, 3, 4, 5, 6, 7
 * 
 *       4
 *     /   \
 *    2     6
 *   / \   /  \
 *  1   3 5    7
 *              \
 *               8
 */
namespace trees
{
using std::vector;

void toBST(vector<int> &a, int begin, int end, BST &t)
{
  if (begin > end)
  {
    return;
  }

  int mid = begin + (end - begin) / 2;
  t.put(a[mid]);

  toBST(a, begin, mid - 1, t);
  toBST(a, mid + 1, end, t);
}

BST toBST(vector<int> &a)
{
  BST t;
  int begin = 0;
  int end = a.size() - 1;

  toBST(a, begin, end, t);
  return t;
}

} // namespace trees

#endif
