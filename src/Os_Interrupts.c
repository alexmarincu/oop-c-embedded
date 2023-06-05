#include "Os_Interrupts.h"
#include "PlatformAccDriver.h"
#include "PlatformAccSimDriver.h"
#include "PlatformButtonDriver.h"

void Os_Interrupts_realAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)PlatformAccDriver_getInstance());
}

void Os_Interrupts_simAccDataAvailable(void) {
    AccDriver_onDataAvailableInt((AccDriver *)PlatformAccSimDriver_getInstance());
}

void Os_Interrupts_buttonPress(void) {
    ButtonDriver_onButtonPressInt((ButtonDriver *)PlatformButtonDriver_getInstance());
}
