#include "inverter.h"

void inverter(hls::stream<imgIn> &dataIn,hls::stream<imgIn> &dataOut,u32 size){
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=control
#pragma HLS INTERFACE axis register both port=dataOut
#pragma HLS INTERFACE axis register both port=dataIn

	imgIn streamDataIn;
	imgIn streamDataOut;

	for(u32 i = 0; i< size;i++){
		streamDataIn = dataIn.read();

		streamDataOut.data = 255 - streamDataIn.data;
		streamDataOut.keep = streamDataIn.keep;
		streamDataOut.last = streamDataIn.last;
		streamDataOut.strb = streamDataIn.strb;
		streamDataOut.user = streamDataIn.user;
		streamDataOut.id = streamDataIn.id;
		streamDataOut.dest = streamDataIn.dest;

		dataOut.write(streamDataOut);
	}
}
