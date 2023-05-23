#pragma once

#include "ap_int.h"

#define period 100000000
#define baudrate 115200

#define counterlim (period/baudrate)-1
#define HalfCounterlim ((period/baudrate)/2)-1

typedef enum {st_idle,st_start,st_receive,st_stop} states;
