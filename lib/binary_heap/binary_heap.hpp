#ifndef RL_ALGORITHMS_LIB_BINARY_HEAP_BINARY_HEAP_HPP
#define RL_ALGORITHMS_LIB_BINARY_HEAP_BINARY_HEAP_HPP

#include <vector>

using std::vector;
using std::cout;
using std::endl;

namespace binary_heap {

class Binary_heap {
private:
  vector<int> _v;
  int _size;

  int _max(int a, int b) {
    if (a > _size && b > _size) {
      return -1;
    }

    if (a > _size) {
      return b;
    }

    if (b > _size) {
      return a;
    }

    return _v[a] > _v[b] ? a : b;
  }

  void _swap(int lhs, int rhs) {
    int aux = _v[lhs];
    _v[lhs] = _v[rhs];
    _v[rhs] = aux;
  }

  void _swim(int node) {
    int parent = node / 2;
    if (parent == 0) {
      return;
    }
  
    if (_v[parent] < _v[node]) {
      _swap(parent, node);
      _swim(parent);
    }
  }

  void _sink(int node) {
    if (node >= _size) {
      return;
    }

    int lhs_child = 2 * node;
    int rhs_child = 2 * node + 1;

    if ((lhs_child > _size || _v[node] > _v[lhs_child]) && (rhs_child > _size || _v[node] > _v[rhs_child])) {
      return;
    }

    int child_to_swap = _max(lhs_child, rhs_child);
    if (child_to_swap == -1) {
      return;
    }

    _swap(child_to_swap, node);
    _sink(child_to_swap);
  }

public:
  Binary_heap(int cap) {
    _v = vector<int>(cap + 1);
    _size = 0;
  }

  void insert(int key) {
    if (_size + 1 >= _v.size()) {
      return;
    }

    _size++;
    _v[_size] = key;
    _swim(_size);
  }

  int max() {
    return _v[1];
  }
  
  void remove_max() {
    _swap(1, _size);
    _v[_size] = 0;
    _size--;
    _sink(1);
  }

  bool is_empty() {
    return size() == 0;
  }

  int size() {
    return _size;
  }

  int capacity() {
    return _v.size() - 1;
  }

  void print() {
    cout << "print:" << endl;
    for (int v : _v) {
      cout << v << " ";
    }

    cout << endl;
  }
};

};

#endif
