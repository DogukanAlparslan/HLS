
#include "seven_segment_driver.h"
#include "iostream"

void seven_segment_driver(bool refresh_signal,ap_uint<4> first_dig,ap_uint<4> second_dig,ap_uint<4> third_dig,
						  ap_uint<4> fourth_dig,ap_uint<8>* seven_seg_data,ap_uint<4>* enable);

