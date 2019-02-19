#include "UnitTest++.h"
#include "Utils/engine.h"
#include "Math/cVectorSpace.h"
#include "Math/cMathOps.h"

namespace
{

typedef yame::math::vector<yame::math::Real,2> vec2r;

TEST(Vec2rDecl)
{
    vec2r vec2;
}
TEST(Vec2rAccess)
{
    vec2r vec2;

    vec2[0] = 1.f;
    vec2[1] = yame::math::Real(2.f);

    const double vec0d = vec2[0].get_raw();
    const double vec1d = vec2[1].get_raw();

    CHECK_EQUAL(true, vec2[0] == yame::math::Real(1.f));
    CHECK_EQUAL(true, vec2[1] == yame::math::Real(2.f));
}
TEST(Vec2rAddition)
{
    vec2r vec1, vec2;

    vec1[0] = 1.f;
    vec1[1] = 2.f;

    vec2[0] = 2.f;
    vec2[1] = 1.f;

    vec2r vec3 = vec1 + vec2;

    CHECK_EQUAL(true, vec3[0] == yame::math::Real(3.f));
    CHECK_EQUAL(true, vec3[1] == yame::math::Real(3.f));
}
TEST(Vec2rProduct)
{
    vec2r vec1, vec2;

    vec1[0] = 1.f;
    vec1[1] = 2.f;

    vec2[0] = 2.f;
    vec2[1] = 1.f;

    yame::math::Real prod = vec1 * vec2;

    CHECK_EQUAL(true, prod == yame::math::Real(4.f));
}

}

