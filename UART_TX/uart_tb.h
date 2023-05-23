#include "uart.h"
#include <iostream>


void uart(ap_uint<1> uart_en, ap_uint<8> data, ap_uint<1>* uart_tx,ap_uint<1>* tx_valid,ap_uint<8>* data_out);
