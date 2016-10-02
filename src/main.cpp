#include <Heap.h>

#include <iostream>

using namespace std;
using namespace hfun;

struct Node
{
    int  key;
    char val;

    bool operator >(Node& other)
    {
        return key > other.key;
    }

};

int main(int argc, char *argv[])
{
    Heap<Node *> heap;

    cout << "Done." << endl;
    return 0;
}    
