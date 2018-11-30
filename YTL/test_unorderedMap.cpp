#include "UnitTest++.h"
#include "YTL/container/cUnorderedMap.h"
#include "YTL/container/cString.h"

using namespace yame;
using namespace yame::container;

namespace
{

TEST(EmptyUnorderedMap)
{
    cUnorderedMap<int, int> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(UnorderedMapKeyString)
{
    cUnorderedMap<int, string> foo;

    foo["hola"] = 10;
    foo["adeu"] = 11;
    foo["aabbccdd"] = 12;

    CHECK_EQUAL(3, foo.getSize());

    foo["hola"] = 113;

//    CHECK_EQUAL(10, foo["hola"]);
//    CHECK_EQUAL(11, foo["adeu"]);
//    CHECK_EQUAL(12, foo["aabbccdd"]);
}

TEST(UnorderedMapKeyPointer)
{
    cUnorderedMap<char, const int*> foo;

    int a = 'a';
    int b = 'b';
    int c = 'c';

    foo[&a] = a;
    foo[&b] = b;
    foo[&c] = c;

    CHECK_EQUAL(3, foo.getSize());

    CHECK_EQUAL(a, foo[&a]);
    CHECK_EQUAL(b, foo[&b]);
    CHECK_EQUAL(c, foo[&c]);
}

TEST(ForwardUnorderedMapConstIteration)
{
    cUnorderedMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;
    foo[20] = -20;

    cUnorderedMap<int,int>::const_iterator_type it = foo.cbegin();

    for(;it!=foo.cend();++it)
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

TEST(ReverseUnorderedMapConstIteration)
{
    cUnorderedMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;
    foo[20] = -20;

    cUnorderedMap<int,int>::const_reverse_iterator_type it = foo.crbegin();

    for(;it!=foo.crend();++it)
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

TEST(ForwardUnorderedMapIteration)
{
    cUnorderedMap<const int*, int> foo;

    foo[0] = (const int *)NULL;
    foo[1] = (const int *)NULL;
    foo[10] = (const int *)NULL;

    cUnorderedMap<const int*,int>::iterator_type it = foo.begin();

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

TEST(ForwardUnorderedMapIterationWithFilter)
{
    cUnorderedMap<int, int> foo;

    foo[0] = 0;
    foo[1] = 1;
    foo[10] = 20;

    cUnorderedMap<int,int>::iterator_type it = foo.begin([](const cPair<const int,int>& i_pair){ return i_pair.second > 0;});

    for(;it!=foo.end();it++)
    {
        cPair<const int, int>& itPair = *it;

        switch(itPair.first)
        {
            case 1: CHECK_EQUAL(1, itPair.second); break;
            case 10: CHECK_EQUAL(20, itPair.second); break;
            default: printf("ep! unexpected value: %d\n", itPair.first);
        }
    }
}

}

