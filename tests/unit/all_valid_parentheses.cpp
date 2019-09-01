#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/all_valid_parentheses.hpp"

namespace unit_tests
{
using namespace std;
using namespace recursion;

TEST(RECURSION, ALL_VALID_PARENTHESES_1)
{
  auto result = recursion::all_valid_parentheses(2);

  EXPECT_EQ(result.size(), 2);
  EXPECT_TRUE(result.find("()()") != result.end());
  EXPECT_TRUE(result.find("(())") != result.end());
}

TEST(RECURSION, ALL_VALID_PARENTHESES_2)
{
  auto result = recursion::all_valid_parentheses(3);

  EXPECT_EQ(result.size(), 5);
  EXPECT_TRUE(result.find("((()))") != result.end());
  EXPECT_TRUE(result.find("(()())") != result.end());
  EXPECT_TRUE(result.find("(())()") != result.end());
  EXPECT_TRUE(result.find("()(())") != result.end());
  EXPECT_TRUE(result.find("()()()") != result.end());
}

} // namespace unit_tests