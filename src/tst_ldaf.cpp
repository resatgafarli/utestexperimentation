#include "tst_ldaf.h"

using ::testing::AtLeast;
TEST(LdafTestCase, LDAFMessageTypeTest){
    MockLDAFMessageType ldafMessage;
    EXPECT_CALL(ldafMessage, setMessage()).Times(AtLeast(2));
    ldafMessage.setMessage();

    //EXPECT_EQ(ldafMessage.m_basicObject,nullptr);
    //EXPECT_EQ(ldafMessage.m_callBackObject,nullptr);
    //EXPECT_EQ(ldafMessage.m_callBackJSFunc,"");    
}