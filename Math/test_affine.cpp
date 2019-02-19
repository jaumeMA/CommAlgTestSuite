#include "UnitTest++.h"
#include "Utils/engine.h"
#include "Math/cAffineSpace.h"
#include "Math/cVectorSpace.h"
#include "Math/cMathOps.h"
#include "Math/cAffineFunctionSpace.h"

namespace
{

typedef yame::math::R1 vec1r;
typedef yame::math::R2 vec2r;
typedef yame::math::R3 vec3r;

using namespace yame::math;

TEST(AffineDecl)
{
    AR1 ar1;
    AR2 ar2;
    AR3 ar3;

    AC1 ac1;
    AC2 ac2;
    AC3 ac3;
}

TEST(AffineDisplacement)
{
    vec1r vec1(0.5f);
    AR1 ar1(vec1);

    ar1 = ar1 + vec1;

    CHECK_EQUAL(true, ar1 == 1.f);
}

TEST(AffineCompare)
{
    vec1r orig1(0.5f);
    vec1r vec1(1.5f);
    AR1 ar1(orig1,vec1);

    vec1r orig2(2.5f);
    vec1r vec2(-0.5f);
    AR1 ar2(orig2,vec2);

    CHECK_EQUAL(true, ar1 == ar2);
}

TEST(EmptyAffineFunction)
{
    AFR1 afr1;
}

}
