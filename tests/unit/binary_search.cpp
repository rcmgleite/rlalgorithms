#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/binary_search/binary_search.hpp"

namespace unit_tests {

using namespace std;

TEST(BINARY_SEARCH, FINDING_VALUES_THAT_ARE_INSIDE_INT_VECTOR) {
  auto v = vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  for (auto i : v) {
    int index = binary_search::binary_search(v, i);
    EXPECT_EQ(index, i - 1);
  }
}

TEST(BINARY_SEARCH, FINDING_VALUES_THAT_ARE_NOT_INSIDE_INT_VECTOR) {
  auto v = vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 70, 100});

  int index = binary_search::binary_search(v, 0);
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, 101);
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, 60);
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, 40);
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, 71);
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, 99);
  EXPECT_EQ(index, -1);
}

TEST(BINARY_SEARCH, FINDING_VALUES_THAT_ARE_INSIDE_STRING_VECTOR) {
  auto v = vector<string>({"aaa", "bbb", "ccc", "ddd", "eee", "fff"});

  for (auto i = 0; i < v.size(); i++) {
    int index = binary_search::binary_search(v, v[i]);
    EXPECT_EQ(index, i);
  }
}

TEST(BINARY_SEARCH, FINDING_VALUES_THAT_ARE_NOT_INSIDE_STRING_VECTOR) {
  auto v = vector<string>({"aaa", "bbb", "ccc", "ddd", "eee", "fff"});

  int index = binary_search::binary_search(v, string("aaaa"));
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, string(""));
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, string("abc"));
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, string("ffff"));
  EXPECT_EQ(index, -1);

  index = binary_search::binary_search(v, string("z"));
  EXPECT_EQ(index, -1);
}

};
