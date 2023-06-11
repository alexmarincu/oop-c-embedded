#include "os_Interrupts.h"
#include "../acc_driver/AccDriver.h"
#include "../acc_driver/ActualAccDriver.h"
#include "../acc_driver/ActualAccSimDriver.h"
#include "../button_driver/ButtonDriver.h"

void os_Interrupts_accDataAvailable(void) {
    AccDriver_dataAvailableInt((AccDriver *)ActualAccDriver_getInstance());
}

void os_Interrupts_simAccDataAvailable(void) {
    AccDriver_dataAvailableInt((AccDriver *)ActualAccSimDriver_getInstance());
}

void os_Interrupts_buttonPress(void) {
    ButtonDriver_buttonPressInt(ButtonDriver_getInstance());
}
