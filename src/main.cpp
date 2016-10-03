#include <Heap.h>

#include <assert.h>

#include <iostream>

using namespace std;
using namespace hfun;

struct Node
{
    const int  key;
    char const *val;

    Node(int k, char const *v)
      : key(k)
      , val(v)
    {
    }

    bool operator >(Node& other)
    {
        return key > other.key;
    }

};

void testPop()
{
        Heap<Node> h;

        Node *eles[] =
            { new Node(1, "one"),  new Node(2, "two"),  new Node(4, "four"),
              new Node(3, "three"), new Node(0, "zero"), new Node(12, "twelve")};

        for (uint32_t ii = 0; ii < sizeof(eles)/sizeof(eles[0]); ii++)
        {
            h.insert(eles[ii]);
        }

        cout << "Key values after loading heap:" << endl;
        h.print();

        Node *e;

        e  = h.pop();
        assert(12 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();

        e = h.pop();
        assert(4 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();

        e = h.pop();
        assert(3 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();

        e = h.pop();
        assert(2 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();

        e = h.pop();
        assert(1 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();

        e = h. pop();
        assert(0 == e->key);
        cout << "Key values after popping " << e->key << ":" << endl;
        delete e;
        h.print();
}

int main(int argc, char *argv[])
{
    Heap<Node> heap;

    testPop();

    cout << "Done." << endl;

    return 0;
}    
