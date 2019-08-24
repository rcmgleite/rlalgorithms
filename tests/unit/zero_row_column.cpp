#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/matrix/zero_row_column.hpp"

namespace unit_tests
{

using namespace std;

bool equals(matrix::matrix_t &m1, matrix::matrix_t &m2)
{
  for (size_t i = 0; i < m1.size(); i++)
  {
    for (size_t j = 0; j < m1[0].size(); j++)
    {
      if (m1[i][j] != m2[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

TEST(MATRIX, ZERO_ROW_COLUMN_1)
{
  matrix::matrix_t input(
      {{1, 1, 1, 1, 1},
       {1, 1, 1, 0, 1},
       {1, 1, 1, 1, 1},
       {1, 0, 1, 1, 1},
       {1, 1, 1, 1, 1}});

  matrix::matrix_t expected(
      {{1, 0, 1, 0, 1},
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1},
       {0, 0, 0, 0, 0},
       {1, 0, 1, 0, 1}});

  matrix::zero_row_column(input);
  EXPECT_EQ(equals(input, expected), true);
}

}; // namespace unit_tests
