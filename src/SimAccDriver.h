#ifndef SimAccDriver_h
#define SimAccDriver_h
#include "AccDriver.h"

typedef struct SimAccDriver SimAccDriver;

SimAccDriver * SimAccDriver_init(SimAccDriver * const self);
SimAccDriver * SimAccDriver_getInstance(void);

#endif // SimAccDriver_h
