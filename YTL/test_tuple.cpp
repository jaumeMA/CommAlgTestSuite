#include "UnitTest++.h"
#include "YTL/container/cTupla.h"
#include "YTL/container/cAlgorithm.h"
#include "YTL/container/cIterable.h"

using namespace yame::container;

namespace
{

TEST(TupleSize)
{
    cTupla<int,2> foo1;
    cTupla<int,3,4> foo2;
    cTupla<int,5,7,2> foo3;

    CHECK_EQUAL(2, foo1.getSize());
    CHECK_EQUAL(12, foo2.getSize());
    CHECK_EQUAL(70, foo3.getSize());
}

TEST(TupleAccess)
{
    cTupla<int,6> foo1;
    cTupla<int,3,4> foo2;
    cTupla<int,5,7,2> foo3;

    foo1[3] = 10;
    foo1[1] = 11;
    foo2[1][2] = 20;
    foo2[2][1] = 21;
    foo3[2][4][1] = 30;
    foo3[4][6][0] = 31;

    CHECK_EQUAL(10, foo1[3]);
    CHECK_EQUAL(11, foo1[1]);
    CHECK_EQUAL(20, foo2[1][2]);
    CHECK_EQUAL(21, foo2[2][1]);
    CHECK_EQUAL(30, foo3[2][4][1]);
    CHECK_EQUAL(31, foo3[4][6][0]);
}

TEST(TupleIteration)
{
    cTupla<int,3,2> foo({1,2,3,4,5,6});

    cTupla<int,3,2>::const_iterator_type itTupla = foo.cbegin();

    for(size_t counter=0;itTupla!=foo.cend();itTupla++,counter++)
    {
        CHECK_EQUAL(foo[counter/2][counter%2], (*itTupla).second);
    }
}

}



