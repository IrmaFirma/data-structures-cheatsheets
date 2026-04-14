SORTING WITH A PRIORITY QUEUES:
Given an unsorted list L and a priority queue Q we can perform the sorting in two phases:
Phase 1: Put the elements of L into Q using insert(e)
Phase 2: Extract the elements of the Q using (n) combinations of min() and removeMin()

Depending on implementation of insert(e), min() and removeMin() we could be talking about Selection or Insertion Sort.
* is insert(e) is implemented to insert always at the end of the PQ => Selection Sort
* if insert(e) inserts based on keys and sorts => Insertion Sort

COMPLEXITIY ANALYSIS SORTING:
Selection Sort: O(n^2)
Phase 1: O(n)
Phase 2: O(n^2) 
Insertion Sort: O(n^2)
Phase 1: O(n^2)
Phase 2: O(n)
