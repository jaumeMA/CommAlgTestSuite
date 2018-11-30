#include "UnitTest++.h"
#include "YTL/container/cBlockSet.h"

using namespace yame;

namespace
{

TEST(EmptyBitset)
{
    container::cBitSet<> bitset;

    CHECK_EQUAL(true, bitset.getMsb() == container::cBitSet<>::npos);
}

TEST(EmptyByteset)
{
    container::cByteSet<> byteset;

    CHECK_EQUAL(true, byteset.getMsb() == container::cByteSet<>::npos);
}

TEST(BitsetNumConstr)
{
    container::cBitSet<> bitset(10);

    CHECK_EQUAL(10, bitset.toInt());
}

TEST(BytesetNumConstr)
{
    container::cByteSet<> byteset(10);

    CHECK_EQUAL(10, byteset.toInt());
}

TEST(BitsetNumLeftShift)
{
    container::cBitSet<> bitset(10);

    bitset << 1;

    CHECK_EQUAL(20, bitset.toInt());
}

TEST(ByteSetNumLeftShift)
{
    container::cByteSet<> byteset(10);

    byteset << 1;

    CHECK_EQUAL(2560, byteset.toInt());
}

TEST(BitsetNumRightShift)
{
    container::cBitSet<> bitset(10);

    bitset >> 1;

    CHECK_EQUAL(5, bitset.toInt());
}

TEST(BytesetNumRightShift)
{
    container::cByteSet<> byteset(10);

    byteset >> 1;

    CHECK_EQUAL(true, byteset.getMsb() == container::cByteSet<>::npos);
}

TEST(BitsetNumRightShiftToZero)
{
    container::cBitSet<> bitset(10);

    bitset >> 1 >> 1 >> 1 >> 1;

    CHECK_EQUAL(true, bitset.getMsb() == container::cBitSet<>::npos);
}

TEST(BitsetNumAddition)
{
    container::cBitSet<> bitset1(3853);
    container::cBitSet<> bitset2(17956);
    container::cBitSet<> bitset3 = bitset1 + bitset2;

    CHECK_EQUAL(3853, bitset1.toInt());
    CHECK_EQUAL(17956, bitset2.toInt());
    CHECK_EQUAL(73551629, bitset3.toInt());
}

TEST(ByteSetNumAddition)
{
    container::cByteSet<> byteset1(3853);
    container::cByteSet<> byteset2(17956);
    container::cByteSet<> byteset3 = byteset1 + byteset2;

    CHECK_EQUAL(3853, byteset1.toInt());
    CHECK_EQUAL(17956, byteset2.toInt());
    CHECK_EQUAL(1176768269, byteset3.toInt());
}

}

