#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Board
#include <boost/test/unit_test.hpp>
#include <Heap.h>

using namespace hfun;

struct Ele
{
    const int  key;
    const char val;

    Ele(int k, char v)
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
    Ele *e = new Ele(123, 'a');
    h.add(e);
    BOOST_CHECK_EQUAL(1, h.size());
    delete e;
}
