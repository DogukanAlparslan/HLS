#include "seven_segment_refresh_signal.h"

void seven_segment_refresh_signal(bool* out){
#pragma HLS INTERFACE ap_none port=out
#pragma HLS INTERFACE ap_ctrl_none port=return

	static int counter = 0;

	if(counter == REFRESH_PERIOD-1){
		*out = 1;
		counter = 0;
	}else{
		*out = 0;
		counter = counter + 1;
	}

}
