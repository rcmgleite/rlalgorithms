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
