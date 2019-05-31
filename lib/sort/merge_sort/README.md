## Basic idea
The basic idea behind merge sort is to divide the array in two, sort each half and merge them back as a final step.
The [recursive implementation](https://github.com/rcmgleite/rlalgorithms/blob/master/lib/sort/merge_sort/merge_sort.hpp#L38) is pretty easy to read.

## The merge function
The [current implementation](https://github.com/rcmgleite/rlalgorithms/blob/master/lib/sort/merge_sort/merge_sort.hpp#L50) of the merge function has
- O(n) time complexity
- O(n) space complexity

Similar to [binary search](https://github.com/rcmgleite/rlalgorithms/blob/master/lib/binary_search/README.md) the number of calls to the merge function is proportional to the
height of the equivalent binary search tree.
Therefore, the time complexity of merge sort is O(n*log(n)).
