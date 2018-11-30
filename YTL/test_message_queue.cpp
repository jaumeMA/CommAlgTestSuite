#include "UnitTest++.h"
#include "YTL/signal/cMessageQueue.h"
#include <thread>

namespace
{

struct FooMessage
{
public:
    FooMessage() = default;
    FooMessage(int i_value)
    {
        m_number = i_value;
    }
    int getValue() const
    {
        return m_number;
    }
private:
    int m_number = 0;
};

struct FooMessageQueueProducerKey
{};

struct FooMessageQueueConsumerKey
{};

TEST(MessageQueueDeclaration)
{
    const size_t numOfMsgs = 1000;
    size_t numOfMsgsReceived = 0;
    size_t numPushes = 0;
    yame::ytl::async_signal<void(const FooMessage&),FooMessageQueueConsumerKey> msgDispatcher;
    yame::ytl::message_queue<FooMessage,FooMessageQueueProducerKey,FooMessageQueueConsumerKey> msgQueue(msgDispatcher);

    yame::ytl::message_producer<FooMessage>& msgProducer = yame::ytl::access<FooMessageQueueProducerKey>(msgQueue);

    auto producerThreadFunc = [&msgProducer,&numPushes,numOfMsgs]()
    {
        for(size_t msgIndex=0;msgIndex<numOfMsgs;msgIndex++,numPushes++)
        {
            msgProducer.push(msgIndex);
        }
    };

    auto consumerThread = [&numOfMsgsReceived](const FooMessage& i_msg)
    {
        numOfMsgsReceived++;
    };

    msgQueue.start();

    msgDispatcher.connect(consumerThread,yame::mpl::place_arg);
    std::thread producerThread(producerThreadFunc);

    producerThread.join();
    msgQueue.stop();

    CHECK_EQUAL(numOfMsgsReceived,numOfMsgs);
}

}
