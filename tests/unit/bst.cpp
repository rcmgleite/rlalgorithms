#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/trees/bst/bst.hpp"
#include "../../lib/trees/bst/sorted_array_to_bst.hpp"

namespace unit_tests
{

using namespace std;

TEST(TREES_BST, PUT_AND_GET)
{
  auto bst = trees::BST();

  bst.put(10);
  bst.put(5);
  bst.put(2);
  bst.put(7);
  bst.put(21);

  EXPECT_EQ(bst.get(10), 10);
  EXPECT_EQ(bst.get(5), 5);
  EXPECT_EQ(bst.get(2), 2);
  EXPECT_EQ(bst.get(7), 7);
  EXPECT_EQ(bst.get(21), 21);
  EXPECT_EQ(bst.get(100), -1);
  EXPECT_EQ(bst.get(0), -1);
}

TEST(TREES_BST, MAX_MIN)
{
  auto bst = trees::BST();
  EXPECT_EQ(bst.min(), -1);
  EXPECT_EQ(bst.max(), -1);

  bst.put(10);
  EXPECT_EQ(bst.min(), 10);
  EXPECT_EQ(bst.max(), 10);

  bst.put(5);
  EXPECT_EQ(bst.min(), 5);
  EXPECT_EQ(bst.max(), 10);

  bst.put(2);
  EXPECT_EQ(bst.min(), 2);
  EXPECT_EQ(bst.max(), 10);

  bst.put(7);
  EXPECT_EQ(bst.min(), 2);
  EXPECT_EQ(bst.max(), 10);

  bst.put(21);
  EXPECT_EQ(bst.min(), 2);
  EXPECT_EQ(bst.max(), 21);
}

TEST(TREES_BST, FLOOR)
{
  auto bst = trees::BST();

  bst.put(10);
  bst.put(7);
  bst.put(3);
  bst.put(5);
  bst.put(8);
  bst.put(1);
  bst.put(12);

  EXPECT_EQ(bst.floor(10), 10);
  EXPECT_EQ(bst.floor(6), 5);
  EXPECT_EQ(bst.floor(7), 7);
  EXPECT_EQ(bst.floor(12), 12);
  EXPECT_EQ(bst.floor(9), 8);
  EXPECT_EQ(bst.floor(20), 12);
  EXPECT_EQ(bst.floor(2), 1);
  EXPECT_EQ(bst.floor(0), -1);
}

TEST(TREES_BST, CEILING_1)
{
  auto bst = trees::BST();

  bst.put(10);
  bst.put(7);
  bst.put(2);
  bst.put(5);
  bst.put(8);
  bst.put(1);
  bst.put(12);

  EXPECT_EQ(bst.ceiling(7), 7);
  EXPECT_EQ(bst.ceiling(8), 8);
  EXPECT_EQ(bst.ceiling(9), 10);
  EXPECT_EQ(bst.ceiling(11), 12);
  EXPECT_EQ(bst.ceiling(13), -1);
}

TEST(TREES_BST, CEILING_2)
{
  auto bst = trees::BST();

  bst.put(10);
  bst.put(7);
  bst.put(2);
  bst.put(5);
  bst.put(8);
  bst.put(9);
  bst.put(1);
  bst.put(12);

  EXPECT_EQ(bst.ceiling(7), 7);
  EXPECT_EQ(bst.ceiling(8), 8);
  EXPECT_EQ(bst.ceiling(9), 9);
  EXPECT_EQ(bst.ceiling(11), 12);
  EXPECT_EQ(bst.ceiling(13), -1);
}

TEST(TREES_BST, INSERT_REMOVE)
{
  auto bst = trees::BST();
  bst.put(10);
  bst.put(7);
  bst.put(2);
  bst.put(5);
  bst.put(8);
  bst.put(9);
  bst.put(1);
  bst.put(12);

  bst.remove(2);
  EXPECT_EQ(bst.get(2), -1);
  EXPECT_EQ(bst.get(1), 1);
  EXPECT_EQ(bst.get(5), 5);

  bst.remove(10);
  EXPECT_EQ(bst.get(5), 5);

  bst.remove(9);
  EXPECT_EQ(bst.get(9), -1);

  bst.remove(12);
  EXPECT_EQ(bst.get(12), -1);
  bst.remove(8);
  EXPECT_EQ(bst.get(8), -1);

  bst.remove(7);
  EXPECT_EQ(bst.get(7), -1);

  bst.remove(1);
  EXPECT_EQ(bst.get(1), -1);

  bst.remove(5);
  EXPECT_EQ(bst.get(5), -1);
}

TEST(TREES_BST, MAX_MIN_DEPTH)
{
  auto bst = trees::BST();

  bst.put(10);
  bst.put(7);
  bst.put(2);
  bst.put(5);
  bst.put(8);
  bst.put(9);
  bst.put(1);
  bst.put(12);

  EXPECT_EQ(bst.max_depth(), 4);
  EXPECT_EQ(bst.min_depth(), 2);
}

TEST(TREES_BST, SORTED_ARRAY_TO_BST_1)
{
  std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
  auto bst = trees::toBST(a);

  EXPECT_EQ(bst.max_depth(), 3);
  EXPECT_EQ(bst.min_depth(), 3);
}

TEST(TREES_BST, SORTED_ARRAY_TO_BST_2)
{
  std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
  auto bst = trees::toBST(a);

  EXPECT_EQ(bst.max_depth(), 4);
  EXPECT_EQ(bst.min_depth(), 3);
}

TEST(TREES_BST, FIND_LEVEL_LINK_LIST)
{
  std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
  auto bst = trees::toBST(a);

  vector<linked_list::Linked_list *> result = bst.find_level_link_list();
  EXPECT_EQ(result[0]->get_nth(0), 4);
  EXPECT_EQ(result[1]->get_nth(0), 2);
  EXPECT_EQ(result[1]->get_nth(1), 6);
  EXPECT_EQ(result[2]->get_nth(0), 1);
  EXPECT_EQ(result[2]->get_nth(1), 3);
  EXPECT_EQ(result[2]->get_nth(2), 5);
  EXPECT_EQ(result[2]->get_nth(3), 7);
  EXPECT_EQ(result[3]->get_nth(0), 8);

  for (auto v : result)
  {
    delete v;
  }
}

}; // namespace unit_tests
