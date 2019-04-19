#include "UnitTest++.h"
#include "YTL/container/cParameterPack.h"
#include "YTL/container/cString.h"
#include "YTL/container/cParameterPackIterable.h"
#include "YTL/types/variant/custom_visitors.h"

using namespace yame::container;

namespace
{

TEST(ParameterPackCreation)
{
    yame::ytl::formatter_visitor formatterVisitor;
    parameter_pack<int,double,int,string> prova(10,20.5,15,"hello world");

    parameter_pack_iterable<int,double,int,string> packIterable(prova);
    parameter_pack_iterable<int,double,int,string>::const_iterator_type itPack = packIterable.cbegin();
    for(;itPack!=packIterable.cend();++itPack)
    {
        const yame::ytl::variant<const int&,const double&,const int&,const string&> currValue = *itPack;

        currValue.apply_visitor(formatterVisitor);
    }

    CHECK_EQUAL(prova.getValue<0>(), 10);
    CHECK_EQUAL(prova.getValue<1>(), 20.5);
    CHECK_EQUAL(prova.getValue<2>(), 15);
    CHECK_EQUAL(true, prova.getValue<3>() == "hello world");
}

}

