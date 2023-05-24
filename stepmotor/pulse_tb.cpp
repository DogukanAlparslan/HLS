#include "pulse_tb.h"


int main(){
	ap_uint<1> en= 0;
	ap_uint<1> pulse;

	for(int i= 0; i<10000;i++){
		pulse_gen(en,&pulse);
		en= 1;
		std::cout << "Pulse = " << pulse << std::endl;
	}
	return 0;
}
