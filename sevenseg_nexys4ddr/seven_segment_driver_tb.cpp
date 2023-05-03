#include "seven_segment_driver_tb.h"



int main(){

	bool refresh_signal = 0;
	ap_uint<4> first_dig= 2;
	ap_uint<4> second_dig= 4;
	ap_uint<4> third_dig= 6;
	ap_uint<4> fourth_dig= 8;
	ap_uint<8> seven_seg_data;
	ap_uint<4> seven_seg_en;

	for(int i = 0; i < 10 ;i++) {

		for(int j = 0; j < 5 ; j++){

			seven_segment_driver(refresh_signal,first_dig,second_dig,third_dig,fourth_dig,&seven_seg_data,&seven_seg_en);
			refresh_signal = 0;
			std::cout << seven_seg_en.to_string() << " , " << seven_seg_data.to_string()<<std::endl;
		}
		refresh_signal = 1;
	}
	return 0;
}
