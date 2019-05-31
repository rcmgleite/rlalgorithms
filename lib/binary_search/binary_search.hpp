#ifndef RL_ALGORITHMS_LIB_BINARY_SEARCH_BINARY_SEARCH_HPP
#define RL_ALGORITHMS_LIB_BINARY_SEARCH_BINARY_SEARCH_HPP

namespace binary_search {

/*
 * Binary search Template function.
 * Complexity: O(log(n))
 */
template<typename T>
int binary_search(const std::vector<T>& v, const T& value) {
  int lo = 0;
  int hi = v.size() - 1;

  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (value == v[mid]) {
      return mid;
    } else if (value < v[mid]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

};

#endif
