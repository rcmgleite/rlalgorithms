#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "../../lib/dp/largest_square_of_1s_matrix/largest_square_of_1s_matrix.hpp"

namespace unit_tests
{

using namespace std;

TEST(DP, LARGEST_SQUARE_OF_1S_MATRIX_1)
{
  vector<vector<int>> m = {
      {1, 1, 0, 1, 0},
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 0},
      {0, 1, 1, 1, 1},
  };

  int result = dp::largest_square_of_1s_matrix(m);
  EXPECT_EQ(result, 3);
}

TEST(DP, LARGEST_SQUARE_OF_1S_MATRIX_2)
{
  vector<vector<int>> m = {
      {1, 1, 1, 1, 0},
      {1, 1, 1, 1, 0},
      {1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1},
  };

  int result = dp::largest_square_of_1s_matrix(m);
  EXPECT_EQ(result, 4);
}

TEST(DP, LARGEST_SQUARE_OF_1S_MATRIX_3)
{
  vector<vector<int>> m = {
      {0, 1, 1, 1, 0},
      {0, 1, 1, 1, 0},
      {0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0},
  };

  int result = dp::largest_square_of_1s_matrix(m);
  EXPECT_EQ(result, 2);
}

TEST(DP, LARGEST_SQUARE_OF_1S_MATRIX_4)
{
  vector<vector<int>> m = {
      {0, 0, 0, 1, 1},
      {0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };

  int result = dp::largest_square_of_1s_matrix(m);
  EXPECT_EQ(result, 1);
}

}; // namespace unit_tests
