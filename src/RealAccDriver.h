#ifndef RealAccDriver_h
#define RealAccDriver_h
#include "AccDriver.h"

typedef struct RealAccDriver RealAccDriver;

RealAccDriver * RealAccDriver_init(RealAccDriver * const self);
RealAccDriver * RealAccDriver_getInstance(void);

#endif // RealAccDriver_h
