#ifndef AccelerometerDriver_h
#define AccelerometerDriver_h
#include <stdbool.h>

typedef struct AccelerometerDriver AccelerometerDriver;
typedef void (*AccelerometerDriver_mainFun)(AccelerometerDriver * const self);

struct AccelerometerDriver {
    AccelerometerDriver_mainFun main;
    bool volatile isDataAvailable;
};

AccelerometerDriver * AccelerometerDriver_init(
    AccelerometerDriver * const self, AccelerometerDriver_mainFun const main
);
void AccelerometerDriver_dataAvailableInt(AccelerometerDriver * const self);
void AccelerometerDriver_main(AccelerometerDriver * const self);

#endif // AccelerometerDriver_h
