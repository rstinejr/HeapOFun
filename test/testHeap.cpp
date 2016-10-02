#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Board
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

BOOST_AUTO_TEST_CASE(append)
{
    Heap<Ele> h;
    BOOST_CHECK_EQUAL(0, h.size());
    Ele *e = new Ele(123, "a");
    h.add(e);
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

    h.add(one);
    BOOST_CHECK_EQUAL(1, h.top()->key);
    
    h.add(two);
    BOOST_CHECK_EQUAL(2, h.top()->key);

    h.add(three);
    BOOST_CHECK_EQUAL(3, h.top()->key);

    h.add(zero);
    BOOST_CHECK_EQUAL(3, h.top()->key);
    
    delete one;
    delete two;
    delete three;
    delete zero;
}

