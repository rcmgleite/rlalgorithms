#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/string_permutations.hpp"

namespace unit_tests
{
using namespace std;
using namespace recursion;

TEST(RECURSION, STRING_PERMUTATIONS_1)
{
  auto result = recursion::string_permutations("abc");

  EXPECT_EQ(result[0], "cba");
  EXPECT_EQ(result[1], "bca");
  EXPECT_EQ(result[2], "bac");
  EXPECT_EQ(result[3], "cab");
  EXPECT_EQ(result[4], "acb");
  EXPECT_EQ(result[5], "abc");
}

TEST(RECURSION, STRING_PERMUTATIONS_2)
{
  auto result = recursion::string_permutations("abcd");

  EXPECT_EQ(result[0], "dcba");
  EXPECT_EQ(result[1], "cdba");
  EXPECT_EQ(result[2], "cbda");
  EXPECT_EQ(result[3], "cbad");
  EXPECT_EQ(result[4], "dbca");
  EXPECT_EQ(result[5], "bdca");
  EXPECT_EQ(result[6], "bcda");
  EXPECT_EQ(result[7], "bcad");
  EXPECT_EQ(result[8], "dbac");
  EXPECT_EQ(result[9], "bdac");
  EXPECT_EQ(result[10], "badc");
  EXPECT_EQ(result[11], "bacd");
  EXPECT_EQ(result[12], "dcab");
  EXPECT_EQ(result[13], "cdab");
  EXPECT_EQ(result[14], "cadb");
  EXPECT_EQ(result[15], "cabd");
  EXPECT_EQ(result[16], "dacb");
  EXPECT_EQ(result[17], "adcb");
  EXPECT_EQ(result[18], "acdb");
  EXPECT_EQ(result[19], "acbd");
  EXPECT_EQ(result[20], "dabc");
  EXPECT_EQ(result[21], "adbc");
  EXPECT_EQ(result[22], "abdc");
  EXPECT_EQ(result[23], "abcd");
}

} // namespace unit_tests