#include "os_Scheduler.h"
#include "../accelerometer_configurator/AccelerometerConfigurator.h"
#include "../accelerometer_data_storage/AccelerometerConfigStorage.h"
#include "../accelerometer_driver/AccelerometerDriver.h"
#include "../accelerometer_driver/AccelerometerDriverProvider.h"
#include "../button_controller/ButtonCtrl.h"
#include "../button_driver/ButtonDriver.h"
#include "../lib/timer/Timer.h"
#include "../motion_detector/MotionDetector.h"
#include "os_Task.h"
#include "os_Time.h"

struct os_Scheduler {
    ButtonDriver * buttonDriver;
    AccelerometerDriverProvider * accelerometerDriverProvider;
    MotionDetector * motionDetector;
    os_Task tasks[4];
};

static void os_Scheduler_runAt10ms(os_Scheduler * const self) {
    (void)self;
}

static void os_Scheduler_runAt20ms(os_Scheduler * const self) {
    (void)self;
}

static void os_Scheduler_runAt50ms(os_Scheduler * const self) {
    (void)self;
    AccelerometerDriver_run(AccelerometerDriverProvider_getCurrentAccelerometerDriver(self->accelerometerDriverProvider));
    MotionDetector_run(self->motionDetector);
}

static void os_Scheduler_runAt100ms(os_Scheduler * const self) {
    ButtonDriver_run(self->buttonDriver);
}

os_Scheduler * os_Scheduler_getInstance(void) {
    static os_Scheduler self;
    return &self;
}

os_Scheduler * os_Scheduler_init(os_Scheduler * const self) {
    TimerClass_init(
        TimerClass_getInstance(),
        os_Time_getTimeSource(os_Time_init(os_Time_getInstance()))
    );
    os_TaskClass_init(os_TaskClass_getInstance());
    self->buttonDriver = ButtonDriver_init(
        ButtonDriver_getInstance(),
        ButtonCtrl_init(
            ButtonCtrl_getInstance(),
            AccelerometerConfigurator_init(
                AccelerometerConfigurator_getInstance(),
                AccelerometerConfigStorage_getAccelerometerConfigDao(
                    AccelerometerConfigStorage_init(AccelerometerConfigStorage_getInstance())
                )
            )
        )
    );
    self->accelerometerDriverProvider = AccelerometerDriverProvider_init(AccelerometerDriverProvider_getInstance());
    self->motionDetector = MotionDetector_init(MotionDetector_getInstance());
    os_Task_init(&self->tasks[0], 10, self, (os_Task_operationFun)os_Scheduler_runAt10ms);
    os_Task_init(&self->tasks[1], 20, self, (os_Task_operationFun)os_Scheduler_runAt20ms);
    os_Task_init(&self->tasks[2], 50, self, (os_Task_operationFun)os_Scheduler_runAt50ms);
    os_Task_init(&self->tasks[3], 100, self, (os_Task_operationFun)os_Scheduler_runAt100ms);
    return self;
}

void os_Scheduler_run(os_Scheduler * const self) {
    for (uint8_t i = 0; i < 4; i++) {
        os_Task_run(&self->tasks[i]);
    }
}
