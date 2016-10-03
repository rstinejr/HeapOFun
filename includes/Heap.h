#ifndef HEAP_O_FUN
#define HEAP_O_FUN

#include <stdint.h>

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
            uint32_t leftChild = 2 * (inx + 1) - 1;
            if (leftChild >= ln)
            {
                break;  // inx is a leaf node.
            } 

            if ( ! (*heap_[inx]  >  *heap_[leftChild]) )
            {
                T *hld           = heap_[inx];
                heap_[inx]       = heap_[leftChild];
                heap_[leftChild] = hld;
                inx              = leftChild;
                continue;
             }

             uint32_t rightChild = leftChild + 1;
             if (rightChild >= ln)
             {
                 break; // inx does not have a right child. 
             }
             
             if ( *heap_[inx] > *heap_[rightChild] )
             {
                 break;  // Node is greater than its children, heap is good.
             }

             T *hld            = heap_[inx];
             heap_[inx]        = heap_[rightChild];
             heap_[rightChild] = hld;
             inx               = rightChild;
             continue;
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

private:
    std::vector<T*> heap_;
};

}

#endif
