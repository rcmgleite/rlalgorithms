#ifndef RL_ALGORITHMS_MATRIX_SORTED_MATRIX_SEARCH_HPP
#define RL_ALGORITHMS_MATRIX_SORTED_MATRIX_SEARCH_HPP

#include <iostream>
#include <vector>

namespace matrix
{

using std::cout;
using std::endl;
using std::vector;

/*
  value = 35.
  {10, 20, 30, 40},
  {15, 25, 35, 45},
  {27, 29, 37, 48},
  {32, 33, 39, 50}

  The idea is to start at the TOP RIGHT corner of the matrix.
  For every element we are analysing, there are 3 possibilities:

  1. value is < M[i][j] -> this means that we can eliminate the entire column we are scanning right now.
  2. value is > M[i][j] -> this means that we can eliminate the entire row we are scanning right now.
  3. value == m[i][j] -> found :)
*/
struct Coordinate
{
  Coordinate(int i, int j) : i(i), j(j) {}
  int i;
  int j;
};

Coordinate *sorted_search(vector<vector<int>> &m, int value)
{
  if (value > m[m.size() - 1][m[0].size() - 1])
  {
    return nullptr;
  }

  if (value < m[0][0])
  {
    return nullptr;
  }

  int i = 0;
  int j = m[0].size() - 1;

  while (i < (int)m[0].size() && j >= 0)
  {
    if (m[i][j] == value)
    {
      return new Coordinate(i, j);
    }

    if (m[i][j] > value)
    {
      j--;
    }
    else
    {
      i++;
    }
  }

  return nullptr;
}

} // namespace matrix

#endif
