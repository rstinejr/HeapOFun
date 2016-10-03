#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE HeapOFun

#include <boost/test/unit_test.hpp>

#include <Heap.h>

using namespace hfun;

struct Ele
{
    const int  key;
    char const * val;

    Ele(int k, char const * v)
      : key(k)
      , val(v)
    {
    }

    bool operator >(Ele& other)
    {
        return key > other.key;
    }

};

BOOST_AUTO_TEST_CASE(smoke)
{
    {
        Heap<Ele> h;
    }

    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(insert)
{
    Heap<Ele> h;
    BOOST_CHECK_EQUAL(0, h.size());
    Ele *e = new Ele(123, "a");
    h.insert(e);
    BOOST_CHECK_EQUAL(1, h.size());
    delete e;
}

BOOST_AUTO_TEST_CASE(top)
{
    Heap<Ele> h;

    Ele *one   = new Ele(1, "one");
    Ele *two   = new Ele(2, "two");
    Ele *three = new Ele(3, "three");
    Ele *zero  = new Ele(0, "zero");

    h.insert(one);
    BOOST_CHECK_EQUAL(1, h.top()->key);
    
    h.insert(two);
    BOOST_CHECK_EQUAL(2, h.top()->key);

    h.insert(three);
    BOOST_CHECK_EQUAL(3, h.top()->key);

    h.insert(zero);
    BOOST_CHECK_EQUAL(3, h.top()->key);
    
    delete one;
    delete two;
    delete three;
    delete zero;
}

BOOST_AUTO_TEST_CASE(pop)
{
    Heap<Ele> h;

    Ele *eles[] = 
        { new Ele(1, "one"),  new Ele(2, "two"),  new Ele(4, "four"), 
         new Ele(3, "three"), new Ele(0, "zero"), new Ele(12, "twelve")};

    for (uint32_t ii = 0; ii < sizeof(eles)/sizeof(eles[0]); ii++)
    {
        h.insert(eles[ii]);
    }

    Ele *e;
    
    e  = h.pop();
    BOOST_CHECK_EQUAL(12, e->key);
    delete e;

    e = h.pop();
    BOOST_CHECK_EQUAL(4, e->key);
    delete e;

    e = h.pop();
    BOOST_CHECK_EQUAL(3, e->key);
    delete e;

    e = h.pop();
    BOOST_CHECK_EQUAL(2, e->key);
    delete e;

    e = h.pop();
    BOOST_CHECK_EQUAL(1, e->key);
    delete e;

    e = h. pop();
    BOOST_CHECK_EQUAL(0, e->key);
    delete e;
}

