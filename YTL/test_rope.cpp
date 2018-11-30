#include "UnitTest++.h"
#include "YTL/container/cRope.h"

namespace
{

TEST(EmptyRope)
{
    yame::container::cRope<> rope;
}

TEST(InsertRope)
{
    yame::container::cRope<> rope;

    rope.insert(rope.begin(),"hola");
    rope.insert(rope.begin() + 4," i ");
    rope.insert(rope.begin() + 7," company");
    rope.insert(rope.begin() + 7,"adeu");

    CHECK_EQUAL(true, rope.subStr(rope.cbegin(),rope.cend()) == "hola i adeu company");
}

TEST(RemoveRope)
{
    yame::container::cRope<> rope;

    rope.insert(rope.begin(),"hola y adeu company anomenat jaumet");
    rope.remove(rope.begin() + 4,rope.begin() + 28);
    yame::container::string content = rope.subStr(rope.cbegin(),rope.cend());
    CHECK_EQUAL(true, content == "hola jaumet");
}

TEST(LargeSentence)
{
    yame::container::cRope<> rope;

    rope.insert(rope.begin(),"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

    CHECK_EQUAL(true, rope.subStr(rope.cbegin(),rope.cend()) == "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
}

TEST(LargeSentenceAndRemove)
{
    yame::container::cRope<> rope;
    yame::container::string content;

    rope.insert(rope.begin(),"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    rope.remove(rope.begin() + 6,rope.begin() + 12);
    rope.remove(rope.begin() + 22,rope.begin() + 34);
    rope.remove(rope.begin() + 33,rope.begin() + 39);
    rope.remove(rope.begin() + 40,rope.begin() + 48);

    CHECK_EQUAL(true, rope.subStr(rope.cbegin(),rope.cend()) == "Lorem dolor sit amet, adipiscing sed do tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
}

}
