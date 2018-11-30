#include "UnitTest++.h"
#include "YTL/container/cStack.h"
#include "YTL/container/cIterable.h"
#include <thread>

using namespace yame::container;

namespace
{

TEST(EmptyStack)
{
    cStack<int> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(StackPush)
{
    cStack<int> foo;
    const size_t fooSize = 1000;

    for(size_t index=0;index<fooSize;index++)
    {
        foo.push(index);
    }

    CHECK_EQUAL(fooSize, foo.getSize());
}

TEST(StackPushAndPop)
{
    cStack<int> foo;
    const size_t fooSize = 1000;

    for(size_t index=0;index<fooSize;++index)
    {
        foo.push(index);
    }

    for(size_t index=0;index<fooSize;++index)
    {
        CHECK_EQUAL(index,*foo.pop());
    }

    CHECK_EQUAL(true, foo.empty());
}

TEST(StackOneThreadPushAndOneThreadPop)
{
    cStack<int> foo;
    const size_t fooSize = 1000;
    size_t numPushes = 0;
    size_t numPops = 0;

    auto pushFunc = [&foo,fooSize,&numPushes]()
    {
        for(size_t index=0;index<fooSize;++index)
        {
            foo.push(index);
            numPushes++;
        }
    };

    auto popFunc = [&foo,fooSize,&numPops]()
    {
        while(numPops < fooSize)
        {
            if(foo.pop())
            {
                numPops++;
            }
        }
    };

    std::thread pushThread(pushFunc);
    std::thread popThread(popFunc);

    pushThread.join();
    popThread.join();

    CHECK_EQUAL(numPushes,numPops);
}

TEST(StackOneThreadPushAndManyThreadPop)
{
    cStack<int> foo;
    const size_t fooSize = 10000;

    auto pushFunc = [&foo,fooSize]()
    {
        for(size_t index=0;index<fooSize;++index)
        {
            foo.push(index);
        }
    };

    auto popFunc = [&foo,fooSize]()
    {
        for(size_t index=0;index<fooSize;++index)
        {
            if(foo.empty() == false)
            {
                foo.pop();
            }
        }
    };

    std::thread pushThread(pushFunc);
    std::thread popThread0(popFunc);
    std::thread popThread1(popFunc);
    std::thread popThread2(popFunc);
    std::thread popThread3(popFunc);
    std::thread popThread4(popFunc);
    std::thread popThread5(popFunc);
    std::thread popThread6(popFunc);
    std::thread popThread7(popFunc);
    std::thread popThread8(popFunc);
    std::thread popThread9(popFunc);

    pushThread.join();
    popThread0.join();
    popThread1.join();
    popThread2.join();
    popThread3.join();
    popThread4.join();
    popThread5.join();
    popThread6.join();
    popThread7.join();
    popThread8.join();
    popThread9.join();
}

TEST(StackManyThreadPushAndManyThreadPop)
{
    cStack<int> foo;
    const size_t fooSize = 1000;

    auto pushFunc = [&foo,fooSize]()
    {
        for(size_t index=0;index<fooSize;++index)
        {
            foo.push(index);
        }
    };

    auto popFunc = [&foo,fooSize]()
    {
        for(size_t index=0;index<fooSize;++index)
        {
            if(foo.empty() == false)
            {
                foo.pop();
            }
        }
    };

    std::thread pushThread0(pushFunc);
    std::thread pushThread1(pushFunc);
    std::thread pushThread2(pushFunc);
    std::thread pushThread3(pushFunc);
    std::thread pushThread4(pushFunc);
    std::thread pushThread5(pushFunc);
    std::thread pushThread6(pushFunc);
    std::thread pushThread7(pushFunc);
    std::thread pushThread8(pushFunc);
    std::thread pushThread9(pushFunc);

    std::thread popThread0(popFunc);
    std::thread popThread1(popFunc);
    std::thread popThread2(popFunc);
    std::thread popThread3(popFunc);
    std::thread popThread4(popFunc);
    std::thread popThread5(popFunc);
    std::thread popThread6(popFunc);
    std::thread popThread7(popFunc);
    std::thread popThread8(popFunc);
    std::thread popThread9(popFunc);

    pushThread0.join();
    pushThread1.join();
    pushThread2.join();
    pushThread3.join();
    pushThread4.join();
    pushThread5.join();
    pushThread6.join();
    pushThread7.join();
    pushThread8.join();
    pushThread9.join();

    popThread0.join();
    popThread1.join();
    popThread2.join();
    popThread3.join();
    popThread4.join();
    popThread5.join();
    popThread6.join();
    popThread7.join();
    popThread8.join();
    popThread9.join();
}

TEST(StackPushAndIteration)
{
    cStack<int> foo;
    const size_t fooSize = 10;

    for(size_t index=0;index<fooSize;++index)
    {
        foo.push(index);
    }

    typename cStack<int>::const_iterator_type itStack = foo.cbegin();
    for(size_t index=0;itStack!=foo.cend();++itStack,++index)
    {
        CHECK_EQUAL(index,*itStack);
    }

    CHECK_EQUAL(true, foo.empty());
}

}
