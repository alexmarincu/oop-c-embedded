#ifndef RealAccelDriver_h
#define RealAccelDriver_h
#include "AccelDriver.h"

typedef struct RealAccelDriver RealAccelDriver;

RealAccelDriver * RealAccelDriver_init(RealAccelDriver * const self);
RealAccelDriver * RealAccelDriver_getInstance(void);

#endif // RealAccelDriver_h
