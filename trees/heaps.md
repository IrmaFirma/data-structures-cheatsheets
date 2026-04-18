Heap - Data Structure

A heap is a COMPLETE BINARY TREE that stores a collection of elements with their associated KEYS at its NODE and that satisfied the HEAP ORDER PROPERTY.
For every node(v) other than the root; key associated with (v) is greater or equal to the key of its parent. 
The minimum key is always at the top of the heap (root) => Min Heap

IMPLEMENTING A PRIORITY QUEUE USING A HEAP:
- need comparator
* INSERTING ELEMENTS:
- add element to the end
- perform UP HEAP BUBBLING => O(log N) or O(h)
- make sure the Heap Order Property is perserved
* REMOVE MIN:
- remove the root (because the minimum element is always stored at root)
- set the last node as the new root
- perform DONW HEAP BUBBLING => O(log N) or O(h)

HEAP SORT: O(n log n)
- each insert operation with up heap bubbling takes O(log n)
- each removeMin operation with down heap bubbling takes O(log n)
* faster than both Selection sort and Insertion sort

IMPLEMENTING HEAP SORT "IN PLACE":
- to save memory space we can implement the same process but using only the list L
- this technique is called IN PLACE because it does not require any additional memory space
- all the arrangements are done in the list ITSELF
* if L is implemented as an array, we can reduce its space requirement by using the portion of L itself to store the HEAP
- using a reverse comparator where the LARGEST KEY is at the TOP of the HEAP then proceed with PHASES

BOTTOM UP HEAP CONSTRUCTION: O(n) time complexity assuming comparing two keys takes O(1) time
1. Construct n+1/2 heaps containing a single element each
2. For each pair of heaps, add an element that would join the pair into a single heap -> then perform DOWN HEAP BUBBLING
3. Repeat process until ROOT i.e. final heap has been constructed

* fill the bottom level first
* fill the next level above it
* ... repeat the process up to the root
* only if all elements are given in advance

  # swaps/operations reflects the height of the heap
  # running bubble down on internal nodes starting from the last parent node up to root
  # last internal node: n/2 or n/2-1 depending on indexing
  # first leaf index at n/2+1 or n/2 depending on indexing

* Reverse comparator: largest key at the top of the heap
Phase 1: Scan array LEFT to RIGHT and insert elements into the heap
Phase 2: Remove the top of the heap and place in the array LEFT TO RIGHT
