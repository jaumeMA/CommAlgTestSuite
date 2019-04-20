#include "UnitTest++.h"
#include "YTL/types/smartPtr/lent_ref.h"
#include "YTL/types/smartPtr/unique_ref.h"
#include "Utils/rtti/rtti.h"
#include "YTL/types/smartPtr/ptr_utils.h"
#include <memory>

namespace
{

class StackDeleter : public yame::ytl::ISmartPtrDeleter
{
public:
    void Deallocate(void* ptr) override
    {
        //it is allocated in the stack, do nothing
    }
};

TEST(NullUniquePtr)
{
    yame::ytl::unique_ptr<int> foo;

    CHECK_EQUAL(true, foo == null_ptr);
}

TEST(UniquePtrConstr)
{
    int a = 10;
    StackDeleter stackDeleter;
    yame::ytl::unique_ref<int> foo(&a, &stackDeleter);

    CHECK_EQUAL(10, *foo);
}


class C7
{
    PUBLISH_RTTI_BASE_TYPE(C7)
public:
    C7(int i_c)
    : c7(i_c)
    {
    }
    virtual ~C7() = default;
    int getC7() const
    {
        return c7;
    }

private:
    int c7;

    PUBLISH_RTTI_TYPE_MEMBERS(C7,c7)
    PUBLISH_RTTI_TYPE_METHODS(C7,getC7)
    PUBLISH_RTTI_TYPE_INFO(C7)
};
class C8
{
    PUBLISH_RTTI_BASE_TYPE(C8)
public:
    C8(int i_c)
    : c8(i_c)
    {
    }
    virtual ~C8() = default;
    int getC8() const
    {
        return c8;
    }

private:
    int c8;

    PUBLISH_RTTI_TYPE_INFO(C8)
};
class C9
{
    PUBLISH_RTTI_BASE_TYPE(C9)
public:
    C9(int i_c)
    : c9(i_c)
    {
    }
    virtual ~C9() = default;
    int getC9() const
    {
        return c9;
    }

private:
    int c9;

    PUBLISH_RTTI_TYPE_INFO(C9)
};
class C10
{
    PUBLISH_RTTI_BASE_TYPE(C10)
public:
    C10(int i_c)
    : c10(i_c)
    {
    }
    virtual ~C10() = default;
    int getC10() const
    {
        return c10;
    }

private:
    int c10;

    PUBLISH_RTTI_TYPE_INFO(C10)
};
class C11
{
    PUBLISH_RTTI_BASE_TYPE(C11)
public:
    C11(int i_c)
    : c11(i_c)
    {
    }
    virtual ~C11() = default;
    int getC11() const
    {
        return c11;
    }

private:
    int c11;

    PUBLISH_RTTI_TYPE_INFO(C11)
};
class C12
{
    PUBLISH_RTTI_BASE_TYPE(C12)
public:
    C12(int i_c)
    : c12(i_c)
    {
    }
    virtual ~C12() = default;
    int getC12() const
    {
        return c12;
    }

private:
    int c12;

    PUBLISH_RTTI_TYPE_INFO(C12)
};
class C13
{
    PUBLISH_RTTI_BASE_TYPE(C13)
public:
    C13(int i_c)
    : c13(i_c)
    {
    }
    virtual ~C13() = default;
    int getC13() const
    {
        return c13;
    }

private:
    int c13;

    PUBLISH_RTTI_TYPE_INFO(C13)
};
class C14
{
    PUBLISH_RTTI_BASE_TYPE(C14)
public:
    C14(int i_c)
    : c14(i_c)
    {
    }
    virtual ~C14() = default;
    int getC14() const
    {
        return c14;
    }

private:
    int c14;

    PUBLISH_RTTI_TYPE_INFO(C14)
};
class C15
{
    PUBLISH_RTTI_BASE_TYPE(C15)
public:
    C15(int i_c = 15)
    : c15(i_c)
    {
    }
    virtual ~C15() = default;
    int getC15() const
    {
        return c15;
    }

private:
    int c15;

    PUBLISH_RTTI_TYPE_INFO(C15)
};
class C3 : public C7, public C8
{
    PUBLISH_RTTI_TYPE_BASES(C3,C7,C8)
public:
    C3(int i_c1, int i_c2)
    : C7(i_c1)
    , C8(i_c2)
    {
    }
    PUBLISH_RTTI_TYPE_INFO(C3)
};
class C4 : public C9, public C10
{
    PUBLISH_RTTI_TYPE_BASES(C4,C9,C10)
public:
    C4(int i_c1, int i_c2)
    : C9(i_c1)
    , C10(i_c2)
    {
    }
    PUBLISH_RTTI_TYPE_INFO(C4)
};
class C5 : public C11, public C12
{
    PUBLISH_RTTI_TYPE_BASES(C5,C11,C12)
public:
    C5(int i_c1, int i_c2)
    : C11(i_c1)
    , C12(i_c2)
    {
    }
    PUBLISH_RTTI_TYPE_INFO(C5)
};
class C6 : public C13, public C14
{
    PUBLISH_RTTI_TYPE_BASES(C6,C13,C14)
public:
    C6(int i_c1, int i_c2)
    : C13(i_c1)
    , C14(i_c2)
    {
    }

    PUBLISH_RTTI_TYPE_INFO(C6)
};

class CC
{
    PUBLISH_RTTI_BASE_TYPE(CC)
public:
    CC() = default;
};

class C2 : public C5, public C6, public C15
{
    PUBLISH_RTTI_TYPE_BASES(C2,C5,C6,C15)
public:
    C2(int i_c1, int i_c2, int i_c3, int i_c4)
    : C5(i_c1,i_c2)
    , C6(i_c3,i_c4)
    {
    }

    PUBLISH_RTTI_TYPE_INFO(C2)
};

class C1 : public C3, public C4
{
    PUBLISH_RTTI_TYPE_BASES(C1,C3,C4)
public:
    C1(int i_c1, int i_c2, int i_c3, int i_c4)
    : C3(i_c1,i_c2)
    , C4(i_c3,i_c4)
    {
    }

    PUBLISH_RTTI_TYPE_INFO(C1)
};

class C : public C1, public C2
{
    PUBLISH_RTTI_TYPE_BASES(C,C1,C2)

public:
    C(int i_c1, int i_c2, int i_c3, int i_c4, int i_c5, int i_c6, int i_c7, int i_c8)
    : C1(i_c1,i_c2,i_c3,i_c4)
    , C2(i_c5,i_c6,i_c7,i_c8)
    , a(100)
    , b(200.5f)
    , d('c')
    , e(75)
    {
    }

    int getA() const
    {
        return a;
    }
    float getB() const
    {
        return b;
    }
    char getD() const
    {
        return d;
    }

private:
    int a;
    float b;
    char d;
    int e;

    PUBLISH_RTTI_TYPE_MEMBERS(C,a,b,d,e)

    PUBLISH_RTTI_TYPE_INFO(C)
};

struct c_member_visitor : public yame::ytl::static_visitor<void>
{
public:
    void operator()(const yame::container::cPair<yame::container::string_view,int&>& i_value) const
    {
        printf("receving value int of %s: %d\n",i_value.first.getData(),i_value.second);
    }
    void operator()(const yame::container::cPair<yame::container::string_view,float&>& i_value) const
    {
        printf("receving value float of %s: %f\n",i_value.first.getData(),i_value.second);
    }
    void operator()(const yame::container::cPair<yame::container::string_view,char&>& i_value) const
    {
        printf("receving value char of %s: %c\n",i_value.first.getData(),i_value.second);
    }
};

TEST(MakeUniquePtr)
{
    yame::ytl::unique_ptr<int> foo = yame::ytl::make_unique<int>(10);

    CHECK_EQUAL(10, *foo);
}

TEST(MakeUniqueRef)
{
    yame::ytl::unique_ref<int> foo = yame::ytl::make_unique<int>(10);

    CHECK_EQUAL(10, *foo);
}

TEST(UniquePtrAssign)
{
    yame::ytl::unique_ptr<int> foo1;
    yame::ytl::unique_ptr<int> foo2 = yame::ytl::make_unique<int>(10);

    CHECK_EQUAL(10, *foo2);
    CHECK_EQUAL(true, foo1 == null_ptr);

    foo1 = yame::mpl::move(foo2);

    CHECK_EQUAL(10, *foo1);
    CHECK_EQUAL(true, foo2 == null_ptr);
}

TEST(UniquePtrPromotion)
{
    yame::ytl::unique_ptr<int> foo1 = yame::ytl::make_unique<int>(10);

    CHECK_EQUAL(10, *foo1);

    yame::ytl::unique_ref<int> foo2 = yame::ytl::promote_to_ref(yame::mpl::move(foo1));

    CHECK_EQUAL(10, *foo2);
    CHECK_EQUAL(true, foo1 == null_ptr);
}

TEST(UniqueRefAssign)
{
    yame::ytl::unique_ref<int> foo1 = yame::ytl::make_unique<int>(10);
    yame::ytl::unique_ref<int> foo2 = yame::ytl::make_unique<int>(20);

    CHECK_EQUAL(10, *foo1);
    CHECK_EQUAL(20, *foo2);

    foo1 = yame::mpl::move(foo2);

    CHECK_EQUAL(20, *foo1);
    CHECK_EQUAL(true, foo2 == null_ptr);
}

TEST(UniquePtrSwap)
{
    yame::ytl::unique_ptr<int> foo1 = yame::ytl::make_unique<int>(10);
    yame::ytl::unique_ptr<int> foo2 = yame::ytl::make_unique<int>(20);

    CHECK_EQUAL(10, *foo1);
    CHECK_EQUAL(20, *foo2);

    foo1 = yame::mpl::move(foo2);

    CHECK_EQUAL(20, *foo1);
    CHECK_EQUAL(true, foo2 == null_ptr);
}

TEST(UniquePtrAssignNull)
{
    yame::ytl::unique_ptr<int> foo = yame::ytl::make_unique<int>(10);

    CHECK_EQUAL(10, *foo);

    foo = null_ptr;

    CHECK_EQUAL(true, foo == null_ptr);
}

TEST(TypeInfoTest)
{
    yame::rtti::TypeInfo fooTypeInfo[15] = { yame::rtti::getTypeInfo<C>(),
                                            yame::rtti::getTypeInfo<C1>(),
                                            yame::rtti::getTypeInfo<C2>(),
                                            yame::rtti::getTypeInfo<C3>(),
                                            yame::rtti::getTypeInfo<C4>(),
                                            yame::rtti::getTypeInfo<C5>(),
                                            yame::rtti::getTypeInfo<C6>(),
                                            yame::rtti::getTypeInfo<C7>(),
                                            yame::rtti::getTypeInfo<C8>(),
                                            yame::rtti::getTypeInfo<C9>(),
                                            yame::rtti::getTypeInfo<C10>(),
                                            yame::rtti::getTypeInfo<C11>(),
                                            yame::rtti::getTypeInfo<C12>(),
                                            yame::rtti::getTypeInfo<C13>(),
                                            yame::rtti::getTypeInfo<C14>() };

//    size_t fooPrime[16] = { yame::rtti::detail::get_bases_prime_id<C,C::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C1,C1::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C2,C2::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C3,C3::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C4,C4::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C5,C5::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C6,C6::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C7,C7::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C8,C8::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C9,C9::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C10,C10::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C11,C11::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C12,C12::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C13,C13::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C14,C14::rtti_base>::value,
//                            yame::rtti::detail::get_bases_prime_id<C15,C15::rtti_base>::value };

    yame::container::string typeInfoName = fooTypeInfo[0].getName();
}

TEST(UniquePtrCtoC1DynamicCast)
{
    yame::ytl::unique_ptr<C1> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());
    CHECK_EQUAL(8,foo1->getC8());
    CHECK_EQUAL(9,foo1->getC9());
    CHECK_EQUAL(10,foo1->getC10());

    yame::ytl::unique_ptr<C> foo2 = yame::ytl::dynamic_unique_cast<C>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrCtoC2DynamicCast)
{
    const C* __foo1 = nullptr;
    const C2* __foo2 = reinterpret_cast<const C2*>(__foo1);

    yame::ytl::unique_ptr<C2> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(11,foo1->getC11());
    CHECK_EQUAL(12,foo1->getC12());
    CHECK_EQUAL(13,foo1->getC13());
    CHECK_EQUAL(14,foo1->getC14());

    if(yame::ytl::unique_ptr<C> foo2 = yame::ytl::dynamic_unique_cast<C>(yame::mpl::move(foo1)))
    {
        yame::ytl::unique_ref<C> foo2Ref = yame::ytl::promote_to_ref(yame::mpl::move(foo2));

        int& aValue = yame::rtti::access<int>(foo2Ref,"a");
        float& bValue = yame::rtti::access<float>(foo2Ref,"b");
        char& dValue = yame::rtti::access<char>(foo2Ref,"d");

        aValue += 10;

        c_member_visitor cVisitor;
        yame::rtti::visit_members(foo2Ref,cVisitor);

        CHECK_EQUAL(110,foo2Ref->getA());
        CHECK_EQUAL(7,foo2Ref->getC7());
        CHECK_EQUAL(8,foo2Ref->getC8());
        CHECK_EQUAL(9,foo2Ref->getC9());
        CHECK_EQUAL(10,foo2Ref->getC10());
        CHECK_EQUAL(11,foo2Ref->getC11());
        CHECK_EQUAL(12,foo2Ref->getC12());
        CHECK_EQUAL(13,foo2Ref->getC13());
        CHECK_EQUAL(14,foo2Ref->getC14());
    }
}

TEST(UniquePtrC3toC1DynamicCast)
{
    yame::ytl::unique_ptr<C3> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());
    CHECK_EQUAL(8,foo1->getC8());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC3toC2DynamicCast)
{
    yame::ytl::unique_ptr<C3> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());
    CHECK_EQUAL(8,foo1->getC8());

    yame::ytl::unique_ptr<C2> foo2 = yame::ytl::dynamic_unique_cast<C2>(yame::mpl::move(foo1));

    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC3toCDynamicCast)
{
    yame::ytl::unique_ptr<C3> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());
    CHECK_EQUAL(8,foo1->getC8());

    yame::ytl::unique_ptr<C> foo2 = yame::ytl::dynamic_unique_cast<C>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC4toC1DynamicCast)
{
    yame::ytl::unique_ptr<C4> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(9,foo1->getC9());
    CHECK_EQUAL(10,foo1->getC10());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC4toC2DynamicCast)
{
    yame::ytl::unique_ptr<C4> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(9,foo1->getC9());
    CHECK_EQUAL(10,foo1->getC10());

    yame::ytl::unique_ptr<C2> foo2 = yame::ytl::dynamic_unique_cast<C2>(yame::mpl::move(foo1));

    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC5toC2DynamicCast)
{
    yame::ytl::unique_ptr<C5> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(11,foo1->getC11());
    CHECK_EQUAL(12,foo1->getC12());

    yame::ytl::unique_ptr<C2> foo2 = yame::ytl::dynamic_unique_cast<C2>(yame::mpl::move(foo1));

    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC5toC1DynamicCast)
{
    yame::ytl::unique_ptr<C5> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(11,foo1->getC11());
    CHECK_EQUAL(12,foo1->getC12());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC6toC2DynamicCast)
{
    yame::ytl::unique_ptr<C6> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(13,foo1->getC13());
    CHECK_EQUAL(14,foo1->getC14());

    yame::ytl::unique_ptr<C2> foo2 = yame::ytl::dynamic_unique_cast<C2>(yame::mpl::move(foo1));

    CHECK_EQUAL(11,foo2->getC11());
    CHECK_EQUAL(12,foo2->getC12());
    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC6toC1DynamicCast)
{
    yame::ytl::unique_ptr<C6> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(13,foo1->getC13());
    CHECK_EQUAL(14,foo1->getC14());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC7toC1DynamicCast)
{
    yame::ytl::unique_ptr<C7> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC7toC6DynamicCast)
{
    yame::ytl::unique_ptr<C7> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());

    yame::ytl::unique_ptr<C6> foo2 = yame::ytl::dynamic_unique_cast<C6>(yame::mpl::move(foo1));

    CHECK_EQUAL(13,foo2->getC13());
    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC7toC14DynamicCast)
{
    yame::ytl::unique_ptr<C7> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());

    yame::ytl::unique_ptr<C14> foo2 = yame::ytl::dynamic_unique_cast<C14>(yame::mpl::move(foo1));

    CHECK_EQUAL(14,foo2->getC14());
}

TEST(UniquePtrC7toC10DynamicCast)
{
    yame::ytl::unique_ptr<C7> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(7,foo1->getC7());

    yame::ytl::unique_ptr<C10> foo2 = yame::ytl::dynamic_unique_cast<C10>(yame::mpl::move(foo1));

    CHECK_EQUAL(10,foo2->getC10());
}

TEST(UniquePtrC13toC15DynamicCast)
{
    yame::ytl::unique_ptr<C13> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(13,foo1->getC13());

    yame::ytl::unique_ptr<C15> foo2 = yame::ytl::dynamic_unique_cast<C15>(yame::mpl::move(foo1));

    CHECK_EQUAL(15,foo2->getC15());
}

TEST(UniquePtrC14toC1DynamicCast)
{
    yame::ytl::unique_ptr<C14> foo1 = yame::ytl::make_unique<C>(7,8,9,10,11,12,13,14);

    CHECK_EQUAL(14,foo1->getC14());

    yame::ytl::unique_ptr<C1> foo2 = yame::ytl::dynamic_unique_cast<C1>(yame::mpl::move(foo1));

    CHECK_EQUAL(7,foo2->getC7());
    CHECK_EQUAL(8,foo2->getC8());
    CHECK_EQUAL(9,foo2->getC9());
    CHECK_EQUAL(10,foo2->getC10());
}
//TEST(UniquePtrNullDynamicCast)
//{
//    yame::ytl::unique_ptr<A> foo1(new C(10,10));
//
//    CHECK_EQUAL(10, foo1->getA());
//
//    yame::ytl::unique_ptr<C> foo2 = yame::ytl::dynamic_unique_cast<C>(yame::mpl::move(foo1));
//
//    CHECK_EQUAL(10, foo2->getB());
//}
//
//TEST(UniquePtrDynamicCast)
//{
//    yame::ytl::unique_ptr<A> foo1(new C(10,10));
//
//    CHECK_EQUAL(10, foo1->getA());
//
//    yame::ytl::unique_ptr<B> foo2 = yame::ytl::dynamic_unique_cast<B>(yame::mpl::move(foo1));
//
//    CHECK_EQUAL(10, foo2->getB());
//    CHECK_EQUAL(true, foo1 == null_ptr);
//}

//TEST(UniqueRefDynamicCast)
//{
//    yame::ytl::unique_ref<A> foo1(new B(10));
//
//    CHECK_EQUAL(10, foo1->getA());
//
//    yame::ytl::unique_ptr<B> foo2 = yame::ytl::dynamic_unique_cast<B>(yame::mpl::move(foo1));
//
//    CHECK_EQUAL(10, foo2->getA());
//    CHECK_EQUAL(true, foo1 == null_ptr);
//}
//
//TEST(UniquePtrConstCast)
//{
//    yame::ytl::unique_ptr<const A> foo1(new B(10));
//
//    CHECK_EQUAL(10, foo1->getA());
//
//    yame::ytl::unique_ptr<A> foo2 = yame::ytl::const_unique_cast<A>(yame::mpl::move(foo1));
//
//    CHECK_EQUAL(10, foo2->getA());
//    CHECK_EQUAL(true, foo1 == null_ptr);
//}
//
//TEST(UniqueRefConstCast)
//{
//    yame::ytl::unique_ref<const A> foo1(new B(10));
//
//    CHECK_EQUAL(10, foo1->getA());
//
//    yame::ytl::unique_ref<A> foo2 = yame::ytl::const_unique_cast<A>(yame::mpl::move(foo1));
//
//    CHECK_EQUAL(10, foo2->getA());
//    CHECK_EQUAL(true, foo1 == null_ptr);
//}
//
//TEST(UniquePtrAccess)
//{
//    yame::ytl::unique_ptr<A> foo(new B(10));
//
//    CHECK_EQUAL(10, foo->getA());
//}
//
//TEST(RefPtrCtr)
//{
//    yame::ytl::lent_ptr<int> foo;
//}
//
//TEST(RefPtrReference)
//{
//    yame::ytl::unique_ptr<int> foo = yame::ytl::make_unique<int>(10);
//
//    {
//        yame::ytl::lent_ptr<int> refFoo = foo;
//
//        CHECK_EQUAL(10, *refFoo);
//    }
//}
//
//TEST(RefPtrPromotion)
//{
//    yame::ytl::unique_ptr<int> foo = yame::ytl::make_unique<int>(10);
//    yame::ytl::lent_ptr<int> refFoo1;
//
//    refFoo1 = foo;
//
//    CHECK_EQUAL(10, *refFoo1);
//
//    yame::ytl::lent_ref<int> refFoo2 = yame::ytl::promote_to_ref(refFoo1);
//
//    CHECK_EQUAL(10, *refFoo1);
//    CHECK_EQUAL(10, *refFoo2);
//}
//
//TEST(RefPtrNullStaticCast)
//{
//    yame::ytl::lent_ptr<A> refFoo1;
//
//    CHECK_EQUAL(true, refFoo1 == null_ptr);
//
//    yame::ytl::lent_ptr<B> refFoo2 = yame::ytl::static_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(true, refFoo2 == null_ptr);
//}
//
//TEST(RefPtrStaticCast)
//{
//    yame::ytl::unique_ref<A> foo(new B(10));
//    yame::ytl::lent_ptr<A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ptr<B> refFoo2 = yame::ytl::static_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefStaticCast)
//{
//    yame::ytl::unique_ref<A> foo(new B(10));
//    yame::ytl::lent_ref<A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ref<B> refFoo2 = yame::ytl::static_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefPtrNullDynamicCast)
//{
//    yame::ytl::lent_ptr<A> refFoo1;
//
//    CHECK_EQUAL(true, refFoo1 == null_ptr);
//
//    yame::ytl::lent_ptr<B> refFoo2 = yame::ytl::dynamic_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(true, refFoo2 == null_ptr);
//}
//
//TEST(RefPtrDynamicCast)
//{
//    yame::ytl::unique_ref<A> foo(new B(10));
//    yame::ytl::lent_ptr<A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ptr<B> refFoo2 = yame::ytl::dynamic_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefDynamicCast)
//{
//    yame::ytl::unique_ref<A> foo(new B(10));
//    yame::ytl::lent_ref<A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ptr<B> refFoo2 = yame::ytl::dynamic_lent_cast<B>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefPtrNullConstCast)
//{
//    yame::ytl::lent_ptr<const A> refFoo1;
//
//    CHECK_EQUAL(true, refFoo1 == null_ptr);
//
//    yame::ytl::lent_ptr<A> refFoo2 = yame::ytl::const_lent_cast<A>(refFoo1);
//
//    CHECK_EQUAL(true, refFoo2 == null_ptr);
//}
//
//TEST(RefPtrConstCast)
//{
//    yame::ytl::unique_ref<const A> foo(new B(10));
//    yame::ytl::lent_ptr<const A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ptr<A> refFoo2 = yame::ytl::const_lent_cast<A>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefConstCast)
//{
//    yame::ytl::unique_ref<const A> foo(new B(10));
//    yame::ytl::lent_ref<const A> refFoo1 = foo;
//
//    CHECK_EQUAL(10, refFoo1->getA());
//
//    yame::ytl::lent_ref<A> refFoo2 = yame::ytl::const_lent_cast<A>(refFoo1);
//
//    CHECK_EQUAL(10, refFoo2->getA());
//}
//
//TEST(RefPtrMultipleReference)
//{
//    typedef yame::ytl::lent_ptr<int> refInt;
//    static const size_t maxIndex = 1000;
//    refInt refFoo[maxIndex];
//    yame::ytl::unique_ptr<int> foo = yame::ytl::make_unique<int>(10);
//
//    {
//        for(size_t refIndex=0;refIndex<maxIndex;refIndex++)
//        {
//            refFoo[refIndex] = foo;
//        }
//
//        for(size_t refIndex=0;refIndex<maxIndex;refIndex++)
//        {
//            CHECK_EQUAL(10, *refFoo[refIndex]);
//        }
//
//        for(size_t refIndex=0;refIndex<maxIndex;refIndex++)
//        {
//            refFoo[refIndex].release();
//        }
//    }
//}



}



