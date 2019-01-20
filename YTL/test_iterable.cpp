#include "UnitTest++.h"
#include "YTL/container/cArray.h"
#include "YTL/container/cQueue.h"
#include "YTL/container/cMap.h"
#include "YTL/container/cString.h"
#include "YTL/container/cIterable.h"
#include "YTL/container/cPackIterable.h"

using namespace yame::container;

namespace
{

TEST(StringRawCharConstruction)
{
    string foo1 = "holaQueAse";
    string foo2 = "VieneOqUEaSE";
    string foo3 = foo1 + foo2;


    CHECK_EQUAL(foo1.getStr(), "holaQueAse");
    CHECK_EQUAL(foo1.getSize(), 10);
}

TEST(QueueBaseIteration)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    typename cQueue<int>::iterator_type itFoo = foo.begin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueBaseIterationWithFilter)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    typename cQueue<int>::iterator_type itFoo = foo.begin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueBaseConstIteration)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    typename cQueue<int>::const_iterator_type itFoo = foo.cbegin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(QueueBaseConstIterationWithFilter)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    typename cQueue<int>::const_iterator_type itFoo = foo.cbegin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(MapBaseIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::iterator_type itFoo = foo.begin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(MapBaseIterationWithFilter)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::iterator_type itFoo = foo.begin([](const cPair<const int,int>& i_val){ return i_val.first > 2; });

    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(MapBaseReverseIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::reverse_iterator_type itFoo = foo.rbegin();

    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.rend() == itFoo);
}

TEST(MapBaseReverseIterationWithFilter)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::reverse_iterator_type itFoo = foo.rbegin([](const cPair<const int,int>& i_val){ return i_val.first > 2; });

    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.rend() == itFoo);
}

TEST(MapBaseConstIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::const_iterator_type itFoo = foo.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(MapBaseConstIterationWithFilter)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::const_iterator_type itFoo = foo.cbegin([](const cPair<const int,int>& i_val){ return i_val.first > 2; });

    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(MapBaseConstReverseIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::const_reverse_iterator_type itFoo = foo.crbegin();

    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.crend() == itFoo);
}

TEST(MapBaseConstReverseIterationWithFilter)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    typename cMap<int,int>::const_reverse_iterator_type itFoo = foo.crbegin([](const cPair<const int,int>& i_val){ return i_val.first > 2; });

    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, foo.crend() == itFoo);
}

TEST(ArrayBaseIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::iterator_type itFoo = foo.begin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(ArrayBaseIterationWithFilter)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::iterator_type itFoo = foo.begin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(ArrayBaseReverseIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::reverse_iterator_type itFoo = foo.rbegin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.rend() == itFoo);
}

TEST(ArrayBaseReverseIterationWithFilter)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::reverse_iterator_type itFoo = foo.rbegin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(true, foo.rend() == itFoo);
}

TEST(ArrayBaseConstIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::const_iterator_type itFoo = foo.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(ArrayBaseConstIterationWithFilter)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::const_iterator_type itFoo = foo.cbegin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(ArrayBaseConstReverseIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::const_reverse_iterator_type itFoo = foo.crbegin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.crend() == itFoo);
}

TEST(ArrayBaseConstReverseIterationWithFilter)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::const_reverse_iterator_type itFoo = foo.crbegin([](const int& i_val){ return i_val > 20; });

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(true, foo.crend() == itFoo);
}

TEST(QueueConstIterableBaseIteration)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cConstForwardIterable<int&>& queueIterable = foo;
    typename cConstForwardIterable<int&>::iterator_type itFoo = queueIterable.begin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(MapConstIterableBaseIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cConstBidirectionalIterable<cPair<const int,int>&>& iterableFoo = foo;
    typename cConstBidirectionalIterable<cPair<const int,int>&>::iterator_type itFoo = iterableFoo.begin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.end() == itFoo);
}

TEST(ArrayConstIterableBaseIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cConstRandomAccessIterable<int&>& arrayIterable = foo;
    typename cConstRandomAccessIterable<int&>::iterator_type itFoo = arrayIterable.begin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueIterableBaseIteration)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cForwardIterable<int&>& queueIterable = foo;
    typename cForwardIterable<int&>::iterator_type itFoo = queueIterable.begin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(MapIterableBaseIteration)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cBidirectionalIterable<cPair<const int,int>&>& iterableFoo = foo;
    typename cBidirectionalIterable<cPair<const int,int>&>::iterator_type itFoo = iterableFoo.begin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.end() == itFoo);
}

TEST(ArrayIterableBaseIteration)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cRandomAccessIterable<int&>& arrayIterable = foo;
    typename cRandomAccessIterable<int&>::iterator_type itFoo = arrayIterable.begin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueIterableBaseAdd)
{
    cQueue<int> foo;

    cForwardIterable<int&>& queueIterable = foo;

    queueIterable.add(10);
    queueIterable.add(21);
    queueIterable.add(1);
    queueIterable.add(32);
    queueIterable.add(43);

    typename cForwardIterable<int&>::iterator_type itFoo = queueIterable.begin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueIterableBaseErase)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cForwardIterable<int&>& queueIterable = foo;

    queueIterable.erase(queueIterable.begin());
    queueIterable.erase(queueIterable.begin());
    queueIterable.erase(queueIterable.begin());
    queueIterable.erase(queueIterable.begin());
    queueIterable.erase(queueIterable.begin());

    typename cForwardIterable<int&>::iterator_type itFoo = queueIterable.begin();

    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(MapIterableBaseAdd)
{
    cMap<int,int> foo;

    cBidirectionalIterable<cPair<const int,int>&>& iterableFoo = foo;

    iterableFoo.add(cPair<const int,int>(0,10));
    iterableFoo.add(cPair<const int,int>(1,11));
    iterableFoo.add(cPair<const int,int>(2,12));
    iterableFoo.add(cPair<const int,int>(3,13));
    iterableFoo.add(cPair<const int,int>(4,14));

    typename cBidirectionalIterable<cPair<const int,int>&>::iterator_type itFoo = iterableFoo.begin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.end() == itFoo);
}

TEST(MapIterableBaseErase)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cBidirectionalIterable<cPair<const int,int>&>& iterableFoo = foo;

    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());

    typename cBidirectionalIterable<cPair<const int,int>&>::iterator_type itFoo = iterableFoo.begin();

    CHECK_EQUAL(true, iterableFoo.end() == itFoo);
}

TEST(ArrayIterableBaseAdd)
{
    cArray<int> foo;

    cRandomAccessIterable<int&>& arrayIterable = foo;

    arrayIterable.add(10);
    arrayIterable.add(21);
    arrayIterable.add(1);
    arrayIterable.add(32);
    arrayIterable.add(43);

    typename cRandomAccessIterable<int&>::iterator_type itFoo = arrayIterable.begin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(ArrayIterableBaseErase)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cRandomAccessIterable<int&>& arrayIterable = foo;

    arrayIterable.erase(arrayIterable.begin());
    arrayIterable.erase(arrayIterable.begin());
    arrayIterable.erase(arrayIterable.begin());
    arrayIterable.erase(arrayIterable.begin());
    arrayIterable.erase(arrayIterable.begin());

    typename cRandomAccessIterable<int&>::iterator_type itFoo = arrayIterable.begin();

    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(ArrayIterableBaseIterationStress)
{
    cArray<int> foo;
    const size_t maxElems = 1000000;

    foo.reserve(maxElems);
    for(size_t i=0;i<maxElems;++i)
    {
        foo.push_back(i);
    }

    cRandomAccessIterable<int&>& arrayIterable = foo;
    typename cRandomAccessIterable<int&>::iterator_type itFoo = arrayIterable.begin();

    for(size_t i=0;i<maxElems;++i)
    {
        CHECK_EQUAL(i, *itFoo++);
    }

    CHECK_EQUAL(true, foo.end() == itFoo);
}

TEST(QueueConstForwardIntraIterable)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cConstForwardIntraIterable<int&> iterableFoo(foo);
    typename cConstForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(QueueConstForwardIntraIterableTransformed)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cConstForwardIntraIterable<int&, char> iterableFoo(foo, [](const int& i_val) { return char(i_val); });

    typename cConstForwardIntraIterable<int&,char>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(char(43), *itFoo++);
    CHECK_EQUAL(char(32), *itFoo++);
    CHECK_EQUAL(char(1), *itFoo++);
    CHECK_EQUAL(char(21), *itFoo++);
    CHECK_EQUAL(char(10), *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(QueueForwardIntraIterableAdd)
{
    cQueue<int> foo;

    cForwardIntraIterable<int&> iterableFoo(foo);

    iterableFoo.add(10);
    iterableFoo.add(21);
    iterableFoo.add(1);
    iterableFoo.add(32);
    iterableFoo.add(43);

    typename cForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(QueueForwardIntraIterableErase)
{
    cQueue<int> foo;

    foo.push(10);
    foo.push(21);
    foo.push(1);
    foo.push(32);
    foo.push(43);

    cForwardIntraIterable<int&> iterableFoo(foo);

    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());

    typename cForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(true, foo.cend() == itFoo);
}

TEST(MapConstForwardIntraIterable)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cConstForwardIntraIterable<cPair<const int,int>&> iterableFoo(foo);
    typename cConstForwardIntraIterable<cPair<const int,int>&>::const_iterator_type itFoo = iterableFoo.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(MapForwardIntraIterableAdd)
{
    cMap<int,int> foo;

    cForwardIntraIterable<cPair<const int,int>&> iterableFoo(foo);

    iterableFoo.add(cPair<const int,int>(0,10));
    iterableFoo.add(cPair<const int,int>(1,11));
    iterableFoo.add(cPair<const int,int>(2,12));
    iterableFoo.add(cPair<const int,int>(3,13));
    iterableFoo.add(cPair<const int,int>(4,14));

    typename cForwardIntraIterable<cPair<const int,int>&>::const_iterator_type itFoo = iterableFoo.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(MapForwardIntraIterableErase)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cForwardIntraIterable<cPair<const int,int>&> iterableFoo(foo);

    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());

    typename cForwardIntraIterable<cPair<const int,int>&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(MapConstForwardIntraIterableTransformed)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cConstForwardIntraIterable<cPair<const int,int>&, int> iterableFoo(foo, [](const cPair<const int,int>& i_val){ return i_val.first; });

    typename cConstForwardIntraIterable<cPair<const int,int>&, int>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(0, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(2, *itFoo++);
    CHECK_EQUAL(3, *itFoo++);
    CHECK_EQUAL(4, *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayConstForwardIntraIterable)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cConstForwardIntraIterable<int&> iterableFoo(foo);
    typename cConstForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayForwardIntraIterableAdd)
{
    cArray<int> foo;

    cForwardIntraIterable<int&> iterableFoo(foo);

    iterableFoo.add(10);
    iterableFoo.add(21);
    iterableFoo.add(1);
    iterableFoo.add(32);
    iterableFoo.add(43);

    typename cForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayForwardIntraIterableErase)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cForwardIntraIterable<int&> iterableFoo(foo);

    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());
    iterableFoo.erase(iterableFoo.begin());

    typename cForwardIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayConstForwardIntraIterableTransformed)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cConstForwardIntraIterable<int&, char> iterableFoo(foo, [](const int& i_val){ return char(i_val); });
    typename cConstForwardIntraIterable<int&,char>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(char(10), *itFoo++);
    CHECK_EQUAL(char(21), *itFoo++);
    CHECK_EQUAL(char(1), *itFoo++);
    CHECK_EQUAL(char(32), *itFoo++);
    CHECK_EQUAL(char(43), *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

//you cannot create bidirectional iterables from forward iterables, so queues not allowed
TEST(MapConstBidirectionalIntraIterable)
{
    cMap<int,int> foo;

    foo[0] = 10;
    foo[1] = 11;
    foo[2] = 12;
    foo[3] = 13;
    foo[4] = 14;

    cConstBidirectionalIntraIterable<cPair<const int,int>&> iterableFoo(foo);
    typename cConstBidirectionalIntraIterable<cPair<const int,int>&>::const_iterator_type itFoo = iterableFoo.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(3,13);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(4,14);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}


TEST(ArrayConstBidirectionalIntraIterable)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cConstBidirectionalIntraIterable<int&> iterableFoo(foo);
    typename cConstBidirectionalIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayConstRandomAccessIntraIterable)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    cConstRandomAccessIntraIterable<int&> iterableFoo(foo);
    typename cConstRandomAccessIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(21, *itFoo++);
    CHECK_EQUAL(1, *itFoo++);
    CHECK_EQUAL(32, *itFoo++);
    CHECK_EQUAL(43, *itFoo++);
    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ArrayConstRandomAccessIntraIterableStress)
{
    cArray<int> foo;
    size_t maxElems = 1000000;

    foo.reserve(maxElems);
    for(size_t i=0;i<maxElems;++i)
    {
        foo.push_back(i);
    }

    cConstRandomAccessIntraIterable<int&> iterableFoo(foo);
    typename cConstRandomAccessIntraIterable<int&>::const_iterator_type itFoo = iterableFoo.cbegin();

    for(size_t counter=0;itFoo!=iterableFoo.cend();++itFoo,++counter)
    {
        CHECK_EQUAL(counter, *itFoo);
    }

    CHECK_EQUAL(true, iterableFoo.cend() == itFoo);
}

TEST(ConstForwardInterIterable)
{
    cMap<int, int> foo1;

    foo1[0] = 10;
    foo1[1] = 11;
    foo1[2] = 12;

    cConstForwardInterIterable<1, cPair<const int, int>&> convertedIterable(foo1);

    typename cConstForwardInterIterable<1, cPair<const int, int>&>::const_iterator_type itFoo = convertedIterable.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, convertedIterable.cend() == itFoo);
}

TEST(ConstForwardInterIterableTransformed)
{
    cMap<int, int> foo1;

    foo1[0] = 10;
    foo1[1] = 11;
    foo1[2] = 12;

    cQueue<int> foo3;

    foo3.push(16);
    foo3.push(17);
    foo3.push(18);

    cConstBidirectionalInterIterable<1, cPair<const int, int>&, int&> convertedIterable0(foo1, [](const cPair<const int,int>& i_pair) ->int& { return i_pair.second;});
    cConstForwardInterIterable<1, int&> convertedIterable1(foo3);

    cConstForwardInterIterable<2, int&> convertedIterable2(convertedIterable0, convertedIterable1);
    //cForwardIntraIterable<int&> prova(convertedIterable0);

    //prova.add(10);

    typename cConstForwardInterIterable<2, int&>::const_iterator_type itFoo = typename cConstForwardInterIterable<2, int&>::const_iterator_type(convertedIterable2.cbegin());

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(11, *itFoo++);
    CHECK_EQUAL(12, *itFoo++);
    CHECK_EQUAL(18, *itFoo++);
    CHECK_EQUAL(17, *itFoo++);
    CHECK_EQUAL(16, *itFoo++);
    CHECK_EQUAL(true, convertedIterable2.cend() == itFoo);
}

TEST(ConstBidirectionalInterIterable)
{
    cMap<int, int> foo1;

    foo1[0] = 10;
    foo1[1] = 11;
    foo1[2] = 12;

    cConstBidirectionalInterIterable<1, cPair<const int, int>&> convertedIterable(foo1);

    const cConstBidirectionalIterable<cPair<const int, int>&>& convertedIterableInterface = convertedIterable;

    typename cConstBidirectionalIterable<cPair<const int, int>&>::const_iterator_type itFoo = convertedIterableInterface.cbegin();

    {
        cPair<const int,int> expValue(0,10);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(1,11);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    {
        cPair<const int,int> expValue(2,12);
        CHECK_EQUAL(true, expValue == *itFoo++);
    }
    CHECK_EQUAL(true, convertedIterableInterface.cend() == itFoo);
}

TEST(ConstBidirectionalInterIterableTransformed)
{
    cMap<int, int> foo1;

    foo1[0] = 10;
    foo1[1] = 11;
    foo1[2] = 12;

    cConstBidirectionalInterIterable<1, cPair<const int, int>&, int&> convertedIterable(foo1, [](const cPair<const int,int>& i_pair) ->int& { return i_pair.second;});

    const cConstBidirectionalIterable<int&>& convertedIterableInterface = convertedIterable;

    typename cConstBidirectionalIterable<int&>::const_iterator_type itFoo = convertedIterableInterface.cbegin();

    CHECK_EQUAL(10, *itFoo++);
    CHECK_EQUAL(11, *itFoo++);
    CHECK_EQUAL(12, *itFoo++);
    CHECK_EQUAL(true, convertedIterableInterface.cend() == itFoo);
}

TEST(ConstRandomAccessInterIterable)
{
    cArray<int> foo1;

    foo1.push_back(13);
    foo1.push_back(14);
    foo1.push_back(15);

    cArray<int> foo2;

    foo2.push_back(16);
    foo2.push_back(17);
    foo2.push_back(18);

    cConstRandomAccessPackIterable<int&,int&> arraysPackIterable(foo1,foo2);

    typename cConstRandomAccessPackIterable<int&,int&>::iterator_type itPack = arraysPackIterable.begin();
    for(size_t index = 0;itPack!=arraysPackIterable.end();++itPack)
    {
        parameter_pack<int&,int&> currValue = *itPack;
        const int& firstValue = currValue.getValue<0>();
        const int& secondValue = currValue.getValue<1>();
        ++index;
    }

    cConstRandomAccessInterIterable<2, int&> convertedIterable(foo1,foo2);

    const cConstRandomAccessIterable<int&>& convertedIterableInterface = convertedIterable;

    typename cConstRandomAccessIterable<int&>::const_iterator_type itFoo = convertedIterableInterface.cbegin();

    CHECK_EQUAL(13, *itFoo++);
    CHECK_EQUAL(14, *itFoo++);
    CHECK_EQUAL(15, *itFoo++);
    CHECK_EQUAL(16, *itFoo++);
    CHECK_EQUAL(17, *itFoo++);
    CHECK_EQUAL(18, *itFoo++);
    CHECK_EQUAL(true, convertedIterableInterface.cend() == itFoo);
}

template<int currDepth>
struct wrapper;

template<>
struct wrapper<0>
{
    static cConstRandomAccessInterIterable<2, int&> createInterIterable(size_t currNum, size_t arraySize)
    {
        static cArray<int> foo;
        foo.reserve(arraySize);

        for(size_t i=0;i<arraySize;i++)
        {
            foo.push_back(currNum++);
        }

        static cArray<int> nestedFoo;
        nestedFoo.reserve(arraySize);

        for(size_t i=0;i<arraySize;i++)
        {
            nestedFoo.push_back(currNum++);
        }

        return cConstRandomAccessInterIterable<2, int&>(foo, nestedFoo);
    }
};


template<int currDepth>
struct wrapper
{
    static cConstRandomAccessInterIterable<2, int&> createInterIterable(size_t currNum, size_t arraySize)
    {
        //declare everything static so its lifetime is guaranteed (its under template functions, so there wont be any clash)
        static cArray<int> foo;
        foo.reserve(arraySize);

        for(size_t i=0;i<arraySize;i++)
        {
            foo.push_back(currNum++);
        }

        static cConstRandomAccessInterIterable<2, int&> nestedIterable = wrapper<currDepth-1>::createInterIterable(currNum, arraySize);

        return cConstRandomAccessInterIterable<2, int&>(foo, nestedIterable);
    }
};

TEST(ConstForwardInterIterableStress)
{
    cArray<int> foo1;
    const size_t arraySize = 1000;
    const static size_t maxDepth = 500;

    foo1.push_back(13);
    foo1.push_back(14);
    foo1.push_back(15);

    cConstRandomAccessInterIterable<2, int&> convertedIterable = wrapper<maxDepth>::createInterIterable(0, arraySize);

    const cConstRandomAccessIterable<int&>& convertedIterableInterface = convertedIterable;

    typename cConstRandomAccessIterable<int&>::const_iterator_type itFoo = convertedIterableInterface.cbegin();

    for(size_t currNum=0;itFoo!=convertedIterableInterface.cend();++itFoo,++currNum)
    {
        CHECK_EQUAL(currNum, *itFoo);
    }

    CHECK_EQUAL(true, convertedIterableInterface.cend() == itFoo);
}

}

