#ifndef RL_ALGORITHMS_GRAPH_GRAPH_HPP
#define RL_ALGORITHMS_GRAPH_GRAPH_HPP

#include <vector>
#include <list>;

namespace graph
{

using std::list;
using std::vector;

using adj_list_t = list<int>;

class UndirectedGraph
{
private:
  int n_vertices;
  vector<adj_list_t> adj_list;

public:
  UndirectedGraph(int n_vertices) : n_vertices(n_vertices), adj_list(vector<adj_list_t>(n_vertices))
  {
  }

  void add_edge(int v, int w)
  {
    adj_list[v].push_back(w);
    adj_list[w].push_back(v);
  }

  adj_list_t adj(int v)
  {
    return adj_list[v];
  }
};

} // namespace graph

#endif