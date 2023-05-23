#include "uart_rx.h"

void uart_rx(ap_uint<1> rx, ap_uint<1>* rx_valid, ap_uint<8>* rx_data){
#pragma HLS INTERFACE ap_none port=rx_data
#pragma HLS INTERFACE ap_none port=rx_valid
#pragma HLS INTERFACE ap_none port=rx
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return


	static states state = st_idle;
	static ap_uint<32> counter  = 0;
	static ap_uint<32> bit_counter  = 0;
	static ap_uint<1> rx_prev = 1;
	static ap_uint<1> valid = 0;
	static ap_uint<8> data_reg = 0;

	switch(state){
	case st_idle:
		valid = 0;
		counter = 0;
		bit_counter = 0;
		if(rx == 0){
			state = st_start;
		}else{
			state = st_idle;
		}
		break;
	case st_start:
		if(counter == HalfCounterlim){
			state = st_receive;
			counter = 0;
		}else{
			counter++;
		}

		break;
	case st_receive:
		if(bit_counter == 7){
			if(counter == counterlim){
				data_reg[bit_counter] = rx;
				bit_counter = 0;
				counter = 0;
				valid = 1;
				state = st_stop;
			}else{
				counter++;
			}
		}else{
			if(counter == counterlim){
				data_reg[bit_counter] = rx;
				bit_counter++;
				counter = 0;
			}else{
				counter++;
			}
		}

		break;
	case st_stop:
		valid = 0;
		if(counter == counterlim + HalfCounterlim){
			state = st_idle;
			counter = 0;
		}else{
			counter++;
		}
		break;
	default:
		break;

	}

	*rx_data = data_reg;
	*rx_valid = valid;
}
