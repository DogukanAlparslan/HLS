#include "timer.h"


void timer(ap_uint<4>* first_dig,ap_uint<4>* second_dig,ap_uint<4>* third_dig,ap_uint<4>* fourth_dig){
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=fourth_dig
#pragma HLS INTERFACE ap_none port=third_dig
#pragma HLS INTERFACE ap_none port=second_dig
#pragma HLS INTERFACE ap_none port=first_dig
#pragma HLS INTERFACE ap_ctrl_none port=return

	static ap_uint<32> counter=0;

	static ap_uint<4> local_first = 0;
	static ap_uint<4> local_second = 0;
	static ap_uint<4> local_third = 0;
	static ap_uint<4> local_fourth = 0;


	if(counter == PERIOD-1){
		counter = 0;
		if(local_fourth == 9){
			local_fourth = 0;
			if(local_third == 5){
				local_third = 0;
				if(local_second == 9){
					local_second= 0;
					if(local_first== 5){
						local_first = 0;
					}else{
						local_first = local_first + 1;
					}
				}else{
					local_second = local_second + 1;
				}
			}else{
				local_third = local_third + 1;
			}
		}else{
			local_fourth = local_fourth + 1;
		}

	}else{
		counter = counter + 1;
	}

	*first_dig	= local_first;
	*second_dig = local_second;
	*third_dig 	= local_third;
	*fourth_dig = local_fourth;

}
