#include "UnitTest++.h"
#include "YTL/container/cTrie.h"
#include "YTL/container/cString.h"
#include "YTL/container/cBlockSet.h"

using namespace yame;

namespace
{

TEST(EmptyTrieOfString)
{
    container::cTrie<int, container::string> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(EmptyTrieOfBitset)
{
    container::cTrie<int, container::cBitSet<>> foo;

    CHECK_EQUAL(true, foo.empty());
}

TEST(ModifyTrieOfBitset)
{
    container::cTrie<int, container::cBitSet<>> foo;

    foo.emplace(0x53385678, 0);
    foo.emplace(0x53384321, 1);
    foo.emplace(0x53387482, 2);
    foo.emplace(0x53380012, 3);
    foo.emplace(0x53383751, 4);
    foo.emplace(0x53387701, 5);

    CHECK_EQUAL(false, foo.empty());
}

TEST(ModifyTrieOfString)
{
    container::cTrie<int, container::string> foo;

    foo.emplace("hello", 0);
    foo.emplace("cup", 1);
    foo.emplace("cups", 2);
    foo.emplace("cut", 3);
    foo.emplace("cuttie", 4);
    foo.emplace("welcome", 5);

    typename container::cTrie<int, container::string>::iterator_type itFFoo = foo.begin();

    for(;itFFoo!=foo.end();++itFFoo)
    {
        printf("we have forward %d at %s\n", (*itFFoo).second, (*itFFoo).first.getStr());
    }

    typename container::cTrie<int, container::string>::reverse_iterator_type itRFoo = foo.rbegin();

    for(;itRFoo!=foo.rend();++itRFoo)
    {
        printf("we have backward %d at %s\n", (*itRFoo).second, (*itRFoo).first.getStr());
    }

    CHECK_EQUAL(false, foo.empty());
}

TEST(EraseTrieEntryOfString)
{
    container::cTrie<int, container::string> foo;

    foo.emplace("hello", 0);
    foo.emplace("cup", 1);
    foo.emplace("cups", 2);
    foo.emplace("cut", 3);
    foo.emplace("cuttie", 4);
    foo.emplace("cuze", 4);
    foo.emplace("welcome", 5);

    typename container::cTrie<int, container::string>::iterator_type itFoo = foo.begin();

    for(;itFoo!=foo.end();++itFoo)
    {
        printf("before we have %d at %s\n", (*itFoo).second, (*itFoo).first.getStr());
    }

    itFoo = foo.search("cups");

    if(itFoo != foo.end())
    {
        foo.erase(itFoo);
    }

    itFoo = foo.search("hello");

    if(itFoo != foo.end())
    {
        foo.erase(itFoo);
    }

    itFoo = foo.search("cuttie");

    if(itFoo != foo.end())
    {
        foo.erase(itFoo);
    }

    itFoo = foo.search("kk");

    if(itFoo != foo.end())
    {
        foo.erase(itFoo);
    }

    itFoo = foo.begin();

    for(;itFoo!=foo.end();++itFoo)
    {
        printf("after before we have %d at %s\n", (*itFoo).second, (*itFoo).first.getStr());
    }

    CHECK_EQUAL(false, foo.empty());
}

TEST(EraseTrieOfStringAllEntries)
{
    container::cTrie<int, container::string> foo;

    foo.add(container::cPair<const container::string, int>("hello", 0));
    foo.add(container::cPair<const container::string, int>("cups", 0));
    foo.add(container::cPair<const container::string, int>("cut", 0));
    foo.add(container::cPair<const container::string, int>("cuttie", 0));
    foo.add(container::cPair<const container::string, int>("cutter", 0));
    foo.add(container::cPair<const container::string, int>("cuqa", 0));
    foo.add(container::cPair<const container::string, int>("cuze", 0));
    foo.add(container::cPair<const container::string, int>("welcome", 0));

    typename container::cTrie<int, container::string>::iterator_type itFoo = foo.search("cut");

    if(itFoo != foo.end())
    {
        foo.erase(itFoo);
    }

    itFoo = foo.begin();

    for(;itFoo!=foo.end();++itFoo)
    {
        printf("before we have %d at %s\n", (*itFoo).second, (*itFoo).first.getStr());
    }

    itFoo = foo.begin();

    for(;itFoo!=foo.end();)
    {
        itFoo = foo.erase(itFoo);
    }

    CHECK_EQUAL(true, foo.empty());
}

}

