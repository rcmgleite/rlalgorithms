#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/graph/directed_graph.hpp"

namespace unit_tests
{

using namespace std;

TEST(DIRECTED_GRAPH, HAS_CYCLE__NO_CYCLE_1)
{
  graph::Directed_graph g(6);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 5);
  g.add_edge(3, 4);

  EXPECT_EQ(g.has_cycle_dfs_rec(), false);
}

TEST(DIRECTED_GRAPH, HAS_CYCLE__NO_CYCLE_2)
{
  graph::Directed_graph g(6);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(2, 5);
  g.add_edge(1, 3);
  g.add_edge(1, 4);

  EXPECT_EQ(g.has_cycle_dfs_rec(), false);
}

TEST(DIRECTED_GRAPH, HAS_CYCLE__WITH_CYCLE_1)
{
  graph::Directed_graph g(6);

  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(0, 3);
  g.add_edge(3, 5);
  g.add_edge(5, 4);
  g.add_edge(4, 3);

  EXPECT_EQ(g.has_cycle_dfs_rec(), true);
}

TEST(DIRECTED_GRAPH, HAS_CYCLE__WITH_CYCLE_2)
{
  graph::Directed_graph g(6);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(2, 5);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  g.add_edge(5, 0);

  EXPECT_EQ(g.has_cycle_dfs_rec(), true);
}

}; // namespace unit_tests
