#include "debouncer.h"

void debouncer(u1 pulse, u1* out)
{
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=out
#pragma HLS INTERFACE ap_none port=pulse
#pragma HLS INTERFACE ap_ctrl_none port=return

	static int counter = 0;
	static u1 out_reg = 0;
	static states debounce= st_idle;

	switch(debounce){
		case st_idle:
			counter = 0;
			out_reg = 0;
			if(pulse == 1){
				debounce = st_count;
			}else{
				debounce = st_idle;
			}
			break;
		case st_count:
			if(counter == period/counterLim-1){
				counter = 0;
				out_reg = 1;
				debounce = st_idle;
			}else{
				counter += 1;
				debounce = st_count;
			}
			break;
		default:
			break;
	}
	*out = out_reg;
}
