#ifndef HEAP_O_FUN
#define HEAP_O_FUN

#include <stdint.h>

#include <iostream>
#include <vector>

namespace hfun
{

template <class T> class Heap
{
public:
    Heap()
    {
    }

    uint32_t size()
    {
        return heap_.size();
    }
    
    T * top()
    {
        return (heap_.size() > 0) ? heap_[0] : (T *) 0;
    }

    /**
    * pop() pull out top item, resort the heap, return (former) top item.
    *
    * 1. Hold the top (greatest) item.
    * 2. Move the last item to the top, 
    * 3. Swap item with its children until heap condition is satisfied:
    *    parent node's key is greater than key of either of its children. 
    * 4. Return held top item.
    */
    T * pop()
    {
        uint32_t ln = heap_.size();
        if (ln == 0)
        {
            return (T *) 0;
        }

        T * top = heap_[0];
        
        heap_[0] = heap_[ln - 1];
        heap_.pop_back();
        ln--;

        uint32_t inx = 0;
        for ( ; ; )
        {
            int leftChild = 2 * (inx + 1) - 1;
            if ((unsigned) leftChild >= ln)
            {
                break;  // inx is a leaf node.
            } 

            int rightChild = ((unsigned) leftChild < ln) ? leftChild + 1 : -1;

            if (*heap_[inx] > *heap_[leftChild] && (rightChild == -1 || *heap_[inx] > *heap_[rightChild]))
            {
                break;  // properly sorted.
            }

            int swapInx;
            if (rightChild == -1)
            {
                swapInx = leftChild;
            }
            else
            {
                swapInx = (*heap_[leftChild] > *heap_[rightChild]) ? leftChild : rightChild;
            }

            T *hld         = heap_[inx];
            heap_[inx]     = heap_[swapInx];
            heap_[swapInx] = hld;
            inx            = swapInx;
        }                 

        return top;
    }

    void insert(T * e)
    {
	    uint32_t inx = heap_.size();
        
        heap_.push_back(e);
        while (inx > 0)
        {
            if ( ! (*heap_[inx] > *heap_[inx/2]) )
            {
                break;
            }

            T *tmp = heap_[inx/2];
            heap_[inx/2] = heap_[inx];
            heap_[inx] = tmp;
            inx /= 2;
        }

        return;
    }

    void print()
    {
        uint32_t ln = heap_.size();
        for (uint32_t ii = 0; ii < ln; ii++)
        {
            std::cout << heap_[ii]->key << " ";
        }
        
        std::cout << std::endl;

        return;
    }

private:
    std::vector<T*>  heap_;
};

}

#endif
