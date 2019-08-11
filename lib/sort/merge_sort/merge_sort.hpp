#ifndef RL_ALGORITHMS_LIB_SORT_MERGE_SORT_HPP
#define RL_ALGORITHMS_LIB_SORT_MERGE_SORT_HPP

#include "../utils.hpp"

namespace sort
{

/*
 * Merge sort implementation,
 * Time complexity: O(nlog(n))
 * Space complexity: (O(n))
 */
template <typename T>
void merge_sort(std::vector<T> &v);

/*
 * Merge sort recursive implementation
 */
template <typename T>
void merge_sort(std::vector<T> &v, int lo, int hi, std::vector<T> &aux);

/*
 * Merge merges 2 sorted arrays.
 */
template <typename T>
void merge(std::vector<T> &v, int lo, int mid, int hi, std::vector<T> &aux);

/*
 * Implementations.
 */
template <typename T>
void merge_sort(std::vector<T> &v)
{
  std::vector<T> aux(v.size());
  merge_sort(v, 0, v.size() - 1, aux);
}

template <typename T>
void merge_sort(std::vector<T> &v, int lo, int hi, std::vector<T> &aux)
{
  if (lo >= hi)
  {
    return;
  }

  int mid = lo + (hi - lo) / 2;
  merge_sort(v, lo, mid, aux);     // Sort from 'lo' to 'mid'.
  merge_sort(v, mid + 1, hi, aux); // Sort from 'mid+1' to 'hi'.
  merge(v, lo, mid, hi, aux);
}

template <typename T>
void merge(std::vector<T> &v, int lo, int mid, int hi, std::vector<T> &aux)
{
  int i = lo;
  int j = mid + 1;

  for (int k = lo; k <= hi; k++)
  {
    aux[k] = v[k];
  }

  for (int k = lo; k <= hi; k++)
  {
    if (i > mid)
    {
      v[k] = aux[j++];
    }
    else if (j > hi)
    {
      v[k] = aux[i++];
    }
    else if (aux[i] <= aux[j])
    {
      v[k] = aux[i++];
    }
    else
    {
      v[k] = aux[j++];
    }
  }
}

} // namespace sort

#endif
