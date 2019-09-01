#ifndef RL_ALGORITHMS_LIB_RECURSION_N_QUEENS
#define RL_ALGORITHMS_LIB_RECURSION_N_QUEENS

#include <iostream>
#include <vector>

namespace recursion
{
using std::cout;
using std::endl;
using std::vector;
using board_t = vector<vector<int>>;

bool compare_boards(board_t &b1, board_t &b2)
{
  for (int i = 0; i < b1.size(); i++)
  {
    for (int j = 0; j < b1[0].size(); j++)
    {
      if (b1[i][j] != b2[i][j])
      {
        return false;
      }
    }
  }

  return true;
} // namespace recursion

void print_board(board_t &b)
{
  cout << "PRINT_BOARD_BEGIN" << endl;
  for (int i = 0; i < b.size(); i++)
  {
    for (int j = 0; j < b[0].size(); j++)
    {
      cout << b[i][j] << " ";
    }

    cout << endl;
  }
  cout << "PRINT_BOARD_END" << endl;
}

bool is_safe(board_t &b, int row, int col)
{
  for (int i = 0; i < b.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      // row and column
      if (b[i][j] == 1 && (i == row || j == col))
      {
        return false;
      }

      // diagonal
      if (b[i][j] == 1 && std::abs(i - row) == std::abs(j - col))
      {
        return false;
      }
    }
  }

  return true;
}

bool solve_n_queens(board_t &b, int row)
{
  // Found solution.
  if (row == b.size())
  {
    return true;
  }

  // test all columns for the given row
  for (int col = 0; col < b[row].size(); col++)
  {
    if (is_safe(b, row, col))
    {
      // mark path and go to next row
      b[row][col] = 1;
      if (solve_n_queens(b, row + 1))
      {
        // all good, finish
        return true;
      }

      // backtrack
      b[row][col] = 0;
    }
  }

  return false;
}

board_t solve_n_queens(int n)
{
  board_t board = board_t(n, vector<int>(n));
  solve_n_queens(board, 0);
  return board;
}

bool is_safe_v2(vector<int> column_for_row, int row, int column)
{
  for (int i = 0; i < row; i++)
  {
    // check row
    if (column_for_row[i] == column_for_row[row])
    {
      return false;
    }

    // check diagonal
    if (std::abs(row - i) == std::abs(column_for_row[i] - column))
    {
      return false;
    }
  }

  return true;
}

void print_column_for_row(const vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

bool solve_n_queens_v2(board_t &b, int row, vector<int> column_for_row)
{

  if (row == b.size())
  {
    return true;
  }

  for (int col = 0; col < b[row].size(); col++)
  {
    column_for_row[row] = col;
    if (is_safe_v2(column_for_row, row, col))
    {
      b[row][col] = 1;
      if (solve_n_queens_v2(b, row + 1, column_for_row))
      {
        return true;
      }

      b[row][col] = 0;
    }
  }

  return false;
}

/**
 * Similar to @solve_n_queens but using a 1D vector instead of 2D vector
 * to represent the board and compute the is_safe function. 
 */
board_t solve_n_queens_v2(int n)
{
  board_t board = board_t(n, vector<int>(n));
  vector<int> column_for_row(n);
  solve_n_queens_v2(board, 0, column_for_row);
  return board;
}

} // namespace recursion

#endif