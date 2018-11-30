#include "UnitTest++.h"
#include "YTL/container/cMap.h"
#include "YTL/container/cAVLtree.h"
#include "YTL/container/cQueue.h"
#include "YTL/container/cArray.h"
#include "YTL/container/cIterable.h"
#include "YTL/container/cAlgorithm.h"

using namespace yame;
using namespace yame::container;

namespace
{

TEST(EmptyMap)
{
    cMap<int, int> foo;

    CHECK_EQUAL(true, foo.empty());

    foo[0] = 0;

    CHECK_EQUAL(false, foo.empty());
}

TEST(SizeMap)
{
    cMap<int, int> foo;

    CHECK_EQUAL(0, foo.getSize());

    foo[0] = 0;

    CHECK_EQUAL(1, foo.getSize());
}

TEST(ModifyMap)
{
    cMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;

    CHECK_EQUAL(1, foo[1]);

    foo[1] = 2;

    CHECK_EQUAL(2, foo[1]);
}

TEST(AccessMap)
{
    cMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;

    int a = foo[0];
    int b = foo[1];
    int c = foo[10];

    CHECK_EQUAL(0, a);
    CHECK_EQUAL(1, b);
    CHECK_EQUAL(20, c);
}

TEST(ForwardMapConstIteration)
{
    cMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;
    foo[20] = -20;

    cMap<int,int>::const_iterator_type it = foo.cbegin();

    cMap<int,int>::const_iterator_type maxNum = yame::max(foo,ytl::function<bool(const cPair<const int,int>&,const cPair<const int,int>&)>([](const cPair<const int,int>& i_lhs,const cPair<const int,int>& i_rhs){ return i_lhs.second > i_rhs.second; }));
    cMap<int,int>::const_iterator_type minNum = yame::min(foo,ytl::function<bool(const cPair<const int,int>&,const cPair<const int,int>&)>([](const cPair<const int,int>& i_lhs,const cPair<const int,int>& i_rhs){ return i_lhs.second < i_rhs.second; }));

    cConstBidirectionalIntraIterable<cPair<const int, int>&, int> valueMapIterable(foo, [](const cPair<const int,int>& i_pair) { return i_pair.second;});

    int sumNum = yame::apply(valueMapIterable,ytl::function<int(int,int)>([](int i_lhs,int i_rhs){ return i_lhs + i_rhs; }));

    CHECK_EQUAL(10, maxNum->first);
    CHECK_EQUAL(20, maxNum->second);
    CHECK_EQUAL(20, minNum->first);
    CHECK_EQUAL(-20, minNum->second);
    CHECK_EQUAL(1, sumNum);

    for(;it!=foo.cend();it++)
    {
        //notice in this case you are not able to acquire non const references
        const cPair<const int, int>& itPair = *it;

        switch(itPair.first)
        {
            case 0: CHECK_EQUAL(0, itPair.second); break;
            case 1: CHECK_EQUAL(1, itPair.second); break;
            case 10: CHECK_EQUAL(20, itPair.second); break;
            case 20: CHECK_EQUAL(-20, itPair.second); break;
            default: printf("ep! unexpected value: %d\n", itPair.first);
        }
    }
}

TEST(ReverseMapConstIteration)
{
    cMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;
    foo[20] = -20;

    cMap<int,int>::const_reverse_iterator_type it = foo.crbegin();

    for(;it!=foo.crend();it++)
    {
        //notice in this case you are not able to acquire non const references
        const cPair<const int, int>& itPair = *it;

        printf("reverse value : %d",itPair.second);

        switch(itPair.first)
        {
            case 0: CHECK_EQUAL(0, itPair.second); break;
            case 1: CHECK_EQUAL(1, itPair.second); break;
            case 10: CHECK_EQUAL(20, itPair.second); break;
            case 20: CHECK_EQUAL(-20, itPair.second); break;
            default: printf("ep! unexpected value: %d\n", itPair.first);
        }
    }
}

TEST(ForwardMapIteration)
{
    cMap<const int*, int> foo;

    foo[0] = (const int *)NULL;
    foo[1] = (const int *)NULL;
    foo[10] = (const int *)NULL;

    cMap<const int*,int>::iterator_type it = foo.begin();

    for(;it!=foo.end();it++)
    {
        cPair<const int, const int*>& itPair = *it;

        switch(itPair.first)
        {
            case 0: CHECK_EQUAL((const int *)NULL, itPair.second); break;
            case 1: CHECK_EQUAL((const int *)NULL, itPair.second); break;
            case 10: CHECK_EQUAL((const int *)NULL, itPair.second); break;
            default: printf("ep! unexpected value: %d\n", itPair.first);
        }
    }
}

TEST(ForwardMapIterationWithFilter)
{
    cAVLtree<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;

    cConstBidirectionalInterIterable<1, cPair<const int, int>&, int> convertedIterable(foo, [](const cPair<const int,int>& i_pair) { return i_pair.second;});
    typename cConstBidirectionalInterIterable<1, cPair<const int, int>&, int>::iterator_type it = convertedIterable.begin([](int i_value){ return i_value > 0;});

    for(;it!=convertedIterable.end();it++)
    {
        int itValue = *it;

        printf("checking value of: %d", itValue);
    }
}

TEST(ForwardMultiMapIteration)
{
    cAVLtree<int, int> foo1;

    foo1[0] = 10;
    foo1[1] = 11;
    foo1[2] = 12;

    cQueue<int> foo3;

    foo3.push(16);
    foo3.push(17);
    foo3.push(18);

    cConstBidirectionalIntraIterable<cPair<const int, int>&, int&> convertedIterable0(foo1, [](const cPair<const int,int>& i_pair) ->int& { return i_pair.second;});
    cConstForwardInterIterable<1, int&> convertedIterable1(foo3);
    cConstForwardInterIterable<2, int&> convertedIterable2(convertedIterable0, convertedIterable1);
    typename cConstForwardInterIterable<2, int&>::const_iterator_type it = convertedIterable2.cbegin();

    for(;it!=convertedIterable2.cend();it++)
    {
        int itValue = *it;

        printf("\nchecking multiple value of: %d", itValue);
    }
}

}
