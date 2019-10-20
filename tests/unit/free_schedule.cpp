#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/array/free_schedule.hpp"

namespace unit_tests
{
using namespace std;
using namespace rlarray;

TEST(ARRAY, FREE_SCHEDULE)
{
  vector<vector<int>> schedules = {
      {9, 10},
      {12, 14},
      {12, 15},
      {9, 11}};

  auto resp = rlarray::available_slots(schedules);
  ASSERT_EQ(resp[0], 0);
  ASSERT_EQ(resp[1], 0);
  ASSERT_EQ(resp[2], 1);
  ASSERT_EQ(resp[3], 0);
  ASSERT_EQ(resp[4], 0);
  ASSERT_EQ(resp[5], 0);
  ASSERT_EQ(resp[6], 1);
  ASSERT_EQ(resp[7], 1);
  ASSERT_EQ(resp[8], 1);
}
} // namespace unit_tests