#ifndef RL_ALGORITHMS_LIB_RECURSION_ALL_SUBSETS_OF_SET_HPP
#define RL_ALGORITHMS_LIB_RECURSION_ALL_SUBSETS_OF_SET_HPP

#include <iostream>
#include <vector>

namespace recursion
{

using std::cout;
using std::endl;
using std::vector;

using all_subsets_t = vector<vector<int>>;

void print(vector<int> v)
{
  for (auto value : v)
  {
    cout << value << " ";
  }

  cout << endl;
}

void print(const all_subsets_t &a)
{
  for (auto &v : a)
  {
    print(v);
  }
}

void all_subsets_of_a_set(const vector<int> &set, int current_elem, all_subsets_t &result)
{
  if (current_elem >= (int)set.size())
  {
    return;
  }

  all_subsets_t new_subsets;
  for (auto &subset : result)
  {
    vector<int> new_subset = subset;
    new_subset.push_back(set[current_elem]);
    new_subsets.push_back(new_subset);
  }

  for (auto &new_subset : new_subsets)
  {
    result.push_back(new_subset);
  }

  all_subsets_of_a_set(set, current_elem + 1, result);
}

/*
 * Example: [1, 2, 3]
 * 
 * Result:
 * 1. [1], [2], [3]
 * 2. [1, 2], [1, 3]
 * 3. [2, 3]
 * 4. [1, 2, 3]
 */
all_subsets_t all_subsets_of_a_set(const vector<int> &set)
{
  all_subsets_t result;
  result.push_back(vector<int>{});

  all_subsets_of_a_set(set, 0, result);

  return result;
}

}; // namespace recursion

#endif
