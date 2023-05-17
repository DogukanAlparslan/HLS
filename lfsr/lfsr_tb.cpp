#include "lfsr_tb.h"


int main(){
	ap_uint<4> seed;
	ap_uint<1> load;
	ap_uint<4> data;
	int i = 0;
	seed = 15;
	while(i<100){
		lfsr(seed,load,&data);
		std::cout<< "Seed = "<< seed<< " load = " << load << " data = "<< data << std::endl;
		i += 1;
		if(i == 25){
			load = 1;
		}else{
			load = 0;
		}
	}

	return 0;
}
