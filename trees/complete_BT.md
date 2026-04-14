Complete Binary Trees - Data Structure

A Binary Tree is COMPLETE if ALL levels are completely filled except the LAST one which is filled from the left. 
Levels from 0 to h-1 are completely filled (have a maximum # nodes possible). Level h is being filled from the left to right. 

* A complete binary tree with (N) nodes has height = log N.

A complete binary tree supports all functions of a binary tree in addition to: 
* ADD(E) => add and return a new external node (v) with element (e) 
* REMOVE() => remove the last node of the tree and return its element
* by using only these operations the binary tree is guaranteed to be complete

More on ADD(E): 
- creating a new last node
- at the first available opening in the tree (going top to bottom, left to right)
- checks current BOTTOM LEVEL
- if there is space to the RIGHT of the current last node add new node there
- if not (LEVEL IS FULL) start new LEVEL at the far LEFT

VECTOR BASED IMPLEMENTATION: level numbering technique
- filling the vector from left to right
- if we use an EXTENDABLE ARRAY the AMORTIZED time complexity of add(e) and remove() is O(1)

* REMEMBER *
- f(root) = 1
- f(left) = 2i
- f(right) = 2i + 1
- f(current) = i
