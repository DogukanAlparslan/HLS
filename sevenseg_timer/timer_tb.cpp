#include "timer_tb.h"

int main(){

	ap_uint<4> first_dig;
	ap_uint<4> second_dig;
	ap_uint<4> third_dig;
	ap_uint<4> fourth_dig;

	for(int i = 0; i<5000; i++){
		timer(&first_dig,&second_dig,&third_dig,&fourth_dig);
		std::cout << first_dig<<second_dig<<":"<<third_dig<<fourth_dig<<std::endl;
	}


	return 0;
}
