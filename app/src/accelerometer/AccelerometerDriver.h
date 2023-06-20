#ifndef AccelerometerDriver_h
#define AccelerometerDriver_h
#include <stdbool.h>

typedef struct AccelerometerDriver AccelerometerDriver;
typedef void (*AccelerometerDriver_runFun)(AccelerometerDriver * const self);

struct AccelerometerDriver {
    AccelerometerDriver_runFun run;
    bool volatile isDataAvailable;
};

AccelerometerDriver * AccelerometerDriver_init(
    AccelerometerDriver * const self, AccelerometerDriver_runFun const run
);
void AccelerometerDriver_dataAvailableInt(AccelerometerDriver * const self);
void AccelerometerDriver_run(AccelerometerDriver * const self);

#endif // AccelerometerDriver_h
