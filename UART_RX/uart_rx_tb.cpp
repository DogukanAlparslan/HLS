#include "uart_rx_tb.h"


int main(){
	ap_uint<1> rx= 1;
	ap_uint<1> rx_valid;
	ap_uint<8> rx_data;
	ap_uint<8> bit_counter = 0;
	ap_uint<32> counter = 0;
	ap_uint<8> tx_data = 0;

	for(int i=0; i< 50;i++){uart_rx(rx,&rx_valid,&rx_data);};

	std::cout << "Before UART RECIEVE DATA = " <<rx_data << std::endl;
	tx_data = 0xAA;
	rx= 0;
	while(bit_counter < 10){
		uart_rx(rx,&rx_valid,&rx_data);
		if(bit_counter >= 8){
			if(counter == counterlim){
				counter = 0;
				rx = 1;
				bit_counter++;
			}else{
				counter++;
			}
		}else{
			if(counter == counterlim){
				counter = 0;
				rx = tx_data[bit_counter];
				bit_counter++;
			}else{
				counter++;
			}
		}
	}
	rx= 1;
	bit_counter = 0;

	std::cout << "After UART RECIEVE DATA = " <<rx_data << std::endl;
	for(int i=0; i< 50;i++){uart_rx(rx,&rx_valid,&rx_data);};

	std::cout << "Before UART RECIEVE DATA = " <<rx_data << std::endl;
	tx_data = 0xFF;
	rx= 0;
	while(bit_counter < 10){
		uart_rx(rx,&rx_valid,&rx_data);
		if(bit_counter >= 8){
			if(counter == counterlim){
				counter = 0;
				rx = 1;
				bit_counter++;
			}else{
				counter++;
			}
		}else{
			if(counter == counterlim){
				counter = 0;
				rx = tx_data[bit_counter];
				bit_counter++;
			}else{
				counter++;
			}
		}
	}
	rx= 1;
	bit_counter = 0;

	std::cout << "After UART RECIEVE DATA = " <<rx_data << std::endl;
	for(int i=0; i< 50;i++){uart_rx(rx,&rx_valid,&rx_data);};

	std::cout << "Before UART RECIEVE DATA = " <<rx_data << std::endl;
	tx_data = 0x38;
	rx= 0;

	while(bit_counter < 10){
		uart_rx(rx,&rx_valid,&rx_data);
		if(bit_counter >= 8){
			if(counter == counterlim){
				counter = 0;
				rx = 1;
				bit_counter++;
			}else{
				counter++;
			}
		}else{
			if(counter == counterlim){
				counter = 0;
				rx = tx_data[bit_counter];
				bit_counter++;
			}else{
				counter++;
			}
		}
	}
	rx= 1;
	bit_counter = 0;

	std::cout << "After UART RECIEVE DATA = " <<rx_data << std::endl;
	for(int i=0; i< 50;i++){uart_rx(rx,&rx_valid,&rx_data);};
	return 0;
}
