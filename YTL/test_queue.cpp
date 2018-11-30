#include "UnitTest++.h"
#include "YTL/container/cQueue.h"
#include "YTL/container/cIterable.h"

using namespace yame::container;

namespace
{

TEST(EmptyQueue)
{
    cQueue<int> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(PushValueQueue)
{
    cQueue<int> foo;

    foo.push(10);

    CHECK_EQUAL(1, foo.getSize());
    CHECK_EQUAL(10, foo.front());

    foo.push(20);

    CHECK_EQUAL(2, foo.getSize());
    CHECK_EQUAL(20, foo.front());
}

TEST(PopValueQueue)
{
    cQueue<int> foo;

    foo.push(10);

    CHECK_EQUAL(1, foo.getSize());
    CHECK_EQUAL(10, foo.front());

    foo.pop();

    CHECK_EQUAL(0, foo.getSize());

    foo.push(20);

    CHECK_EQUAL(1, foo.getSize());
    CHECK_EQUAL(20, foo.front());
}

TEST(IterateQueue)
{
    cQueue<int> foo;

    foo.push(0);
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.push(4);

    CHECK_EQUAL(5, foo.getSize());

    cQueue<int>::const_iterator_type itQueue = foo.cbegin();
    size_t counter = 4;

    for(;itQueue!=foo.cend();itQueue++,counter--)
    {
        CHECK_EQUAL(counter, *itQueue);
    }
}

TEST(IterateFilteredQueue)
{
    cQueue<int> foo;

    foo.push(0);
    foo.push(1);
    foo.push(2);
    foo.push(3);
    foo.push(4);

    CHECK_EQUAL(5, foo.getSize());

    cQueue<int>::const_iterator_type itQueue = foo.cbegin([](int value){ return value < 3; });

    size_t counter = 2;

    for(;itQueue!=foo.cend();itQueue++,counter--)
    {
        CHECK_EQUAL(counter, *itQueue);
    }
}

TEST(IterableOverQueue)
{
    cQueue<int> foo;

    foo.push(97);
    foo.push(98);
    foo.push(99);
    foo.push(100);
    foo.push(101);

    CHECK_EQUAL(5, foo.getSize());

    cConstForwardInterIterable<1, int&,char> fooToCharIterable(foo, [](int value) { return char(value);});
    typename cConstForwardInterIterable<1, int&,char>::iterator_type itFooToChar = fooToCharIterable.begin();

    for(;itFooToChar!=fooToCharIterable.end();itFooToChar++)
    {
        char currChar = *itFooToChar;

        printf("getting char %c\n", *itFooToChar);
    }
}

}

