#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/sort/merge_sort/merge_sort.hpp"

namespace unit_tests {

using namespace std;

TEST(MERGE_SORT, SORT_INT_VECTOR) {
  auto v = vector<int>({2, 10, 5, -1, 22, 99, 8});

  sort::merge_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(MERGE_SORT, SORT_INT_VECTOR_WITH_DUPLICATE_VALUES) {
  auto v = vector<int>({2, 10, 5, -1, 22, 10, 99, 8, 10});

  sort::merge_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(MERGE_SORT, SORT_INT_VECTOR_ALREADY_SORTED) {
  auto v = vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  sort::merge_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(MERGE_SORT, SORT_INT_VECTOR_ALREADY_SORTED_IN_REVERSE_ORDER) {
  auto v = vector<int>({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});

  sort::merge_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

TEST(MERGE_SORT, SORT_STRING_VECTOR) {
  auto v = vector<string>({"a", "c", "z", "b", "d", "h", "f"});

  sort::merge_sort(v);
  EXPECT_EQ(sort::is_sorted(v), true);
}

};
