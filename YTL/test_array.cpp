#include "UnitTest++.h"
#include "YTL/container/cArray.h"
#include "YTL/container/cAlgorithm.h"
#include "YTL/container/cIterable.h"
#include "YTL/types/smartPtr/unique_ptr.h"
#include "YTL/container/cParameterPack.h"
#include "YTL/container/cString.h"

using namespace yame::container;

namespace
{

TEST(EmptyArray)
{
    cArray<int> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(ArrayPush)
{
    cArray<int> foo;

    foo.push_back(5);
    foo.push_back(2);
    foo.push_back(10);
    foo.push_back(28);
    foo.push_back(4);
    foo.push_back(72);
    foo.push_back(1);

    CHECK_EQUAL(7, foo.getSize());

    yame::sort(foo);

    printf("\n larray sorted es:\n");

    typename cArray<int>::const_iterator_type itArray = foo.cbegin();

    for(;itArray!=foo.cend();itArray++)
    {
        printf("%d ",*itArray);
    }

    printf("\n");
}

TEST(ArrayMerge)
{
    cArray<int> foo1;

    foo1.push_back(5);
    foo1.push_back(2);
    foo1.push_back(10);
    foo1.push_back(28);

    cArray<int> foo2;
    foo2.push_back(4);
    foo2.push_back(72);
    foo2.push_back(1);

    cArray<int> foo3;

    yame::merge(foo1,foo2,foo3, yame::ytl::function<int(yame::ytl::optional<const int&>,yame::ytl::optional<const int&>)>([](yame::ytl::optional<const int&> i_valA, yame::ytl::optional<const int&> i_valB){ int res=0; if(i_valA) res+=*i_valA; if(i_valB) res+=*i_valB;return res;}));

    CHECK_EQUAL(4, foo3.getSize());

    typename cArray<int>::const_iterator_type itArray = foo3.cbegin();

    for(;itArray!=foo3.cend();itArray++)
    {
        printf("%d ",*itArray);
    }

    printf("\n");
}

TEST(ParameterPackCreation)
{
    parameter_pack<int,double,string> prova(10,20.5,"hello world");

    CHECK_EQUAL(prova.getValue<0>(), 10);
    CHECK_EQUAL(prova.getValue<1>(), 20.5);
    CHECK_EQUAL(true, prova.getValue<2>() == "hello world");

    prova.setValue<0>(20);
    prova.setValue<1>(10.5);
    prova.setValue<2>("goodbye world");

    CHECK_EQUAL(prova.getValue<0>(), 20);
    CHECK_EQUAL(prova.getValue<1>(), 10.5);
    CHECK_EQUAL(true, prova.getValue<2>() == "goodbye world");

    prova.setValues<2,0,1>("Yep",3,15.6);

    CHECK_EQUAL(prova.getValue<0>(), 3);
    CHECK_EQUAL(prova.getValue<1>(), 15.6);
    CHECK_EQUAL(true, prova.getValue<2>() == "Yep");

    parameter_pack<int,float,int> prova2(0,1.5,2);

    CHECK_EQUAL(prova2.getValue<0>(), 0);
    CHECK_EQUAL(prova2.getValue<1>(), 1.5);
    CHECK_EQUAL(prova2.getValue<2>(), 2);
}

}


