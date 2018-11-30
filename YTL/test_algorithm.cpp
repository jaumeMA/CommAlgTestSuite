#include "UnitTest++.h"
#include "YTL/container/cArray.h"
#include "YTL/container/cAlgorithm.h"
#include "YTL/container/cIterable.h"

using namespace yame::container;

namespace
{

struct Data
{
public:
    Data(int i_a) : a(i_a){};
    int getA() const { return a; }
    operator int() const { return a; }
    bool operator<(const Data& other) const { return a < other.a; }
private:
    int a;
};

bool lessDataThan(const Data& i_lhs, const Data& i_rhs) { return i_lhs < i_rhs; }

TEST(FindMin)
{
    cArray<Data> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(1);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<Data>::const_iterator_type constItValByValueNoFunc = yame::min(foo.cbegin(), foo.cend());

    CHECK_EQUAL(1, *constItValByValueNoFunc);

    typename cArray<Data>::const_iterator_type constItValByValueFunc = yame::min(foo.cbegin(), foo.cend(), yame::ytl::function<bool(const Data&,const Data&)>(&lessDataThan));

    CHECK_EQUAL(1, *constItValByValueFunc);

    typename cArray<Data>::iterator_type itValByValueNoFunc = yame::min(foo.begin(), foo.end());

    CHECK_EQUAL(1, *itValByValueNoFunc);

    typename cArray<Data>::iterator_type itValByValueFunc = yame::min(foo.begin(), foo.end(), yame::ytl::function<bool(const Data&,const Data&)>(&lessDataThan));

    CHECK_EQUAL(1, *itValByValueFunc);

    typename cArray<Data>::const_iterator_type iterableValByValueNoFunc = yame::min(foo);

    CHECK_EQUAL(1, *iterableValByValueNoFunc);

    typename cArray<Data>::const_iterator_type iterableValByValueFunc = yame::min(foo, yame::ytl::function<bool(const Data&,const Data&)>(&lessDataThan));

    CHECK_EQUAL(1, *iterableValByValueFunc);

}

TEST(FindValue)
{
    cArray<int> foo;

    foo.push_back(10);
    foo.push_back(21);
    foo.push_back(32);
    foo.push_back(43);

    typename cArray<int>::const_iterator_type itValByValue = yame::find(foo, 10);

    CHECK_EQUAL(true, itValByValue!=foo.cend());

    int findVal = 21;
    typename cArray<int>::const_iterator_type itValByRef = yame::find(foo, findVal);

    CHECK_EQUAL(true, itValByValue!=foo.cend());
    CHECK_EQUAL(1, yame::distance(foo.cbegin(), itValByRef));

    findVal = 45;

    const int& constFindVal = findVal;
    typename cArray<int>::const_iterator_type itValByConstRef = yame::find(foo, constFindVal);

    CHECK_EQUAL(false, itValByConstRef!=foo.cend());
}


}

