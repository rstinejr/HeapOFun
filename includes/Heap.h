#ifndef HEAP_O_FUN
#define HEAP_O_FUN

#include <vector>

namespace hfun
{

template <class T> class Heap
{
public:
    Heap()
    {
    }
    
private:
    std::vector<T*> heap_;
};

}

#endif
