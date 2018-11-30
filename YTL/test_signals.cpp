#include "UnitTest++.h"
#include "YTL/signal/cSignal.h"
#include "YTL/container/cArray.h"
#include "YTL/types/smartPtr/unique_ptr.h"

namespace
{

void lalala(int a, float b, int c)
{
}

struct SignalExecKey
{
};

class FooClass
{
public:
    FooClass()
    : m_executedValue(0)
    {
    }
    void nonCopiableData(int a, float b, int c, yame::ytl::unique_ref<int>&& i_val)
    {
        m_executedValue += a + int(b) + c + *i_val;
    }
    void nonStaticFooFunction(int a, float b, int c)
    {
        m_executedValue += a + int(b) + c;
    }
    static void staticFooFunction(int a, float b, int c)
    {
        m_staticExecutedValue += a + int(b) + c;
    }
    int getExecutedValue() const
    {
        return m_executedValue;
    }

    static int m_staticExecutedValue;
private:
    int m_executedValue;
};

int FooClass::m_staticExecutedValue = 0;

TEST(NullSignal)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;
}

TEST(NonStaticMemberFunctionConnect)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, _arg, _arg);
}

TEST(StaticMemberFunctionConnect)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg);
}

TEST(NonStaticMemberFunctionExecute)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, _arg, _arg);

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6, foo.getExecutedValue());
}

TEST(NonStaticMemberFunctionNonCopiableDataExecute)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::ytl::unique_ref<int> fooData = yame::ytl::make_unique_ref<int>(20);

    fooSignal.connect(&foo, &FooClass::nonCopiableData, _arg, _arg, _arg, yame::mpl::move(fooData));

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(26, foo.getExecutedValue());

    *fooData = 40;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    //previous 26 plus 6 plus 40
    CHECK_EQUAL(72, foo.getExecutedValue());
}

TEST(NonStaticMemberFunctionDisconnect)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::ytl::connection conn = fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, _arg, _arg);

    conn.disconnect();

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(0, foo.getExecutedValue());
}

TEST(NonStaticMemberFunctionReconnect)
{
    FooClass foo;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::ytl::connection conn = fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, _arg, _arg);

    conn.disconnect();

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(0, foo.getExecutedValue());

    conn.connect();

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6, foo.getExecutedValue());
}

TEST(StaticMemberFunctionExecute)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg);

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6, FooClass::m_staticExecutedValue);
}

TEST(StaticMemberFunctionDisconnect)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::ytl::connection conn = fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg);

    conn.disconnect();

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(0, FooClass::m_staticExecutedValue);
}

TEST(StaticMemberFunctionReconnect)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::ytl::connection conn = fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg);

    conn.disconnect();

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(0, FooClass::m_staticExecutedValue);

    conn.connect();

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6, FooClass::m_staticExecutedValue);
}

TEST(MemberFunctionMultipleConnect)
{
    FooClass fooClass;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::container::cArray<yame::ytl::connection> connections;
    const size_t maxNumConnections = 1000;

    for(size_t connIndex = 0; connIndex < maxNumConnections; ++connIndex)
    {
        connections.push_back(fooSignal.connect(&fooClass, &FooClass::nonStaticFooFunction, _arg, _arg, _arg));
    }

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6 * maxNumConnections, fooClass.getExecutedValue());
}

TEST(StaticMemberFunctionMultipleConnect)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::container::cArray<yame::ytl::connection> connections;
    const size_t maxNumConnections = 1000;

    for(size_t connIndex = 0; connIndex < maxNumConnections; ++connIndex)
    {
        connections.push_back(fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg));
    }

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6 * maxNumConnections, FooClass::m_staticExecutedValue);
}

TEST(MemberFunctionMultipleConnectSomeDisconnect)
{
    FooClass fooClass;
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::container::cArray<yame::ytl::connection> connections;
    const size_t maxNumConnections = 1000;

    for(size_t connIndex = 0; connIndex < maxNumConnections; ++connIndex)
    {
        connections.push_back(fooSignal.connect(&fooClass, &FooClass::nonStaticFooFunction, _arg, _arg, _arg));
    }

    const size_t maxNumDisconnect = rand() % maxNumConnections;
    for(size_t currIndex = 0; currIndex < maxNumDisconnect; ++currIndex)
    {
        connections[currIndex].disconnect();
    }

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6 * (maxNumConnections - maxNumDisconnect), fooClass.getExecutedValue());
}

TEST(StaticMemberFunctionMultipleConnectSomeDisconnect)
{
    yame::ytl::signal<void(int, float, int),SignalExecKey> fooSignal;

    yame::container::cArray<yame::ytl::connection> connections;
    const size_t maxNumConnections = 1000;

    for(size_t connIndex = 0; connIndex < maxNumConnections; ++connIndex)
    {
        connections.push_back(fooSignal.connect(&FooClass::staticFooFunction, _arg, _arg, _arg));
    }

    const size_t maxNumDisconnect = rand() % maxNumConnections;
    for(size_t currIndex = 0; currIndex < maxNumDisconnect; ++currIndex)
    {
        connections[currIndex].disconnect();
    }

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1,2.5,3);

    CHECK_EQUAL(6 * (maxNumConnections - maxNumDisconnect), FooClass::m_staticExecutedValue);
}

TEST(StaticMemberFunctionConnectWithExtraArgs)
{
    yame::ytl::signal<void(int),SignalExecKey> fooSignal;

    fooSignal.connect(&FooClass::staticFooFunction, _arg, 2.5f, 10);
}

TEST(NonStaticMemberFunctionConnectWithExtraArgs)
{
    FooClass foo;
    yame::ytl::signal<void(int),SignalExecKey> fooSignal;

    fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, 2.5f, 10);
}

TEST(StaticMemberFunctionExecuteWithExtraArgs)
{
    yame::ytl::signal<void(int),SignalExecKey> fooSignal;

    fooSignal.connect(&FooClass::staticFooFunction, _arg, 2.5f, 10);

    FooClass::m_staticExecutedValue = 0;

    yame::ytl::access<SignalExecKey>(fooSignal).execute(1);

    CHECK_EQUAL(13 , FooClass::m_staticExecutedValue);
}

TEST(NonStaticMemberFunctionExecuteWithExtraArgs)
{
    FooClass foo;
    yame::ytl::signal<void(int),SignalExecKey> fooSignal;

    fooSignal.connect(&foo, &FooClass::nonStaticFooFunction, _arg, 2.5f, 10);

    yame::ytl::access<SignalExecKey>(fooSignal).execute(10);

    CHECK_EQUAL(22, foo.getExecutedValue());
}

}


