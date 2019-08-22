#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/truck_path.hpp"

namespace unit_tests
{

using namespace std;
using namespace recursion;

TEST(RECURSION, TRUCK_PATH_HAS_PATH_1)
{
  maze_t maze({
      {0, 0, 0, 0, 9},
      {1, 0, 1, 1, 0},
      {1, 0, 0, 1, 0},
      {1, 1, 0, 0, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, true);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, 5);
}

TEST(RECURSION, TRUCK_PATH_HAS_PATH_2)
{
  maze_t maze({
      {0, 0, 1, 1, 9},
      {1, 0, 1, 1, 1},
      {1, 0, 0, 1, 0},
      {1, 1, 0, 0, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, false);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, -1);
}

TEST(RECURSION, TRUCK_PATH_HAS_PATH_3)
{
  maze_t maze({
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0},
      {1, 1, 9, 1, 0},
      {1, 1, 0, 0, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, true);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, 11);
}

TEST(RECURSION, TRUCK_PATH_HAS_PATH_4)
{
  maze_t maze({
      {0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0},
      {0, 0, 9, 1, 0},
      {1, 1, 0, 0, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, true);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, 5);
}

TEST(RECURSION, TRUCK_PATH_HAS_PATH_5)
{
  maze_t maze({
      {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1, 1, 1},
      {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 1, 0, 1, 0, 9, 0, 0},
      {1, 0, 0, 1, 0, 1, 0, 0, 1, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, true);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, 15);
}

TEST(RECURSION, TRUCK_PATH_HAS_PATH_6)
{
  maze_t maze({
      {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 1, 1, 1, 0},
      {1, 0, 0, 0, 0, 0, 1, 9, 1, 0},
      {1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
      {1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  });

  auto res = truck_path::has_path(maze);
  EXPECT_EQ(res, false);

  auto shortest_path_size = truck_path::shortest_path(maze);
  EXPECT_EQ(shortest_path_size, -1);
}

}; // namespace unit_tests
