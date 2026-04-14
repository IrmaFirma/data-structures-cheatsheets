Priority Queue - Data Structure

Definition:
Data Structure where each element is associated with a KEY representing its priority. 
A priority queue has no notion of position. (fundamentally different from position based DS)
* more than one element can have the SAME KEY (the key can be any type)
A priority queue needs a comparison rule that can compare any 2 keys to determine which one is "smaller".

Such comparison must never contradict itself, it has to define a TOTAL ORDER RELATION.
In order to never lead to a contradiction the comparison rule must satisfy:
1. Reflexive Property => k<=k
2. Antisymmetric Property => k1<=k2 and k2<=k1 then k1==k2
3. Transitive Property => k1<=k2 and k2<=k3 then k1<=k3

Comparison rule can be implemented as a function => COMPARATOR.
We can also overload the operator "<" instead of writing a custom comparator. 
We are also allowed to define multiple comparator functions.
We can disguise comparator functions as types by making each function appear as a class and overloading the () operator. 
Once comparator functions become classes, we can pass them to template functions as an argument to avoid repeated code. 

SUPPORTED FUNCTIONS:
size() => return the # elements in the p.q.
empty() => return true if p.q. is empty
insert(e) => insert element into p.q.
min() => return a reference to the element of p.q. with the SMALLEST ASSCOCIATED KEY VALUE (error if p.q. empty)
removeMin() => remove from p.q. element REFERENCED by min() (error if p.q. empty)

NOTE** In ADT we do not specify how insert(e) is implemented. Depending on implementation element could:
1. Always be inserted at the end of the p.q.
2. Inserted based on element's key such that after insertion elements in the p.q. are inserted according to their keys
* a priority queue supports elements of any type
* the key could be the element itself

TIME COMPLEXITY:
Sorted Doubly LL: elements inserted based on their key to ensure p.q. is always sorted
size(), empty(), min(), removeMin() => O(1)
insert(e) => O(n)
Unsorted Doubly LL: elements inserted at the end of the list 
size(), empty(), insert(e) => O(1)
min(), removeMin() => O(n)

SORTING WITH A PRIORITY QUEUE:
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

PRIORITY Q. STL:
* templated with 3 parameters: base type, container type(vector by default), comparator object(< by default)
* instead of insert(e) we have PUSH(E) that always inserts based on key
* instead of min() and removeMin() we have TOP() and POP() which return and remove the element with the LARGEST KEY
