#include <hls_stream.h>
#include <ap_axi_sdata.h>

typedef ap_axis<32,1,1,1> intSdch;

void doGain(hls::stream<intSdch> &inStream, hls::stream<intSdch> &outStream, int gain){
#pragma HLS INTERFACE axis port= inStream
#pragma HLS INTERFACE axis port= outStream
#pragma HLS INTERFACE s_axilite port= gain bundle = CTRL_BUS
#pragma HLS INTERFACE s_axilite port= return bundle = CTRL_BUS

	for(int i = 0; i<1000;i++){
#pragma HLS PIPELINE
		intSdch valIn = inStream.read();
		intSdch valOut;

		valOut.data = valIn.data *gain;
		valOut.dest	= valIn.dest;
		valOut.id	= valIn.id;
		valOut.keep = valIn.keep;
		valOut.last = valIn.last;
		valOut.strb = valIn.strb;
		valOut.user = valIn.user;

		outStream.write(valOut);

	}

}
