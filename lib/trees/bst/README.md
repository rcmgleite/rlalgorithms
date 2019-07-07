# BST

## Definition

*Binary tree in symmetric order*

### Symmetric order

Each node has a key, and very node's key is:

1. Larger than all keys in the left subtree
2. Smaller than all keys in the right subtree

This is completely different than the ordering in a binary heap where each node's key is larger than both its children.

### Time complexity

In the current implementation, there is no effort to keep the tree balanced.
This mean that if we insert all items in order, the tree will degenerate into a linked list.
In that case, both *put* and *get* will be O(n).

### Ordered operations

1. Floor - Largest key <= @input
2. Ceiling - Smallest key >= @input

Both of them hava a similar structure. Let's analyse Ceiling.

We have 3 cases to handle:

1. input == node->key
  In this situation, ceiling = node->key by definition.

2. input > node->key
  In this case, input is still greater than node->key. as we need to arrive at a point where input is less then node->key,
  simply go right.

3. input < node->key
  When we finally arrive at this state, one of 2 things can happen: Either the ceiling is on the left subtree or it's the node->key itself.

By handling this 3 cases, we can implement the ceiling operation.
The Floor operation is very similar and we will skip its explanation.
