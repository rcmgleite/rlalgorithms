#ifndef RL_ALGORITHMS_GRAPH_GRAPH_HPP
#define RL_ALGORITHMS_GRAPH_GRAPH_HPP

#include <vector>
#include <list>
#include <stack>
#include <stdexcept>
#include <iostream>

namespace graph
{

using std::list;
using std::vector;
using std::stack;

using adj_list_t = list<int>;


class Directed_graph
{
private:
  int m_n_vertices;
  vector<adj_list_t> m_adj_list;

public:
  Directed_graph(int n_vertices) : m_n_vertices(n_vertices), m_adj_list(vector<adj_list_t>(n_vertices))
  {
  }

  void add_edge(int v, int w)
  {
    m_adj_list[v].push_back(w);
  }

  adj_list_t& adj(int v)
  {
    if (v >= (int)m_adj_list.size())
    {
      throw std::out_of_range("vertex out of bounds");
    }

    return m_adj_list[v];
  }

  int n_vertices()
  {
    return m_n_vertices;
  }

  bool has_cycle_dfs_rec(int v, vector<bool>& visited, vector<bool>& rec_stack)
  {
    visited[v] = true;
    rec_stack[v] = true;

    auto adj = m_adj_list[v];
    for (auto itr = adj.begin(); itr != adj.end(); ++itr)
    {
      if ((!visited[*itr] && has_cycle_dfs_rec(*itr, visited, rec_stack)) || rec_stack[*itr] )
      {
        return true;
      }
    }

    rec_stack[v] = false;
    return false;
  }

  // recursive DFS based cycle detection.
  bool has_cycle_dfs_rec()
  {
    for (int i = 0; i < m_n_vertices; i++)
    {
      vector<bool> visited(m_n_vertices, false);
      vector<bool> rec_stack(m_n_vertices, false);
      if(has_cycle_dfs_rec(i, visited, rec_stack))
      {
        return true;
      }
    }

    return false;
  }
};

} // namespace graph

#endif