#ifndef ARRAY_FREE_SCHEDULE_HPP
#define ARRAY_FREE_SCHEDULE_HPP

#include <iostream>
#include <vector>

/**
 * [[9, 10], [9, 12], [15, 18]] 
 */
namespace rlarray
{
using std::cout;
using std::endl;
using std::vector;

void print_slots(vector<int> &v)
{
  for (auto val : v)
  {
    cout << val << endl;
  }
}

vector<int> available_slots(vector<vector<int>> &schedules)
{
  vector<int> all_slots = {
      1, //{9, 10},
      1, //{10, 11},
      1, //{11, 12},
      1, //{12, 13},
      1, //{13, 14},
      1, //{14, 15},
      1, //{15, 16},
      1, //{16, 17},
      1, //{17, 18},
  };

  for (auto schedule : schedules)
  {
    int begin = schedule[0];
    int end = schedule[1];

    for (int hour = begin; hour < end; hour++)
    {
      all_slots[hour - 9] = 0;
    }
  }

  return all_slots;
}

} // namespace rlarray

#endif