#pragma once

#include "ap_int.h"

typedef enum  {st_idle,st_count} states;

typedef ap_uint<1> u1;
#define period 100000000 // 100 MHz
#define counterLim 1000 // 1KHz
//#define counterLim 10000000// 10MHz
