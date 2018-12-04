#include "UnitTest++.h"
#include "Math/cNumberSpaces.h"


namespace
{

TEST(RationalNumberDeclaration)
{
    yame::math::Rational foo;
}
TEST(RealNumberDeclaration)
{
    yame::math::Real foo;
    foo = yame::math::Real::ring::neutral_element();
    double _foo = foo.get_raw();
    printf("valor del real neutral ring element: %g\n",_foo);
}
TEST(ComplexNumberDeclaration)
{
    yame::math::Complex foo;
}
TEST(QuaternionNumberDeclaration)
{
    yame::math::Quaternion foo;
}
TEST(ZpNumberDeclaration)
{
    yame::math::Zp<31> foo;
}
TEST(RationalNumberConstruction)
{
    yame::math::Rational foo = yame::math::Rational(10, 12);

    CHECK_EQUAL(true, foo.numerator() == 10);
    CHECK_EQUAL(true, foo.denominator() == 12);
}
TEST(RealNumberConstruction)
{
    yame::math::Real foo(10.2f);

    CHECK_EQUAL(true, foo == yame::math::Real(10.2f));
}
TEST(ComplexNumberConstruction)
{
    yame::math::Complex foo(5.f, 6.f);

    CHECK_EQUAL(true, foo.real() == 5.f);
    CHECK_EQUAL(true, foo.imag() == 6.f);
}
TEST(QuaternionNumberConstruction)
{
    yame::math::Quaternion foo(-15.f, 1.f, 0.f, 10.f);

    CHECK_EQUAL(true, foo.n_part() == -15.f);
    CHECK_EQUAL(true, foo.i_part() == 1.f);
    CHECK_EQUAL(true, foo.j_part() == 0.f);
    CHECK_EQUAL(true, foo.k_part() == 10.f);
}
TEST(ZpNumberConstruction)
{
    yame::math::Zp<31> foo(12);

    CHECK_EQUAL(true, foo == yame::math::Zp<31>(12));
}
TEST(RationalNumberAssignment)
{
    yame::math::Rational foo;

    foo = yame::math::rationalPair(10, 12);

    CHECK_EQUAL(true, foo.numerator() == 10);
    CHECK_EQUAL(true, foo.denominator() == 12);
}
TEST(RealNumberAssignment)
{
    yame::math::Real foo;

    foo = 10.2f;

    CHECK_EQUAL(true, foo == yame::math::Real(10.2f));
}
TEST(ComplexNumberAssignment)
{
    yame::math::Complex foo;

    foo = yame::math::complexPair(5.f, 6.f);

    CHECK_EQUAL(true, foo.real() == 5.f);
    CHECK_EQUAL(true, foo.imag() == 6.f);
}
TEST(QuaternionNumberAssignment)
{
    yame::math::Quaternion foo;

    foo = yame::math::quaternionQuartet(-15.f, 1.f, 0.f, 10.f);

    CHECK_EQUAL(true, foo.n_part() == -15.f);
    CHECK_EQUAL(true, foo.i_part() == 1.f);
    CHECK_EQUAL(true, foo.j_part() == 0.f);
    CHECK_EQUAL(true, foo.k_part() == 10.f);
}
TEST(ZpNumberAssignment)
{
    yame::math::Zp<31> foo;

    foo = 12;

    CHECK_EQUAL(true, foo == yame::math::Zp<31>(12));
}
TEST(RationalNumberSum)
{
    yame::math::Rational foo1(3, 5);
    yame::math::Rational foo2(7, 2);

    yame::math::Rational fooSum = foo1 + foo2;

    CHECK_EQUAL(true, fooSum.numerator() == 41);
    CHECK_EQUAL(true, fooSum.denominator() == 10);
}
TEST(RealNumberSum)
{
    double foo = 10.3;
    yame::math::Real foo1(foo);
    yame::math::Real foo2(22.5f);
    yame::math::Real foo3(foo2);

    yame::math::Real fooSum = foo1 + foo2;

    double res1 = foo1.get_raw();
    double res2 = foo2.get_raw();
    double res = fooSum.get_raw();

    CHECK_EQUAL(true, fooSum == yame::math::Real(32.7f));
}
TEST(RealNumberProd)
{
    double foo = 2.5;
    yame::math::Real foo1(foo);
    yame::math::Real foo2(2.f);
    yame::math::Real foo3(foo2);

    yame::math::Real fooProd = foo1 * foo2;

    double res1 = foo1.get_raw();
    double res2 = foo2.get_raw();
    double res = fooProd.get_raw();

    CHECK_EQUAL(true, fooProd == yame::math::Real(5.f));
}
TEST(ComplexNumberSum)
{
    yame::math::Complex foo1(5.f, 6.f);
    yame::math::Complex foo2(1.5f, 7.f);

    yame::math::Complex fooSum = foo1 + foo2;

    CHECK_EQUAL(true, fooSum.real() == 6.5f);
    CHECK_EQUAL(true, fooSum.imag() == 13.f);
}
TEST(QuaternionNumberSum)
{
    yame::math::Quaternion foo1(-15.f, 1.f, 0.f, 10.f);
    yame::math::Quaternion foo2(10.f, 7.5f, 10.f, 0.f);

    yame::math::Quaternion fooSum = foo1 + foo2;

    CHECK_EQUAL(true, fooSum.n_part() == -5.f);
    CHECK_EQUAL(true, fooSum.i_part() == 8.5f);
    CHECK_EQUAL(true, fooSum.j_part() == 10.f);
    CHECK_EQUAL(true, fooSum.k_part() == 10.f);
}
TEST(ZpNumberSum)
{
    yame::math::Zp<31> foo1(12);
    yame::math::Zp<31> foo2(20);

    yame::math::Zp<31> fooSum = foo1 + foo2;

    CHECK_EQUAL(true, fooSum == yame::math::Zp<31>(1));
}
}
