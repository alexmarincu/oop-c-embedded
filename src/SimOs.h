#ifndef SimOs_h
#define SimOs_h
#include <stdint.h>

typedef struct SimOs SimOs;

SimOs * SimOs_getInstance(void);
SimOs * SimOs_init(SimOs * const self);
void SimOs_main(SimOs * const self);

#endif // SimOs_h
