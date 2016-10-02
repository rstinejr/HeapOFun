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
