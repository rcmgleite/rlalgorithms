#ifndef RL_ALGORITHMS_MATRIX_ZERO_ROW_COLUMN_HPP
#define RL_ALGORITHMS_MATRIX_ZERO_ROW_COLUMN_HPP

#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::vector;

namespace matrix
{
using matrix_t = vector<vector<int>>;

void print_matrix(matrix_t &m)
{
  cout << "Print_matrix begin" << endl;
  for (size_t i = 0; i < m.size(); i++)
  {
    for (size_t j = 0; j < m[0].size(); j++)
    {
      cout << m[i][j] << " ";
    }

    cout << endl;
  }
  cout << "Print_matrix end" << endl;
}

void zero_row_column(matrix_t &m)
{
  map<int, bool> rows;
  map<int, bool> columns;
  for (size_t i = 0; i < m.size(); i++)
  {
    for (size_t j = 0; j < m.size(); j++)
    {
      if (m[i][j] == 0)
      {
        rows[i] = true;
        columns[j] = true;
      }
    }
  }

  for (size_t i = 0; i < m.size(); i++)
  {
    for (size_t j = 0; j < m[0].size(); j++)
    {
      if (rows[i] || columns[j])
      {
        m[i][j] = 0;
      }
    }
  }
}

} // namespace matrix

#endif
