#include "UnitTest++.h"
#include "YTL/container/cParameterPack.h"
#include "YTL/container/cString.h"

using namespace yame::container;

namespace
{

TEST(ParameterPackCreation)
{
    parameter_pack<int,double,string> prova(10,20.5,"hello world");

    CHECK_EQUAL(prova.getValue<0>(), 10);
    CHECK_EQUAL(prova.getValue<1>(), 20.5);
    CHECK_EQUAL(true, prova.getValue<2>() == "hello world");
}

}

