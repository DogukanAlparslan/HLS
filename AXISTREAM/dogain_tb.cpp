#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <stdio.h>

typedef ap_axis<32,1,1,1> intSdch;

void doGain(hls::stream<intSdch> &inStream, hls::stream<intSdch> &outStream, int gain);


int main(){

	hls::stream<intSdch> inStream;
	hls::stream<intSdch> outStream;
	int gain= 5;

	for(int i = 0; i<1000 ; i++){

		intSdch valIn;

		valIn.data = i;
		valIn.dest= 0; valIn.strb= 1; valIn.user= 1; valIn.keep = 1;

		inStream << valIn;
	}

	doGain(inStream,outStream,gain);

	for(int i = 0; i<1000 ; i++){

			intSdch valOut;
			outStream.read(valOut);
			printf("value %d\n",(int) valOut.data);
		}



	return 0;
}
