#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include "../../lib/matrix/rotate.hpp"

namespace unit_tests
{

using namespace std;

TEST(MATRIX, 4_WAY_SWAP_1)
{
  matrix::matrix_t m = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };

  matrix::matrix_t expected = {
      {13, 9, 5, 1},
      {14, 10, 6, 2},
      {15, 11, 7, 3},
      {16, 12, 8, 4},
  };

  matrix::rotate_4_way_swap(m);
  EXPECT_TRUE(matrix::equals_4_way(m, expected));
}

TEST(MATRIX, 4_WAY_SWAP_2)
{
  matrix::matrix_t m = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  matrix::matrix_t expected = {
      {7, 4, 1},
      {8, 5, 2},
      {9, 6, 3}};

  matrix::rotate_4_way_swap(m);
  EXPECT_TRUE(matrix::equals_4_way(m, expected));
}

} // namespace unit_tests