#include "Os_Interrupts.h"
#include "AccConfig.h"
#include "RealAccDriver.h"
#include "SimAccDriver.h"

void Os_Interrupts_realAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)RealAccDriver_getInstance());
}

void Os_Interrupts_simAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)SimAccDriver_getInstance());
}

void Os_Interrupts_buttonPress(void) {
    AccConfig_toggleAccDriver(AccConfig_getInstance());
}
