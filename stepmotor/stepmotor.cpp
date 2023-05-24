#include "stepmotor.h"

void stepmotor(ap_uint<1> en, ap_uint<1> direction, ap_uint<4>* signals){
#pragma HLS INTERFACE ap_none port=signals
#pragma HLS INTERFACE ap_none port=direction
#pragma HLS INTERFACE ap_none port=en
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS PIPELINE


	static ap_uint<32> counter = 0;
	static states state = st0;
	static ap_uint<4> out = 0;

	switch(state){
	case st0:
		if(en == 1){
			out = 0x1;
			if(direction == 1){
				state = st1;
			}else{
				state = st3;
			}
		}else{
			state = st0;
		}
		break;
	case st1:
		if(en == 1){
			out = 0x2;
			if(direction == 1){
				state = st2;
			}else{
				state = st0;
			}
		}else{
			state = st1;
		}
		break;
	case st2:
		if(en == 1){
			out = 0x4;
			if(direction == 1){
				state = st3;
			}else{
				state = st1;
			}
		}else{
			state = st2;
		}
		break;
	case st3:
		if(en == 1){
			out = 0x8;
			if(direction == 1){
				state = st0;
			}else{
				state = st2;
			}
		}else{
			state = st3;
		}
		break;
	default:
		break;
	}
	*signals = out;
}
