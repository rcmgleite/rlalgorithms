#ifndef RL_ALGORITHMS_DB_LARGEST_SQUARE_OF_1S_MATRIX_HPP
#define RL_ALGORITHMS_DB_LARGEST_SQUARE_OF_1S_MATRIX_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;

namespace dp {

int largest_square_of_1s_matrix(vector<vector<int>> m, int i, int j, int& result, vector<vector<int>>& memo) {
  if (i >= m.size() || j >= m[0].size()) {
    return 0;
  }
  
  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  memo[i][j] = m[i][j] + min({
    largest_square_of_1s_matrix(m, i + 1, j, result, memo),
    largest_square_of_1s_matrix(m, i, j + 1, result, memo),
    largest_square_of_1s_matrix(m, i + 1, j + 1, result, memo)
  });

  result = max(result, memo[i][j]);

  return memo[i][j];
}

int largest_square_of_1s_matrix(vector<vector<int>> m) {
  vector<vector<int>> memo(m.size(), vector<int>(m[0].size(), -1));
  
  int result = -1;

  largest_square_of_1s_matrix(m, 0, 0, result, memo);
  return result;
}

};

#endif 
