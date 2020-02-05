#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/dp/lcs.hpp"

namespace unit_tests
{

using namespace std;

TEST(DP_LCS, LCS_LENGTH_1)
{
  string s1 = "AGGTAB";
  string s2 = "GXTXAYB";

  int result = dp::lcs_length(s1, s2);
  EXPECT_EQ(result, 4);
}

TEST(DP_LCS, LCS_LENGTH_2)
{
  string s1 = "ABCDGH";
  string s2 = "AEDFHR";

  int result = dp::lcs_length(s1, s2);
  EXPECT_EQ(result, 3);
}

TEST(DP_LCS, LCS_LENGTH_EMPTY_STRINGS)
{
  string s1 = "";
  string s2 = "";

  int result = dp::lcs_length(s1, s2);
  EXPECT_EQ(result, 0);
}





}; // namespace unit_tests
