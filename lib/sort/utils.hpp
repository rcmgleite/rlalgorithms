#ifndef RL_ALGORITHMS_LIB_SORT_UTILS_HPP
#define RL_ALGORITHMS_LIB_SORT_UTILS_HPP

#include <iostream>

namespace sort
{

using std::cout;
using std::endl;

/*
 * Returns true if the vector is sorted.
 */
template <typename T>
bool is_sorted(const std::vector<T> &v)
{
  if (v.size() < 2)
  {
    return true;
  }

  for (unsigned int i = 1; i < v.size(); i++)
  {
    if (v[i] < v[i - 1])
    {
      return false;
    }
  }

  return true;
}

template <typename T>
void print_vector(const std::vector<T>& v)
{
  for (auto& item : v)
  {
    cout << item << " ";
  }

  cout << endl;
}

}; // namespace sort

#endif
