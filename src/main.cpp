#include <iostream>

#include "gmock/gmock.h"  // Brings in Google Mock.

struct A {
    A():val(10){

    }
    int getVal(){
        return val;
    }
private:
    int val;
};


struct B{

    A b;

    int getBVal(){
        return b.getVal();
    }

};

struct MockB: public B{
    MOCK_METHOD0(getBVal,int());
};

TEST(ExampleMocTest, DependencyMocking) {

    MockB b;
    EXPECT_EQ(10,b.getBVal());

}


int main(int argc, char * argv[]){
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
	return 0;
}
