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

This project defines a Heap template that supports the following actions: 

* insert - insert an element into the heap.
* top - examine the element at the top of the heap.
* pop - remove the element from the top of the heap.
* size - return the number of elements in the heap
* print - display heap contents to stdout.

## Heap in a Vector

Instead of pointers, heap elements are stored in a vector whose elements can be accessed by index.
The root element goes in position 0.

For an element at position *i*, its left child has index ``2(i + 1) - 1``, and its right child has index
``2(i + 1)``.
 
## Heap Elements

The heap template takes an argument that is either a struct or class. This element must has a definition for the ">" operator that defines a total ordering for the set of help elements.

## Build and test info

This project was developed on 64-bit Linux Mint 17.2 Rafaela, using g++ version 4.9.3.
It uses the Boost Test Framework for unit tests.

The project has also been compiled and run on CentOS 6.1, g++ version 4.4.5, and
Mac OSX.

To build the project, clone it to your system, cd to the HeapOFun directory and run

```
make clean test run
``` 

If you do not have the Boost Test Framework installed, enter

```
make clean run
```

The ```main.cpp``` uses POSIX assesrtions to mimic several of the Boost unit
tests.

