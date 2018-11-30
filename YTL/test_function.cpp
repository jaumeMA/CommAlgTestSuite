#include "UnitTest++.h"
#include "YTL/functional/cFunction.h"
#include "YTL/functional/cFunctionOps.h"
#include "YTL/types/optional/optional.h"
#include "YTL/types/smartPtr/unique_ptr.h"
#include "Utils/engine.h"

namespace
{

int lalala(yame::ytl::unique_ref<int>&& i_val)
{
    return *i_val;
}

class FooClassFunction
{
    public:
    static int FooFunction(int a, float b, int c)
    {
        return a + int(b) + c;
    }
};

TEST(NullFunction)
{
    FooClassFunction foo;
    yame::ytl::function<int(int,float,int)> cucu(&FooClassFunction::FooFunction);
    yame::ytl::function<int()> __fooFunction([](){return 4;});
    yame::ytl::function<int(int,float,int)> fooFunction([](int a, float b, int c){return a + int(b) + c;});
    yame::ytl::function<int(int,std::string,int)> provaFunction([](int a, std::string b, int c){return a + b.length() + c;});

    yame::ytl::optional<int> resultt;
    resultt = fooFunction(0, 1.5f, 2);
    printf("resultt: %d\n", *resultt);

    yame::ytl::function<int(float,int)> specFoo = fooFunction(2, yame::mpl::place_arg, yame::mpl::place_arg);
    yame::ytl::function<int(int,int)> specProva = provaFunction(yame::mpl::place_arg, "caca", yame::mpl::place_arg);

    int result = specProva(4, 2);
    printf("result: %d\n", result);

    yame::ytl::function<int(float,int)> specFoo2 = specFoo(yame::mpl::place_arg, yame::mpl::place_arg);

    result = specFoo2(1.5f, 2);
    printf("result: %d\n", result);

    yame::ytl::function<int(int,float,int)> specFoo3 = fooFunction * fooFunction;
    result = specFoo3.eval(0, 1.5f, 2);
    printf("result: %d\n", result);
}

TEST(FunctionWithNonCopiableArgs)
{
    yame::ytl::function<int(yame::ytl::unique_ref<int>&&)> fooFunction(&lalala);
    yame::ytl::unique_ref<int> uniquePtr = yame::ytl::make_unique_ref<int>(10);
    static_assert(yame::mpl::is_type_constructible<yame::ytl::unique_ref<int>&&,decltype(yame::mpl::move(uniquePtr))>::value, "wtf");
    yame::ytl::function<int()> fooSpec = fooFunction(yame::mpl::move(uniquePtr));

    CHECK_EQUAL(10, int(fooSpec()));

    *uniquePtr = 20;

    CHECK_EQUAL(20, int(fooSpec()));

    *uniquePtr = 40;

    CHECK_EQUAL(40, int(fooSpec()));
}

TEST(DirectExecution)
{
    yame::ytl::function<int(int,float,int)> fooFunction([](int a, float b, int c){return a + int(b) + c;});

    CHECK_EQUAL(8, fooFunction.eval(3,2.5,3));
}

TEST(CurryingFunction)
{
    yame::ytl::function<int(int,float,int)> fooFunction([](int a, float b, int c){return a + int(b) + c;});

    yame::ytl::curried_function<int,int,float,int> curriedFunction;

    curriedFunction << fooFunction;

    CHECK_EQUAL(8, curriedFunction.eval(3).eval(2.5).eval(3));
}

}

