#pragma once

#include "ap_int.h"

#define period 100000000
#define baudrate 115200

#define counterlim (period/baudrate)-1

typedef enum {st_idle,st_start,st_transmit,st_stop} states;
