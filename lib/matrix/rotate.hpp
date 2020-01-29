#ifndef MATRIX_ROTATE_HPP
#define MATRIX_ROTATE_HPP

#include <vector>
#include <iostream>

namespace matrix
{
using std::vector;
using matrix_t = vector<vector<int>>;

using std::cout;
using std::endl;

void print_matrix_4_way(matrix_t &m)
{
  cout << "Print matrix begin" << endl;
  for (unsigned int i = 0; i < m.size(); i++)
  {
    for (unsigned int j = 0; j < m[0].size(); j++)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Print matrix end" << endl;
}

bool equals_4_way(matrix_t &lhs, matrix_t &rhs)
{
  if (lhs.size() != rhs.size())
  {
    return false;
  }

  if (lhs[0].size() != rhs[0].size())
  {
    return false;
  }

  for (unsigned int i = 0; i < lhs.size(); i++)
  {
    for (unsigned int j = 0; j < rhs[0].size(); j++)
    {
      if (lhs[i][j] != rhs[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

void rotate_4_way_swap(matrix_t &m)
{
  int n = m.size();
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i; j < n - 1 - i; j++)
    {
      int aux = m[i][j];
      m[i][j] = m[n - 1 - j][i];
      m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
      m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
      m[j][n - 1 - i] = aux;
    }
  }
}

void rotate_change_base(matrix_t &m)
{
  // TODO
}

} // namespace matrix

#endif
