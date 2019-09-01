#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/n_queens.hpp"

namespace unit_tests
{
using namespace std;
using namespace recursion;

TEST(RECURSION, N_QUEENS_1)
{
  auto board = solve_n_queens(4);
  board_t expected_result = {
      {0, 1, 0, 0},
      {0, 0, 0, 1},
      {1, 0, 0, 0},
      {0, 0, 1, 0}};

  EXPECT_TRUE(compare_boards(board, expected_result));
}

TEST(RECURSION, N_QUEENS_2)
{
  auto board = solve_n_queens(8);
  board_t expected_result = {
      {1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0},
  };

  EXPECT_TRUE(compare_boards(board, expected_result));
}

TEST(RECURSION, N_QUEENS_V2_1)
{
  auto board = solve_n_queens_v2(4);
  board_t expected_result = {
      {0, 1, 0, 0},
      {0, 0, 0, 1},
      {1, 0, 0, 0},
      {0, 0, 1, 0}};

  EXPECT_TRUE(compare_boards(board, expected_result));
}

TEST(RECURSION, N_QUEENS_V2_2)
{
  auto board = solve_n_queens_v2(8);
  board_t expected_result = {
      {1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0},
      {0, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0, 0},
  };

  EXPECT_TRUE(compare_boards(board, expected_result));
}

} // namespace unit_tests