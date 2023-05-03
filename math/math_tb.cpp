#include "math_tb.h"


int main(){

	ap_uint<WIDTH> a;
	ap_uint<WIDTH> b;
	ap_uint<2> mode;
	ap_uint<16> out;

	for(int i = 0; i < 20; i++){
		a = rand();
		b = rand();
		mode = rand();
		math(a,b,mode,&out);
		printf("Mode : %0d  ,  a : %0d ,  b : %0d  , out : %0d\n",int(mode),int(a),int(b),int(out));
	}


	return 0;
}
