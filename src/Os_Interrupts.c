#include "Os_Interrupts.h"
#include "DefaultButtonDriver.h"
#include "RealAccDriver.h"
#include "SimAccDriver.h"

void Os_Interrupts_realAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)RealAccDriver_getInstance());
}

void Os_Interrupts_simAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)SimAccDriver_getInstance());
}

void Os_Interrupts_buttonPress(void) {
    ButtonDriver_onButtonPressInt((ButtonDriver *)DefaultButtonDriver_getInstance());
}
