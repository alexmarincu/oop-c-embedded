#ifndef DefaultButtonDriver_h
#define DefaultButtonDriver_h
#include "ButtonDriver.h"

typedef struct DefaultButtonDriver DefaultButtonDriver;

DefaultButtonDriver * DefaultButtonDriver_getInstance(void);
DefaultButtonDriver * DefaultButtonDriver_init(DefaultButtonDriver * const self);

#endif // DefaultButtonDriver_h
