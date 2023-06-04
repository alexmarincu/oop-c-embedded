#ifndef SimAccelDriver_h
#define SimAccelDriver_h
#include "AccelDriver.h"

typedef struct SimAccelDriver SimAccelDriver;

SimAccelDriver * SimAccelDriver_init(SimAccelDriver * const self);
SimAccelDriver * SimAccelDriver_getInstance(void);

#endif // SimAccelDriver_h
