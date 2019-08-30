#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/linked_list/linked_list.hpp"

namespace unit_tests
{

using namespace std;

TEST(LINKED_LIST, GENERAL_OPS)
{
  linked_list::Linked_list list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  EXPECT_EQ(list.get_nth(0), 1);
  EXPECT_EQ(list.get_nth(1), 2);
  EXPECT_EQ(list.get_nth(2), 3);
  EXPECT_EQ(list.get_nth(3), 4);
  EXPECT_EQ(list.get_nth(4), -1);

  list.remove(2);
  EXPECT_EQ(list.get_nth(0), 1);
  EXPECT_EQ(list.get_nth(1), 3);
  EXPECT_EQ(list.get_nth(2), 4);
  EXPECT_EQ(list.get_nth(3), -1);
}

TEST(LINKED_LIST, REMOVE_DUPS_1)
{
  linked_list::Linked_list list;
  list.push_back(1);
  list.push_back(1);
  list.push_back(1);
  list.push_back(1);

  list.remove_duplicates_map();

  EXPECT_EQ(list.get_nth(0), 1);
  EXPECT_EQ(list.get_nth(1), -1);
}

TEST(LINKED_LIST, REMOVE_DUPS_2)
{
  linked_list::Linked_list list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(2);
  list.push_back(1);

  list.remove_duplicates_map();

  EXPECT_EQ(list.get_nth(0), 1);
  EXPECT_EQ(list.get_nth(1), 2);
  EXPECT_EQ(list.get_nth(2), -1);
}

TEST(LINKED_LIST, REMOVE_DUPS_3)
{
  linked_list::Linked_list list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  list.push_back(3);
  list.push_back(2);
  list.push_back(1);
  list.push_back(6);

  list.remove_duplicates_map();

  EXPECT_EQ(list.get_nth(0), 1);
  EXPECT_EQ(list.get_nth(1), 2);
  EXPECT_EQ(list.get_nth(2), 3);
  EXPECT_EQ(list.get_nth(3), 4);
  EXPECT_EQ(list.get_nth(4), 5);
  EXPECT_EQ(list.get_nth(5), 6);
}

}; // namespace unit_tests
