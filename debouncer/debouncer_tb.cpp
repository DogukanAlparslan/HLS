#include "debouncer_tb.h"


int main(){

	u1 pulse= 0;
	u1 out;

	debouncer(pulse,&out);
	std::cout << "PULSE = "<<pulse<< " OUT = " << out <<std::endl;
	for(int i = 0; i< 10 ; i++){
		pulse = 1;
		for(int j = 0; j < 20; j++){
			debouncer(pulse,&out);
			std::cout << "PULSE = "<<pulse<< " OUT = " << out <<std::endl;
			pulse = 0;

		}
	}
	std::cout << "PULSE = "<<pulse<< " OUT = " << out <<std::endl;
	return 0;
}
