#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/all_subsets_of_a_set.hpp"

namespace unit_tests
{
using namespace std;
using namespace recursion;

/*
  []

  [1]

  [2]
  [1, 2]

  [3]
  [1, 3]
  [2, 3]
  [1, 2, 3]
 */
TEST(RECURSION, ALL_SUBSETS_OF_A_SET)
{
  auto initial_set = vector<int>{1, 2, 3};
  auto result = recursion::all_subsets_of_a_set(initial_set);

  EXPECT_EQ(result[0].size(), 0);
  EXPECT_EQ(result[1][0], 1);
  EXPECT_EQ(result[2][0], 2);
  EXPECT_EQ(result[3][0], 1);
  EXPECT_EQ(result[3][1], 2);
  EXPECT_EQ(result[4][0], 3);
  EXPECT_EQ(result[5][0], 1);
  EXPECT_EQ(result[5][1], 3);
  EXPECT_EQ(result[6][0], 2);
  EXPECT_EQ(result[6][1], 3);
  EXPECT_EQ(result[7][0], 1);
  EXPECT_EQ(result[7][1], 2);
  EXPECT_EQ(result[7][2], 3);
}
} // namespace unit_tests
