#include "seven_segment_refresh_signal_tb.h"


int main(){

	int status=0;

	bool out_signal;

	for(int i = 0; i<10*REFRESH_PERIOD;i++){
		seven_segment_refresh_signal(&out_signal);
		std::cout<< out_signal<< std::endl;
	}

	return status;
}
