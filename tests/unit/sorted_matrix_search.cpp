#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/matrix/sorted_matrix_search.hpp"

namespace unit_tests
{

using namespace std;

TEST(MATRIX, SORTED_MATRIX_SEARCH)
{
  vector<vector<int>> m(
      {{10, 20, 30, 40},
       {15, 25, 35, 45},
       {27, 29, 37, 48},
       {32, 33, 39, 50}});

  auto res = matrix::sorted_search(m, 10);
  EXPECT_EQ(res->i, 0);
  EXPECT_EQ(res->j, 0);
  delete res;

  res = matrix::sorted_search(m, 20);
  EXPECT_EQ(res->i, 0);
  EXPECT_EQ(res->j, 1);
  delete res;

  res = matrix::sorted_search(m, 30);
  EXPECT_EQ(res->i, 0);
  EXPECT_EQ(res->j, 2);
  delete res;

  res = matrix::sorted_search(m, 40);
  EXPECT_EQ(res->i, 0);
  EXPECT_EQ(res->j, 3);
  delete res;

  res = matrix::sorted_search(m, 15);
  EXPECT_EQ(res->i, 1);
  EXPECT_EQ(res->j, 0);
  delete res;

  res = matrix::sorted_search(m, 25);
  EXPECT_EQ(res->i, 1);
  EXPECT_EQ(res->j, 1);
  delete res;

  res = matrix::sorted_search(m, 35);
  EXPECT_EQ(res->i, 1);
  EXPECT_EQ(res->j, 2);
  delete res;

  res = matrix::sorted_search(m, 45);
  EXPECT_EQ(res->i, 1);
  EXPECT_EQ(res->j, 3);
  delete res;

  res = matrix::sorted_search(m, 33);
  EXPECT_EQ(res->i, 3);
  EXPECT_EQ(res->j, 1);
  delete res;

  res = matrix::sorted_search(m, 50);
  EXPECT_EQ(res->i, 3);
  EXPECT_EQ(res->j, 3);
  delete res;
}

}; // namespace unit_tests
