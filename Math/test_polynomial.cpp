#include "UnitTest++.h"
#include "Utils/engine.h"
#include "Math/cPolynomialAlgebra.h"
#include "Math/cPolynomialOps.h"
#include "Math/cPolynomialIterable.h"
#include "YTL/container/cAlgorithm.h"
#include "System/memory/cMemoryMgr.h"

namespace
{

TEST(EmptyPoly)
{
    yame::math::real_polynomial poly;

    //CHECK_EQUAL(poly.getNumMonomials(), 0);
}

TEST(PolyAssignmentReal)
{
    yame::math::real_polynomial poly;

    poly.at(0) = 1.f;
    poly.at(1,1) = 2.f;
    poly.at(1,1) = 4.f;
    poly.at(2,2) = 8.f;

    //CHECK_EQUAL(poly.getNumMonomials(), 3);
    //CHECK_EQUAL(true, poly.at(0) == 1.f);
    //CHECK_EQUAL(true, poly.at(1,1) == 4.f);
    //CHECK_EQUAL(true, poly.at(2,2) == 8.f);

    yame::container::string polyAsStr = yame::format(poly);
    printf("\nreal poli: %s\n",polyAsStr.getStr());
}

TEST(PolyRealDerivative)
{
    yame::math::real_polynomial poly;

    poly.at(0) = 1.f;
    poly.at(1,1) = 2.f;
    poly.at(1,1) = 4.f;
    poly.at(2,2) = 8.f;

    yame::container::cTupla<yame::math::real_polynomial,2> derivedPoly = yame::math::derivative<0,1>(poly);

    yame::container::string polyAsStr = yame::format(poly);
    yame::container::string derxpolyAsStr = yame::format(derivedPoly[0]);
    yame::container::string derypolyAsStr = yame::format(derivedPoly[1]);

    printf("La derivada del polinomi %s:\n",polyAsStr.getStr());
    printf("en x: %s\n",derxpolyAsStr.getStr());
    printf("en y: %s\n",derypolyAsStr.getStr());
}

TEST(PolyAssignmentRealMonomial)
{
    //yame::math::real_polynomial poly = yame::math::cMonomial<yame::math::Real>(2.f, {1,1});

    //CHECK_EQUAL(poly.getNumMonomials(), 1);
    //CHECK_EQUAL(true, poly.at(1,1) == 2.f);
}

TEST(PolyAssignmentRational)
{
    yame::math::rational_polynomial poly;

    poly.at(0) = yame::math::Rational(1.f, 1.f);
    poly.at(1,1) = yame::math::Rational(2.f, 2.f);
    poly.at(1,1) = yame::math::Rational(4.f, 4.f);
    poly.at(2,2) = yame::math::Rational(8.f, 8.f);

    yame::container::string polyAsStr = yame::format(poly);
    printf("\ncomplex poli: %s\n",polyAsStr.getStr());
}

TEST(PolyAssignmentComplex)
{
    yame::math::complex_polynomial poly;

    poly.at(0) = yame::math::Complex(1.f, 1.f);
    poly.at(1,1) = yame::math::Complex(2.f, 2.f);
    poly.at(1,1) = yame::math::Complex(4.f, 4.f);
    poly.at(2,2) = yame::math::Complex(8.f, 8.f);

    yame::container::string polyAsStr = yame::format(poly);
    printf("\ncomplex poli: %s\n",polyAsStr.getStr());
}

TEST(PolyAssignmentQuaternion)
{
    yame::math::polynomial<yame::math::Quaternion> poly;

    poly.at(0) = yame::math::Quaternion(1.f, 1.f, 1.f, 1.f);
    poly.at(1,1) = yame::math::Quaternion(2.f, 2.f, 2.f, 2.f);
    poly.at(1,1) = yame::math::Quaternion(4.f, 4.f, 4.f, 4.f);
    poly.at(2,2) = yame::math::Quaternion(8.f, 8.f, 4.f, 4.f);

    yame::container::string polyAsStr = yame::format(poly);
    printf("\ncomplex poli: %s\n",polyAsStr.getStr());
}

TEST(PolyAssignmentZp)
{
    yame::math::polynomial<yame::math::Zp<31>> poly;

    poly.at(0) = yame::math::Zp<31>(1.f);
    poly.at(1,1) = yame::math::Zp<31>(2.f);
    poly.at(1,1) = yame::math::Zp<31>(4.f);
    poly.at(2,2) = yame::math::Zp<31>(8.f);

    yame::container::string polyAsStr = yame::format(poly);
    printf("\ncomplex poli: %s\n",polyAsStr.getStr());
}

TEST(PolySum)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(0) = 1.f;
    poly1.at(1,1) = 2.f;
    poly1.at(2,2) = 3.f;

    poly2.at(1) = 4.f;
    poly2.at(1,1) = 5.f;
    poly2.at(3,3) = 6.f;

    poly3 = poly1 + poly2;

    //CHECK_EQUAL(5, poly3.getNumMonomials());
    //CHECK_EQUAL(true, poly3.at(0) == 1.f);
    //CHECK_EQUAL(true, poly3.at(1) == 4.f);
    //CHECK_EQUAL(true, poly3.at(1,1) == 7.f);
    //CHECK_EQUAL(true, poly3.at(2,2) == 3.f);
    //CHECK_EQUAL(true, poly3.at(3,3) == 6.f);
}

TEST(PolySubs)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(0) = 1.f;
    poly1.at(1,1) = 2.f;
    poly1.at(2,2) = 3.f;

    poly2.at(1) = 4.f;
    poly2.at(1,1) = 5.f;
    poly2.at(3,3) = 6.f;

    poly3 = poly1 - poly2;

    yame::container::string polyAsStr = yame::format(poly3);
    printf("\nreste de polis: %s\n",polyAsStr.getStr());

    //CHECK_EQUAL(5, poly3.getNumMonomials());
    //CHECK_EQUAL(true, poly3.at(0) == 1.f);
    //CHECK_EQUAL(true, poly3.at(1) == -4.f);
    //CHECK_EQUAL(true, poly3.at(1,1) == -3.f);
    //CHECK_EQUAL(true, poly3.at(2,2) == 3.f);
    //CHECK_EQUAL(true, poly3.at(3,3) == -6.f);
}

TEST(PolyMult)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(0) = 1.f;
    poly1.at(1,1) = 2.f;
    poly1.at(2,2) = 3.f;

    poly2.at(0) = 2.f;
    poly2.at(1) = 4.f;
    poly2.at(1,1) = 5.f;
    poly2.at(3,3) = 6.f;

    poly3 = poly1 * poly2;

    yame::container::string polyLeftStr = yame::format(poly1);
    yame::container::string polyRightStr = yame::format(poly2);
    yame::container::string polyMultStr = yame::format(poly1 * poly2);
    printf("Real poly left: %s\n",polyLeftStr.getStr());
    printf("Real poly right: %s\n",polyRightStr.getStr());
    printf("Real poly mult: %s\n",polyMultStr.getStr());


    CHECK_EQUAL(9, poly3.getNumMonomials());
    CHECK_EQUAL(true, poly3.at(0) == yame::math::Real(2.f));
    CHECK_EQUAL(true, poly3.at(1) == yame::math::Real(4.f));
    CHECK_EQUAL(true, poly3.at(1,1) == yame::math::Real(9.f));
    CHECK_EQUAL(true, poly3.at(2,1) == yame::math::Real(8.f));
    CHECK_EQUAL(true, poly3.at(2,2) == yame::math::Real(16.f));
    CHECK_EQUAL(true, poly3.at(3,2) == yame::math::Real(12.f));
    CHECK_EQUAL(true, poly3.at(3,3) == yame::math::Real(21.f));
    CHECK_EQUAL(true, poly3.at(4,4) == yame::math::Real(12.f));
    CHECK_EQUAL(true, poly3.at(5,5) == yame::math::Real(18.f));
}

TEST(PolyComplexMult)
{
    yame::math::complex_polynomial poly1;
    yame::math::complex_polynomial poly2;
    yame::math::complex_polynomial poly3;

    poly1.at(0) = yame::math::Complex(1.f,1.f);
    poly1.at(1,1) = yame::math::Complex(2.f,2.f);
    poly1.at(2,2) = yame::math::Complex(3.f,3.f);

    poly2.at(0) = yame::math::Complex(2.f,2.f);
    poly2.at(1) = yame::math::Complex(4.f,4.f);
    poly2.at(1,1) = yame::math::Complex(5.f,5.f);
    poly2.at(3,3) = yame::math::Complex(6.f,6.f);

    poly3 = poly1 + poly2;
}

TEST(PolyDiv)
{
    yame::math::real_polynomial dividend;

    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;

    dividend.at(2,1) = 1.f;
    dividend.at(1,2) = 1.f;
    dividend.at(0,2) = 1.f;

    poly1.at(0,2) = 1.f;
    poly1.at(0,0,0) = -1.f;

    poly2.at(1,1) = 1.f;
    poly2.at(0,0,0,0,0,0,0) = -1.f;

    yame::container::cArray<yame::math::real_polynomial> base({poly1,poly2});

    yame::container::cArray<yame::math::real_polynomial> res = dividend / base;
    yame::container::cArray<yame::math::real_polynomial>::const_iterator_type itRes = res.cbegin();

    yame::container::string polyAsStr = yame::format(*itRes);
    printf("\nreste: %s\n",polyAsStr.getStr());

    for(;itRes!=res.cend();itRes++)
    {
        polyAsStr = yame::format(*itRes);
        printf("quocient: %s\n", polyAsStr.getStr());
    }
}

TEST(PolyLeadMonomial)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(1) = 3.f;
    poly1.at(0,1) = -6.f;
    poly1.at(0,0,1) = -2.f;

    poly2.at(1) = 2.f;
    poly2.at(0,1) = -4.f;
    poly2.at(0,0,0,1) = 4.f;

    poly3.at(1) = 1.f;
    poly3.at(0,1) = -2.f;
    poly3.at(0,0,1) = -1.f;
    poly3.at(0,0,0,1) = -1.f;

    yame::math::cPolynomialIterable<yame::math::Real> polyIt1(poly1);
    yame::math::cPolynomialIterable<yame::math::Real> polyIt2(poly2);
    yame::math::cPolynomialIterable<yame::math::Real> polyIt3(poly3);

    yame::math::cPolynomialIterable<yame::math::Real>::const_iterator_type itMono1 = yame::max(polyIt1, yame::ytl::function<bool(yame::math::cMonomial<yame::math::Real>,yame::math::cMonomial<yame::math::Real>)>(&yame::math::cMonomial<yame::math::Real>::lexMoreComparison));
    yame::math::cMonomial<yame::math::Real> mono1 = *itMono1;

    itMono1 = yame::max(polyIt2, yame::ytl::function<bool(yame::math::cMonomial<yame::math::Real>,yame::math::cMonomial<yame::math::Real>)>(&yame::math::cMonomial<yame::math::Real>::lexMoreComparison));
    yame::math::cMonomial<yame::math::Real> mono2 = *itMono1;

    itMono1 = yame::max(polyIt3, yame::ytl::function<bool(yame::math::cMonomial<yame::math::Real>,yame::math::cMonomial<yame::math::Real>)>(&yame::math::cMonomial<yame::math::Real>::lexMoreComparison));
    yame::math::cMonomial<yame::math::Real> mono3 = *itMono1;

    //CHECK_EQUAL(true, mono1.getCoeff() == 3.f);
    //CHECK_EQUAL(true, mono2.getCoeff() == 2.f);
    //CHECK_EQUAL(true, mono3.getCoeff() == 1.f);
}

TEST(PolyGrobnerBases)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(2) = 1.f;
    poly1.at(0,1) = 1.f;

    poly2.at(4) = 1.f;
    poly2.at(2,1) = 2.f;
    poly2.at(0,2) = 1.f;
    poly2.at(0) = 3.f;

    yame::container::cArray<yame::math::real_polynomial> base({poly1,poly2});

    yame::container::cArray<yame::math::real_polynomial> res = yame::math::grobnerBase(base);
    yame::container::cArray<yame::math::real_polynomial>::const_iterator_type itRes = res.cbegin();

    printf("\n");
    for(;itRes!=res.cend();itRes++)
    {
        yame::container::string polyAsStr = yame::format(*itRes);
        printf("base: %s\n",polyAsStr.getStr());
    }
}

TEST(EmptyPolyGrobnerBases)
{
    return;

    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    yame::container::cArray<yame::math::real_polynomial> base({poly1,poly2,poly3});

    yame::container::cArray<yame::math::real_polynomial> res = yame::math::grobnerBase(base);
    yame::container::cArray<yame::math::real_polynomial>::const_iterator_type itRes = res.cbegin();

    printf("\n");
    for(;itRes!=res.cend();itRes++)
    {
        yame::container::string polyAsStr = yame::format(*itRes);
        printf("base: %s\n",polyAsStr.getStr());
    }
}

TEST(NumPolyGrobnerBases)
{
    yame::math::real_polynomial poly1;
    yame::math::real_polynomial poly2;
    yame::math::real_polynomial poly3;

    poly1.at(0) = 3.f;
    poly2.at(0) = 2.f;
    poly3.at(0) = 1.f;

    yame::container::cArray<yame::math::real_polynomial> base({poly1,poly2,poly3});

    yame::container::cArray<yame::math::real_polynomial> res = yame::math::grobnerBase(base);
    yame::container::cArray<yame::math::real_polynomial>::const_iterator_type itRes = res.cbegin();

    printf("\n");
    for(;itRes!=res.cend();itRes++)
    {
        yame::container::string polyAsStr = yame::format(*itRes);
        printf("base: %s\n",polyAsStr.getStr());
    }
}

TEST(IterateOverPoly)
{
    yame::math::real_polynomial poly;

    poly.at(0) = 1.f;
    poly.at(1,1) = 2.f;
    poly.at(2,2) = 3.f;

    yame::math::cPolynomialIterable<yame::math::Real> polyIterable(poly);

    typename yame::math::cPolynomialIterable<yame::math::Real>::const_iterator_type itMaxMonomial = yame::max(polyIterable,yame::ytl::function<bool(yame::math::cMonomial<yame::math::Real>,yame::math::cMonomial<yame::math::Real>)>(&yame::math::cMonomial<yame::math::Real>::grLexMoreComparison));

    typename yame::math::cPolynomialIterable<yame::math::Real>::iterator_type itMonomial = polyIterable.begin();

    for(;itMonomial!=polyIterable.end();itMonomial++)
    {
        yame::math::cMonomial<yame::math::Real> mono = (*itMonomial);

        yame::container::string monomialAsStr = yame::format(mono);
        printf("monomi: %s a",monomialAsStr.getStr());

        bool firstIndex = true;

        for(size_t index=0;index<mono.getNumIndexes();index++)
        {
            printf((firstIndex) ? "%d" : ",%d",mono.getPowerOfIndex(index));

            firstIndex = false;
        }

        printf("\n");
    }
}

TEST(IterateOverSortedPoly)
{
    yame::math::real_polynomial poly;

    poly.at(0) = 1.f;
    poly.at(1,1) = 2.f;
    poly.at(2,2) = 3.f;

    yame::math::cPolynomialIterable<yame::math::Real> polyIterable(poly,&yame::math::cMonomial<yame::math::Real>::lexMoreComparison);

    typename yame::math::cPolynomialIterable<yame::math::Real>::iterator_type itMonomial = polyIterable.begin();

    for(;itMonomial!=polyIterable.end();itMonomial++)
    {
        yame::math::cMonomial<yame::math::Real> mono = (*itMonomial);

        yame::container::string monomialAsStr = yame::format(mono);
        printf("sorted monomi: %s a",monomialAsStr.getStr());

        bool firstIndex = true;

        for(size_t index=0;index<mono.getNumIndexes();index++)
        {
            printf((firstIndex) ? "%d" : ",%d",mono.getPowerOfIndex(index));

            firstIndex = false;
        }

        printf("\n");
    }
}

}
