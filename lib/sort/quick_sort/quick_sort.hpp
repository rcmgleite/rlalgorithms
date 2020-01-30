#ifndef RL_ALGORITHMS_LIB_SORT_QUICK_SORT_HPP
#define RL_ALGORITHMS_LIB_SORT_QUICK_SORT_HPP

#include <algorithm>
#include <vector>
#include "../utils.hpp"

namespace sort
{

using std::vector;
using std::swap;

template<typename T>
int partition(vector<T>& vec, int lo, int hi);

template<typename T>
void quick_sort(vector<T>& vec, int lo, int hi);

/**
 * Quick sort implementation
 */
template<typename T>
void quick_sort(vector<T>& vec)
{
  quick_sort(vec, 0, vec.size() - 1);
}

template<typename T>
T nthsmallest(vector<T>& vec, int n)
{
  if (n >= (int)vec.size())
  {
    throw std::out_of_range("n bigger than vec size");
  }

  int lo = 0;
  int hi = vec.size() - 1;

  int p = -1;

  while (p != n) {
    p = partition(vec, lo, hi);

    if (p == n)
    {
      break;
    }

    if (n > p)
    {
      lo = p + 1;
    }

    if (n < p)
    {
      hi = p - 1;
    }
  }

  return vec[p];
}

/**
 * The partition method rearenges the array to make
 * the following three conditions hold:
 *
 * 1. The entry vec[j] is in its final place for some j.
 * 2. No entry in vec[lo] through vec[j - 1] is greater than vec[j].
 * 3. No entry in vec[j + 1] though vec[hi] is less than vec[j].
 */
template<typename T>
int partition(vector<T>& vec, int lo, int hi)
{
  int i = lo + 1;
  int j = hi;
  T& partition_entry = vec[lo];

  while (true)
  {
    // find element to the left of the partition_entry
    // that is bigger than the partition_entry
    while(vec[i] < partition_entry)
    {
      i++;
      if (i >= hi)
      {
        break;
      }
    }

    // find element to the right of the partition_entry
    // that is less than the partition_entry
    while(vec[j] > partition_entry)
    {
      j--;
      if (j <= lo) {
        break;
      }
    }

    // If crossed, stop
    if (i >= j) {
      break;
    }

    swap(vec[i], vec[j]);
    i++;
    j--;
  }

  // This final swap puts the partition_entry into its correct place
  swap(vec[lo], vec[j]);
  return j;
}

template<typename T>
void quick_sort(vector<T>& vec, int lo, int hi)
{
  if (hi <= lo)
  {
    return;
  }

  int p = partition(vec, lo, hi);
  quick_sort(vec, lo, p - 1);
  quick_sort(vec, p + 1, hi);
}

}

#endif
