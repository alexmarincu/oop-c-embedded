#ifndef AccDriver_h
#define AccDriver_h
#include "../acc_ctrl/AccCtrl.h"
#include <stdbool.h>

typedef struct AccDriver AccDriver;
typedef void (*AccDriver_runFun)(AccDriver * const self);

struct AccDriver {
    AccCtrl * accCtrl;
    AccDriver_runFun run;
    bool isDataAvailable;
};

AccDriver * AccDriver_init(AccDriver * const self, AccCtrl * const accCtrl, AccDriver_runFun const run);
void AccDriver_dataAvailableInt(AccDriver * const self);
void AccDriver_run(AccDriver * const self);

#endif // AccDriver_h
