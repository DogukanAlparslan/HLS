#include "math.h"


void math(ap_uint<WIDTH> a,ap_uint<WIDTH> b,ap_uint<2> mode,ap_uint<16>* out){
#pragma HLS INTERFACE ap_none port=out
#pragma HLS INTERFACE ap_none port=mode
#pragma HLS INTERFACE ap_none port=b
#pragma HLS INTERFACE ap_none port=a
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return

	switch(mode){
		case 0:// adder
			*out = a+b;
			break;
		case 1:// subtraction
			if(a>=b){
				*out = a-b;
			}else{
				*out = b-a;
			}
			break;
		case 2:// Multiplication
				*out = a*b;
			break;
		case 3:// Divider
			if(a>=b){
				*out = a/b;
			}else{
				*out = b/a;
			}
			break;
		default:
			break;
	}

}
