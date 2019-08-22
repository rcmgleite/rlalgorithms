
#ifndef RL_ALGORITHMS_LIB_RECURSION_TRUCK_PATH_HPP
#define RL_ALGORITHMS_LIB_RECURSION_TRUCK_PATH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::queue;
using std::vector;
using maze_t = vector<vector<int>>;

namespace recursion
{
namespace truck_path
{

void has_path(maze_t &maze, int i, int j, maze_t &visited, bool &found_path)
{
  if (found_path)
  {
    return;
  }

  if (i > (int)maze.size() - 1 || i < 0 || j > (int)maze[i].size() - 1 || j < 0)
  {
    return;
  }

  if (maze[i][j] == 9)
  {
    found_path = true;
  }

  if (visited[i][j] == 1)
  {
    return;
  }

  if (maze[i][j] == 1)
  { // wall
    return;
  }

  visited[i][j] = 1;

  has_path(maze, i, j + 1, visited, found_path);
  has_path(maze, i + 1, j, visited, found_path);
  has_path(maze, i - 1, j, visited, found_path);
  has_path(maze, i, j - 1, visited, found_path);
}

/**
 * dfs like implementation for has path.
 */
bool has_path(maze_t &maze)
{
  maze_t visited = maze_t(maze.size(), vector<int>(maze[0].size(), 0));
  bool result = false;
  has_path(maze, 0, 0, visited, result);

  return result;
}

typedef struct Maze_node_t
{
  Maze_node_t(int i, int j, int dist) : i(i), j(j), dist(dist) {}
  int i;
  int j;
  int dist;
} Maze_node_t;

int shortest_path(maze_t &maze, int i, int j)
{
  maze_t visited = maze_t(maze.size(), vector<int>(maze[0].size(), 0));
  queue<Maze_node_t> q;
  q.push(Maze_node_t(i, j, 0));

  int shortest_path_size = -1;
  while (!q.empty())
  {
    auto current_position = q.front();
    q.pop();

    int i = current_position.i;
    int j = current_position.j;
    if (i > (int)maze.size() - 1 || i < 0 || j > (int)maze[i].size() - 1 || j < 0)
    {
      continue;
    }
    if (visited[i][j] == 1)
    {
      continue;
    }

    visited[i][j] = 1;

    if (maze[i][j] == 1)
    { // wall
      continue;
    }

    if (maze[i][j] == 9)
    { // found
      shortest_path_size = current_position.dist + 1;
      while (!q.empty())
      {
        q.pop();
      }
      continue;
    }

    q.push(Maze_node_t(i, j + 1, current_position.dist + 1));
    q.push(Maze_node_t(i + 1, j, current_position.dist + 1));
    q.push(Maze_node_t(i - 1, j, current_position.dist + 1));
    q.push(Maze_node_t(i, j - 1, current_position.dist + 1));
  }

  return shortest_path_size;
}

/**
 * bfs like implementation for shortest_path
 */
int shortest_path(maze_t &maze)
{
  return shortest_path(maze, 0, 0);
}

} // namespace truck_path
}; // namespace recursion

#endif
