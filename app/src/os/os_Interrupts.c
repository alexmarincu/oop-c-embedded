#include "os_Interrupts.h"
#include "../accelerometer_driver/AccelerometerDriver.h"
#include "../accelerometer_driver/AccelerometerSimulatorDriver.h"
#include "../accelerometer_driver/RealAccelerometerDriver.h"
#include "../button_driver/ButtonDriver.h"

void os_Interrupts_accDataAvailable(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)RealAccelerometerDriver_getInstance());
}

void os_Interrupts_simAccelerometerDataAvailable(void) {
    AccelerometerDriver_dataAvailableInt((AccelerometerDriver *)AccelerometerSimulatorDriver_getInstance());
}

void os_Interrupts_buttonPress(void) {
    ButtonDriver_buttonPressInt(ButtonDriver_getInstance());
}
