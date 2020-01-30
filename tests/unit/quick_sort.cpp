
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/sort/quick_sort/quick_sort.hpp"

namespace unit_tests
{

using namespace std;

TEST(QUICK_SORT, SORT_INT_VECTOR)
{
  auto v = vector<int>({2, 10, 5, -1, 22, 99, 8});

  sort::quick_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(QUICK_SORT, SORT_INT_VECTOR_WITH_DUPLICATE_VALUES)
{
  auto v = vector<int>({2, 10, 5, -1, 22, 10, 99, 8, 10});

  sort::quick_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(QUICK_SORT, SORT_INT_VECTOR_ALREADY_SORTED)
{
  auto v = vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  sort::quick_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(QUICK_SORT, SORT_INT_VECTOR_ALREADY_SORTED_IN_REVERSE_ORDER)
{
  auto v = vector<int>({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});

  sort::quick_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(QUICK_SORT, SORT_STRING_VECTOR)
{
  auto v = vector<string>({"a", "c", "z", "b", "d", "h", "f"});

  sort::quick_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(QUICK_SORT, NTH_SMALLEST)
{
  auto v1 = vector<int>({2, 10, 5, -1, 22, 99, 8, -4, 11, 14, 77, 3, 9});
  auto v2 = vector<int>({2, 10, 5, -1, 22, 99, 8, -4, 11, 14, 77, 3, 9});

  sort::quick_sort(v1);
  EXPECT_EQ(sort::is_sorted(v1), true);

  int smallest = sort::nthsmallest(v2, 0);
  EXPECT_EQ(smallest, v1[0]);

  int fifthSmallest = sort::nthsmallest(v2, 5);
  EXPECT_EQ(fifthSmallest, v1[5]);

  int biggest = sort::nthsmallest(v2, v2.size() - 1);
  EXPECT_EQ(biggest, v1[v1.size() - 1]);
}

}; // namespace unit_tests
