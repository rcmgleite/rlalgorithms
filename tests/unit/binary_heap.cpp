#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/binary_heap/binary_heap.hpp"

namespace unit_tests {

using namespace std;
using namespace binary_heap;

TEST(BINARY_HEAP, INSERT_AND_GET) {
  int heap_cap = 10;
  auto bh = Binary_heap(heap_cap);
  EXPECT_EQ(bh.size(), 0);
  EXPECT_EQ(bh.capacity(), heap_cap);
  
  auto values = vector<int>({3, 10, -1, 4, 2, 9, 100, 50, 20, -4});
  int maxValue = -99;
  int counter = 0;
  for (auto value : values) {
    bh.insert(value);
    maxValue = maxValue > value ? maxValue : value;
    counter++;
    EXPECT_EQ(bh.max(), maxValue);
    EXPECT_EQ(bh.size(), counter);
  }
}

TEST(BINARY_HEAP, INSERT_AND_REMOVE) {
  int heap_cap = 10;
  auto bh = Binary_heap(heap_cap);
  
  auto values = vector<int>({3, 10, -1, 4, 2, 9, 100, 50, 20, -4});
  for (auto value : values) {
    bh.insert(value);
  }

  std::sort(values.begin(), values.end(), [](int i, int j) {
    return i > j;
  }); 

  int initial_values_size = values.size();
  for (int i = 0; i < initial_values_size; i++) {
    EXPECT_EQ(bh.max(), values[0]);
    bh.remove_max();
    values.erase(values.begin());
  }
}

};

