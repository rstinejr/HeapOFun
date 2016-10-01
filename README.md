# Heap o' Fun

It's natural to think of pointers for implementing trees, but what if you need
to implement a complete tree, in which new items are always added to the
bottom-most node?  You could use a pointer and some def mechanisms.  Or, you 
could use a vector of nodes, with the parent-child relationship defined 
by the relation of indices of the items.

A heap is a complete binary tree with the further constraint that there is a
complete ordering relation R between the keys of all nodes, and for any parent
P and children C1 & C2, R(P, C1) and R(P, C2) are both true.

See the [Wikipedia article on the "heap" data structure](https://en.wikipedia.org/wiki/Heap_(data_structure)).

This project defines a Heap class that supports insert, pop, count, and print operations.
