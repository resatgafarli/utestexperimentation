/******************************************************
Author: resat.gafarli@gmail.com
File: tst_ldaf.h
Date: 6/7/2017
License: GPL-3.0
*******************************************************/
#ifndef TST_LDAF_H
#define TST_LDAF_H
#include "gmock/gmock.h"
#include "ldafbase.h"
#define private public
#define proteced public

class MockLDAFMessageType: public LDAFMessageType{
public:
  explicit MockLDAFMessageType(LDAFBase*base,QObject*funcobj,QString funcName):
  LDAFMessageType(base,funcobj,funcName)
  {}
  MOCK_METHOD0(setMessage,void());  
};

#endif // TST_LDAF_H
