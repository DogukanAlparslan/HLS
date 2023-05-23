#include "uart_tb.h"


int main(){
	ap_uint<1> uart_en = 0;
	ap_uint<8> data=0x00;
	ap_uint<1> uart_tx;
	ap_uint<1> tx_valid;
	ap_uint<8> data_out;

	for(int i = 0;i<50;i++){uart(uart_en,data,&uart_tx,&tx_valid,&data_out);};
	uart_en = 1;
	data = 0x7A;
	std::cout << "Before UART Transmission Data = " << data << std::endl;

	while(tx_valid == 0){
		uart(uart_en,data,&uart_tx,&tx_valid,&data_out);
		uart_en = 0;
	}

	std::cout << "After UART Transmission Data = " << data_out << std::endl;

	for(int i = 0;i<50;i++){uart(uart_en,data,&uart_tx,&tx_valid,&data_out);};

	uart_en = 1;
	data = 0x43;
	std::cout << "Before UART Transmission Data = " << data << std::endl;

	while(tx_valid == 0){
		uart(uart_en,data,&uart_tx,&tx_valid,&data_out);
		uart_en = 0;
	}

	std::cout << "After UART Transmission Data = " << data_out << std::endl;

	for(int i = 0;i<10;i++){uart(uart_en,data,&uart_tx,&tx_valid,&data_out);};

	uart_en = 1;
	data = 0xFF;
	std::cout << "Before UART Transmission Data = " << data << std::endl;

	while(tx_valid == 0){
		uart(uart_en,data,&uart_tx,&tx_valid,&data_out);
		uart_en = 0;
	}

	std::cout << "After UART Transmission Data = " << data_out << std::endl;

	for(int i = 0;i<50;i++){uart(uart_en,data,&uart_tx,&tx_valid,&data_out);};

	uart_en = 1;
	data = 0x00;
	std::cout << "Before UART Transmission Data = " << data << std::endl;

	while(tx_valid == 0){
		uart(uart_en,data,&uart_tx,&tx_valid,&data_out);
		uart_en = 0;
	}

	std::cout << "After UART Transmission Data = " << data_out << std::endl;

	for(int i = 0;i<10;i++){uart(uart_en,data,&uart_tx,&tx_valid,&data_out);};

	return 0;
}
