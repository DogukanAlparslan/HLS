#include "lfsr.h"

void lfsr(ap_uint<4> seed,ap_uint<1> load, ap_uint<4>* data){
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_none port=data
#pragma HLS INTERFACE ap_none port=load
#pragma HLS INTERFACE ap_none port=seed
#pragma HLS INTERFACE ap_ctrl_none port=return

	static ap_uint<4> poly = 10;
	static bool num;

	if(load == 1) {
		poly = seed;
	}
	num = poly[1] ^ poly[0];
	poly = poly >> 1;
	poly[3] = num;

	*data = poly ;

}
