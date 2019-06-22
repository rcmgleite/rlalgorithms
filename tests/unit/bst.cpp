#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/trees/bst/bst.hpp"

namespace unit_tests {

using namespace std;

TEST(TREES_BST, PUT_AND_GET) {
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

};
