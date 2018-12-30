#include "UnitTest++.h"
#include "Math/cVectorFunctionSpace.h"
#include "Math/cMathOps.h"
#include "Math/cPolynomialAlgebra.h"
#include "Math/cLinearVectorFunction.h"

namespace
{

typedef yame::math::R1 vec1r;
typedef yame::math::R2 vec2r;
typedef yame::math::R3 vec3r;

TEST(RealDerivative)
{
    using namespace yame::math;
    VFR2 prova1;
    VFR2 prova2 = prova1;
    VFR2 planeFunc = (2.f * VFR2::x_0 * VFR2::x_0 * VFR2::x_0 + VFR2::x_1 * VFR2::x_1) + VFR2::x_1 * VFR2::x_1 * (VFR2::x_0 + VFR2::x_0) + (VFR2::x_1 * VFR2::x_0 + VFR2::x_1*(VFR2::x_0 + VFR2::x_1 * VFR2::x_0)) * VFR2::x_0;
    VF<R2,R2> vectorProva = {VFR2::x_0 * VFR2::x_0, VFR2::x_1 * VFR2::x_1 * (VFR2::x_0 + VFR2::x_0)};
    yame::math::R1 planeFuncRes = planeFunc.eval(Real(2.f), Real(3.f));
    printf("Plane Func: %f\n", planeFuncRes[0].get_raw());

    detail::linear_function<Real,R2> linearProva = 2.f * (VFR2::x_0 + VFR2::x_1 + 5.f) + VFR2::x_0 + 4.5f * VFR2::x_1 + 7.4f;
    rvector<2+1> as_vector = linearProva.as_vector();
    double as_vector_0 = as_vector[0].get_raw();
    double as_vector_1 = as_vector[1].get_raw();
    double as_vector_2 = as_vector[2].get_raw();
    rvector<3> provaVector(0.f,
                           1.f,
                           2.f);
    rmatrix<3,1> provaMatriu(0.f,
                             1.f,
                             2.f);
    VF<R3,R1> provaLinearVectorFunc(provaMatriu);

    rmatrix<3,2> provaMatrix(0.f,1.f,
                             2.f,3.f,
                             4.f,5.f);
    LF<R3,R2> provaLinearMatrixFunc(provaMatrix);

    rmatrix<3,2+1> provaLinearMatrixFuncMatrix = provaLinearMatrixFunc.as_matrix();
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[0][0] == 0.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[0][1] == 1.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[0][2] == 0.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[1][0] == 2.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[1][1] == 3.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[1][2] == 0.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[2][0] == 4.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[2][1] == 5.f);
    CHECK_EQUAL(true, provaLinearMatrixFuncMatrix[2][2] == 0.f);

    R3 res = provaLinearMatrixFunc(5.f,1.f);
    CHECK_EQUAL(true, res[0] == 1.f);
    CHECK_EQUAL(true, res[1] == 13.f);
    CHECK_EQUAL(true, res[2] == 25.f);
    VF<R2,R1> vectorProvaSpec = vectorProva(3.f,yame::mpl::place_arg);

    VF<R2,R1> vectorProvaSpecDer = yame::math::derivative(vec1r(1.f), vectorProvaSpec);
    yame::container::cTupla<F<R2,R2>, 2> vectorProvaDerDir = yame::math::derivative<0,1>(vectorProva);
    yame::container::cTupla<VFR2, 2> planeFuncDerDir = yame::math::derivative<0,1>(planeFunc);
    VFR2 planeFuncDer = yame::math::derivative(vec2r(1.f, 1.f), planeFunc);

    yame::container::string planeFuncDerStr = yame::format(planeFuncDer.eval(Real(1.f),Real(1.f)));
    yame::container::string vectorProvaStr = yame::format(vectorProva.eval(Real(1.f),Real(1.f)));

    printf("derivada plane der %s\n", planeFuncDerStr.getStr());
    printf("derivada vectorProva %s\n", vectorProvaStr.getStr());
}

TEST(TaylorSeries)
{
    using namespace yame::math;

    VFR2 planeFunc = (VFR2::x_0 * VFR2::x_0 * VFR2::x_0 + VFR2::x_1 * VFR2::x_1) + VFR2::x_1 * VFR2::x_1 * (VFR2::x_0 + VFR2::x_0) + (VFR2::x_1 * VFR2::x_0 + VFR2::x_1*(VFR2::x_0 + VFR2::x_1 * VFR2::x_0)) * VFR2::x_0;
    VFR3 baseFunc1 = VFR3::x_0 * VFR3::x_1;
    VFR3 baseFunc2 = VFR3::x_1 + VFR3::x_2;
    VFR2 expOverPlane = ExpReal(planeFunc);
    VFR1 otherFunc1 = 1.f / (1.f - VFR1::x_0);
    VFR3 otherFunc = planeFunc(baseFunc1,baseFunc2);
    real_polynomial poly1 = taylorSeries(otherFunc1, vec1r(0.f));
    real_polynomial poly2 = taylorSeries(otherFunc, vec3r(1.f,2.f,3.f));

    yame::container::string polyAsStr1 = yame::format(poly1);
    printf("El desenvolupament de taylor es: %s\n",polyAsStr1.getStr());
}

}
