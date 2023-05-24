#include "stepmotor_tb.h"

int main(){
	ap_uint<1> en = 0;
	ap_uint<1> direction = 0;
	ap_uint<4> signals;

	for(int i = 0;i< 20; i++){
		if(direction == 0){
			 direction = 1;
		}else{
			 direction = 0;
		}
		for(int j=0;j<10;j++){
			stepmotor(en,direction,&signals);
			std::cout<<"Signals = " << signals << " Direction = " << direction<< std::endl;
		}
		en = 1;
	}
	return 0;
}
