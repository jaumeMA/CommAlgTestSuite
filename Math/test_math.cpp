#include "UnitTest++.h"
#include "Math/cVectorFunctionSpace.h"
#include "Math/cMathOps.h"
#include "Math/cPolynomialAlgebra.h"

namespace
{

typedef yame::math::R2 vec2r;
typedef yame::math::R3 vec3r;

TEST(RealDerivative)
{
    using namespace yame::math;

    FR2 planeFunc = (FR2::x_0 * FR2::x_0 * FR2::x_0 + FR2::x_1 * FR2::x_1) + FR2::x_1 * FR2::x_1 * (FR2::x_0 + FR2::x_0) + (FR2::x_1 * FR2::x_0 + FR2::x_1*(FR2::x_0 + FR2::x_1 * FR2::x_0)) * FR2::x_0;
    yame::math::Real planeFuncRes = planeFunc.eval(Real(2.f), Real(3.f));
    printf("Plane Func: %f\n", planeFuncRes.get_raw());

    yame::container::cTupla<FR2, 2> planeFuncDerDir = yame::math::derivative<0,1>(planeFunc);
    FR2 planeFuncDer = yame::math::derivative(vec2r(1.f, 1.f), planeFunc);

    yame::container::string derStr = yame::format(planeFuncDer.eval(Real(1.f),Real(1.f)));

    printf("derivada %s\n", derStr.getStr());
}

TEST(TaylorSeries)
{
    using namespace yame::math;

    FR2 planeFunc = (FR2::x_0 * FR2::x_0 * FR2::x_0 + FR2::x_1 * FR2::x_1) + FR2::x_1 * FR2::x_1 * (FR2::x_0 + FR2::x_0) + (FR2::x_1 * FR2::x_0 + FR2::x_1*(FR2::x_0 + FR2::x_1 * FR2::x_0)) * FR2::x_0;
    FR3 baseFunc1 = FR3::x_0 * FR3::x_1;
    FR3 baseFunc2 = FR3::x_1 + FR3::x_2;
    FR2 expOverPlane = ExpReal(planeFunc);
    FR1 otherFunc1 = FR1::_1 / (FR1::_1 - FR1::x_0);
    FR3 otherFunc = planeFunc(baseFunc1,baseFunc2);
    real_polynomial poly1 = taylorSeries(otherFunc1, R1(0.f));
    real_polynomial poly2 = taylorSeries(otherFunc, vec3r(1.f,2.f,3.f));

    yame::container::string polyAsStr1 = yame::format(poly1);
    printf("El desenvolupament de taylor es: %s\n",polyAsStr1.getStr());
}

}
