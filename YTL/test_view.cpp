#include "UnitTest++.h"
#include "YTL/container/cContainerView.h"
#include "YTL/container/cArray.h"
#include "YTL/container/cMap.h"

using namespace yame::container;

namespace
{

TEST(EmptyView)
{
    //views cannot be empty
}

TEST(ArrayView)
{
    cArray<int> prova = {0,1,2,3,4,5};

    array_view<int> arrayView(prova);

    array_view<int>::iterator_type itProva = arrayView.begin();
    for(size_t arrayIndex=0;itProva!=prova.end();++itProva,++arrayIndex)
    {
        *itProva += 1;
    }

    itProva = arrayView.begin();
    for(size_t arrayIndex=0;itProva!=prova.end();++itProva,++arrayIndex)
    {
        CHECK_EQUAL(arrayIndex+1,*itProva);
    }
}
TEST(ArrayConstView)
{
    cArray<int> prova = {0,1,2,3,4,5};

    const_array_view<int> arrayView(prova);

    const_array_view<int>::const_iterator_type itProva = arrayView.cbegin();
    for(size_t arrayIndex=0;itProva!=prova.cend();++itProva,++arrayIndex)
    {
        CHECK_EQUAL(arrayIndex,*itProva);
    }
}
TEST(ArrayViewRebind)
{
    cArray<int> prova1 = {0,1,2,3,4,5};
    cArray<int> prova2 = {6,7,8,9,10,11};

    array_view<int> arrayView(prova1);

    array_view<int>::iterator_type itProva = arrayView.begin();
    for(size_t arrayIndex=prova1[0];itProva!=arrayView.end();++itProva,++arrayIndex)
    {
        CHECK_EQUAL(arrayIndex,*itProva);
    }

    arrayView = prova2;

    itProva = arrayView.begin();
    for(size_t arrayIndex=prova2[0];itProva!=arrayView.end();++itProva,++arrayIndex)
    {
        CHECK_EQUAL(arrayIndex,*itProva);
    }
}
TEST(MapView)
{
    cMap<int,int> prova;

    prova[0] = 0;
    prova[1] = 1;
    prova[2] = 2;
    prova[3] = 3;
    prova[4] = 4;
    prova[5] = 5;

    map_view<int,int> mapView(prova);

    map_view<int,int>::iterator_type itProva = mapView.begin();
    for(size_t mapIndex=0;itProva!=mapView.end();++itProva,++mapIndex)
    {
        CHECK_EQUAL(mapIndex,itProva->second);
    }
}
TEST(MapConstView)
{
    cMap<int,int> prova;

    prova[0] = 0;
    prova[1] = 1;
    prova[2] = 2;
    prova[3] = 3;
    prova[4] = 4;
    prova[5] = 5;

    const_map_view<int,int> mapView(prova);

    const_map_view<int,int>::const_iterator_type itProva = mapView.cbegin();
    for(size_t mapIndex=0;itProva!=mapView.cend();++itProva,++mapIndex)
    {
        CHECK_EQUAL(mapIndex,itProva->second);
    }
}
TEST(MapViewRebind)
{
    cMap<int,int> prova1;
    cMap<int,int> prova2;

    prova1[0] = 0;
    prova1[1] = 1;
    prova1[2] = 2;
    prova1[3] = 3;
    prova1[4] = 4;
    prova1[5] = 5;

    prova1[0] = 6;
    prova1[1] = 7;
    prova1[2] = 8;
    prova1[3] = 9;
    prova1[4] = 10;
    prova1[5] = 11;

    map_view<int,int> mapView(prova1);

    map_view<int,int>::iterator_type itProva = mapView.begin();
    for(size_t mapIndex=prova1[0];itProva!=mapView.end();++itProva,++mapIndex)
    {
        CHECK_EQUAL(mapIndex,itProva->second);
    }

    mapView = prova2;

    itProva = mapView.begin();
    for(size_t mapIndex=prova2[0];itProva!=mapView.end();++itProva,++mapIndex)
    {
        CHECK_EQUAL(mapIndex,itProva->second);
    }
}
}



