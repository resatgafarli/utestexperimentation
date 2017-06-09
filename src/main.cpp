//#include "tst_experimentation.h"
#include "tst_ldaf.h"


int main(int argc, char * argv[]){
  deneme2 den;
  den.helloWord();
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
	return 0;
}
