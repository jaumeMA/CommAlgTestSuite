#include "UnitTest++.h"
#include "YTL/container/cString.h"
#include "YTL/container/cIterable.h"

using namespace yame::container;

namespace
{

TEST(EmptyString)
{
    string foo;
    CHECK_EQUAL(foo.getSize(), 0);

    int a = 0;
    float b = 0;
    string kk;
}

TEST(StringRawCharConstruction)
{
    string foo1 = "holaQueAse";
    string foo2 = "VieneOqUEaSE";
    string foo3 = foo1 + foo2;


    CHECK_EQUAL(foo1.getStr(), "holaQueAse");
    CHECK_EQUAL(foo1.getSize(), 10);
}

TEST(StringCharAndLengthConstruction)
{
    string foo = string('a', 5);

    CHECK_EQUAL(foo.getStr(), "aaaaa");
    CHECK_EQUAL(foo.getSize(), 5);
}

TEST(StringMoveConstruction)
{
    string foo = "holaQueAse";
    string _foo = std::move(foo);

    CHECK_EQUAL(_foo.getStr(), "holaQueAse");
    CHECK_EQUAL(_foo.getSize(), 10);
    CHECK_EQUAL(foo.getSize(), 0);
}

TEST(StringCopyAssignment)
{
    string foo = "holaQueAse";
    string _foo;

    _foo = foo;

    CHECK_EQUAL(_foo.getStr(), "holaQueAse");
    CHECK_EQUAL(_foo.getSize(), 10);
    CHECK_EQUAL(foo.getStr(), "holaQueAse");
    CHECK_EQUAL(foo.getSize(), 10);
}

TEST(StringMoveAssignment)
{
    string foo1 = "holaQueAse, viene o que ase?";
    string _foo1;

    _foo1 = std::move(foo1);

    CHECK_EQUAL(_foo1.getStr(), "holaQueAse, viene o que ase?");
    CHECK_EQUAL(_foo1.getSize(), 28);
    CHECK_EQUAL(foo1.getSize(), 0);
}

TEST(StringPushBack)
{
    string foo = "holaQueAse";

    foo += ", viene o que ase?";

    CHECK_EQUAL(foo.getStr(), "holaQueAse, viene o que ase?");
    CHECK_EQUAL(foo.getSize(), 28);
    printf("\n tenim: %s.\n",foo.getStr());
}

TEST(StringAccess)
{
    string foo = "holaQueAse";

    CHECK_EQUAL('h', foo.front());
    CHECK_EQUAL('e', foo.back());
    CHECK_EQUAL('a', foo[3]);
}

TEST(StringComparison)
{
    string foo = "holaQueAse";

    CHECK_EQUAL(true, foo == "holaQueAse");
    CHECK_EQUAL(false, foo == "holaQueAs");
}

TEST(StringIteration)
{
    string foo = "holaQueAse";

    string::const_iterator_type itString = foo.cbegin();
    size_t counter = 0;

    for(;itString!=foo.cend();itString++,counter++)
    {
        CHECK_EQUAL(foo[counter], *itString);
    }
}

TEST(StringFilteredIteration)
{
    string foo = "holaQuease";

    string::const_iterator_type itString = foo.cbegin([](char val) { return val == 'a';});
    size_t counter = 0;

    for(;itString!=foo.cend();itString++,counter++)
    {
        CHECK_EQUAL('a', *itString);
    }

    CHECK_EQUAL(2, counter);
}

TEST(IterableOverString)
{
    string foo = "holaQuease";

    cConstRandomAccessInterIterable<1, char&> prova(foo);
    cConstRandomAccessInterIterable<1, char&> fooToIntIterable(prova);
    /*cCopyRandomAccessIterator<int> itFooToInt = fooToIntIterable.begin();

    for(;itFooToInt!=fooToIntIterable.end();itFooToInt++)
    {
        printf("getting int %d\n", *itFooToInt);
    }*/
}

}
