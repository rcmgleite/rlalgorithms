#ifndef RL_ALGORITHMS_LIB_RECURSION_PAINT_FILL
#define RL_ALGORITHMS_LIB_RECURSION_PAINT_FILL

#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace recursion
{
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using screen_t = vector<vector<int>>;

enum Color
{
  R = 0,
  G = 1,
  B = 2,
};

map<int, string> color_map = map<int, string>({
    {Color::R, "R"},
    {Color::G, "G"},
    {Color::B, "B"},
});

bool screen_compare(const screen_t &lhs, const screen_t &rhs)
{
  if (lhs.size() != rhs.size())
  {
    return false;
  }

  for (unsigned int i = 0; i < lhs.size(); i++)
  {
    for (unsigned int j = 0; j < lhs[i].size(); j++)
    {
      if (lhs[i][j] != rhs[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

void print_screen(const screen_t &s)
{
  cout << "PRINT_SCREEN_BEGIN" << endl;
  for (unsigned int i = 0; i < s.size(); i++)
  {
    for (unsigned int j = 0; j < s[i].size(); j++)
    {
      cout << color_map[s[i][j]] << " ";
    }

    cout << endl;
  }
  cout << "PRINT_SCREEN_END" << endl;
}

void paint_fill(screen_t &s, int x, int y, int new_color, int original_color)
{
  if (x < 0 || x >= (int)s.size() || y < 0 || y >= (int)s[x].size())
  {
    return;
  }

  if (s[x][y] == original_color)
  {
    s[x][y] = new_color;

    paint_fill(s, x + 1, y, new_color, original_color);
    paint_fill(s, x - 1, y, new_color, original_color);
    paint_fill(s, x, y + 1, new_color, original_color);
    paint_fill(s, x, y - 1, new_color, original_color);
  }
}

void paint_fill(screen_t &s, int x, int y, int new_color)
{
  paint_fill(s, x, y, new_color, s[x][y]);
}

} // namespace recursion

#endif
