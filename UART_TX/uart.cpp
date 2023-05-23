#include "uart.h"

void uart(ap_uint<1> uart_en, ap_uint<8> data, ap_uint<1>* uart_tx,ap_uint<1>* tx_valid,ap_uint<8>* data_out){
#pragma HLS INTERFACE ap_none port=data_out
#pragma HLS INTERFACE ap_none port=tx_valid
#pragma HLS INTERFACE ap_none port=uart_tx
#pragma HLS INTERFACE ap_none port=data
#pragma HLS INTERFACE ap_none port=uart_en
#pragma HLS PIPELINE
#pragma HLS INTERFACE ap_ctrl_none port=return

	static states state = st_idle;
	static ap_uint<1> tx_reg = 1;
	static ap_uint<1> valid_reg = 0;
	static ap_uint<32> counter = 0;
	static ap_uint<32> bit_counter = 0;
	static ap_uint<8> uart_data = 0;
	static ap_uint<8> uart_data_out = 0;
	switch(state){
	case st_idle:
		valid_reg = 0;
		if(uart_en == 1){
			state = st_start;
			uart_data = data;
			tx_reg = 0;
			counter = 0;
			bit_counter = 0;
		}else{
			tx_reg = 1;
			state = st_idle;
			counter = 0;
			bit_counter = 0;
		}
		break;

	case st_start:
		if(counter == counterlim){
			tx_reg = uart_data[bit_counter];
			uart_data_out[bit_counter] = uart_data[bit_counter];
			bit_counter++;
			counter = 0;
			state = st_transmit;
		}else{
			counter++;
			tx_reg = 0;
		}
		break;

	case st_transmit:
		if(bit_counter==8){
			if(counter == counterlim){
				tx_reg = 1;
				bit_counter = 0;
				counter = 0;
				state = st_stop;
				valid_reg = 1;
			}else{
				counter++;
			}

		}else{
			if(counter == counterlim){
				tx_reg = uart_data[bit_counter];
				uart_data_out[bit_counter] = uart_data[bit_counter];
				bit_counter++;
				counter = 0;
			}else{
				counter++;
			}
		}
		break;

	case st_stop:
		valid_reg = 0;
		if(counter == counterlim){
			tx_reg = 1;
			bit_counter= 0;
			counter = 0;
			state = st_idle;
		}else{
			counter++;
		}
		break;

	default:
		break;
	}
	*data_out = uart_data_out;
	*uart_tx = tx_reg;
	*tx_valid = valid_reg;
}
