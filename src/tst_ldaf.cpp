#include "tst_ldaf.h"

using ::testing::AtLeast;
TEST(LDAFMessageTypeTest, LDAFMessageTypeConstruction){
    MockLDAFMessageType ldafMessage(nullptr,nullptr,"testFunction");
    EXPECT_CALL(ldafMessage, setMessage()).Times(AtLeast(1));
    ldafMessage.setMessage();
    EXPECT_EQ(ldafMessage.getBasicObject(),nullptr);
    EXPECT_EQ(ldafMessage.getCallBackObject(),nullptr);
    EXPECT_EQ(ldafMessage.getCallBackJSFunc(),"testFunction");    
}