#include "pulse.h"

void pulse_gen(ap_uint<1> en, ap_uint<1>* pulse){
#pragma HLS INTERFACE ap_none port=pulse
#pragma HLS INTERFACE ap_none port=en
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return


	static ap_uint<32> counter = 0;
	static ap_uint<1> out = 0;

	if(en == 1){
		if(counter == counterLim){
			counter = 0;
			out = 1;
		}else{
			counter++;
			out = 0;
		}
	}else{
		out = 0;
		counter = 0;
	}
	*pulse = out;
}
