#include "seven_segment_driver.h"


typedef enum {st1,st2,st3,st4} display_st;

void seven_segment_driver(bool refresh_signal,ap_uint<4> first_dig,ap_uint<4> second_dig,ap_uint<4> third_dig,
						  ap_uint<4> fourth_dig,ap_uint<8>* seven_seg_data,ap_uint<4>* enable){
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=enable
#pragma HLS INTERFACE ap_none port=seven_seg_data
#pragma HLS INTERFACE ap_none port=fourth_dig
#pragma HLS INTERFACE ap_none port=third_dig
#pragma HLS INTERFACE ap_none port=second_dig
#pragma HLS INTERFACE ap_none port=first_dig
#pragma HLS INTERFACE ap_none port=refresh_signal
#pragma HLS INTERFACE ap_ctrl_none port=return


	static display_st state =st1;
#pragma HLS RESET variable=state

	switch(state){
		case st1:
			*seven_seg_data = seven_segment[first_dig];
			*enable = 0x1;

			if(refresh_signal){
				state = st2;
			}else{
				state = st1;
			}

			break;
		case st2:
			*seven_seg_data = seven_segment[second_dig];
			*enable = 0x2;

			if(refresh_signal){
				state = st3;
			}else{
				state = st2;
			}

			break;
		case st3:
			*seven_seg_data = seven_segment[third_dig];
			*enable = 0x4;

			if(refresh_signal){
				state = st4;
			}else{
				state = st3;
			}

			break;
		case st4:
			*seven_seg_data = seven_segment[fourth_dig];
			*enable = 0x8;

			if(refresh_signal){
				state = st1;
			}else{
				state = st4;
			}

			break;
		default:
			break;
	}
}
