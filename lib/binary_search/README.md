## Basic idea
Search for a value inside a sorted array by recursively "cutting" the search area in half.

## Tree representation

The array A = [1, 3, 4, 6, 7, 8, 10, 13, 14] can be represented like this:

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/500px-Binary_search_tree.svg.png)

To find the value 7, we need to:

1. Compare 7 with the root node (8). As it's lower than 8, go left.
2. Compare 7 with 3. As it's higher than 3, go right.
3. Comprare 7 with 6. As it's highres than, 6, go right.
4. Finally, found 7.

By inspecting this tree, it's easy to see that the number of steps to find a value using binary search is proportional to the
height of the tree.

### Now, how do we compute the hight of a binary tree like this?

Let's start by the number of nodes in a [complete binary tree](https://web.cecs.pdx.edu/~sheard/course/Cs163/Doc/FullvsComplete.html)


![alt text](https://latex.codecogs.com/svg.latex?n&space;=&space;2^0&space;&plus;&space;2^1&space;&plus;&space;...&space;2^h)
<br>
![alt text](https://latex.codecogs.com/svg.latex?n&space;=&space;\sum_{k=0}^{h}{x^{k-1}}&space;$)
<br>

This is a geometric progression with ration = 2.
The Sum of the first n terms of a geometric progression is:
<br>
![alt text](https://latex.codecogs.com/svg.latex?Sn&space;=&space;a_1&space;*&space;(q^n&space;-&space;1)&space;/&space;(q&space;-&space;1))
<br>

where 
- a1 - is the first term of the progrssion
- q - ration - in our case, 2.
- n - nuber of terms - in out case, h.

Therefore, 
<br>
![alt text](https://latex.codecogs.com/svg.latex?n&space;=&space;2^h&space;-&space;1)
<br>

By applying log2 to both sides of the equation we endup with:
<br>
![alt text](https://latex.codecogs.com/svg.latex?2^h&space;=&space;n&space;&plus;&space;1)
<br>
![alt text](https://latex.codecogs.com/svg.latex?log_2(2^h)&space;=&space;log_2(n&plus;1))
<br>
![alt text](https://latex.codecogs.com/svg.latex?h&space;=&space;log_2(n&plus;1))
<br>

Finally, the height of the binary search tree is proportional to log(n) and this height dictates the time complexity of the binary search algorithm.
