#include <iostream>
#include "gmock/gmock.h"
#include "ldafbase.h"

/*---------- In Order To Access Private Data Members ---------------------*/
#define private public



/*-------------------------------- The class ---------------------------------------*/
struct AIntr {
    virtual int getVal() = 0;
};

struct A: public AIntr {
    A():val(10){}
    int getVal(){
        return val;
    }

private:
    int val;

};

/*---------------------------- The depended class -----------------------------------*/
struct BIntr{
    virtual int getVal() = 0;
};

template<typename T>
struct BTemp: public BIntr{
    BTemp(T& dependenClass):t(dependenClass){}
    int getVal(){
       int v =t.getVal();
       return ++v;
    }
private:
    T &t;
};


/*------------------------ The mock objects -------------------------------*/
struct MockA: public AIntr{
    MOCK_METHOD0(getVal,int());
};

/*------------------------ Tests --------------------------*/
TEST(AClassTest, GetAClassValue) {
    A a;

    EXPECT_EQ(10,a.val);//Access to private members
}

using ::testing::Return;
using ::testing::AtLeast;
TEST(BClassTest, GetBClassValue){
    MockA mockA;
    EXPECT_CALL(mockA,getVal()).
            Times(AtLeast(1)).
            WillRepeatedly(Return(100));

    //Production code declaration is "BTemp<A> B(realDependenObjectRefernece);"
    BTemp<MockA> b(mockA);

    EXPECT_EQ(101,b.getVal());
}

int main(int argc, char * argv[]){
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
	return 0;
}
