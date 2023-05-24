#include "ap_int.h"

#define clock_freq 100000000
#define motor_freq 1000

#define counterLim (clock_freq/motor_freq)-1

typedef enum {st0,st1,st2,st3} states;
