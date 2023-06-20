#include "Scheduler.h"
#include "../../../motion_detector/src/MotionDetector.h"
#include "../../../utils/src/timer/Timer.h"
#include "../accelerometer/AccelerometerConfigurator.h"
#include "../accelerometer_data_storage/AccelerometerConfigStorage.h"
#include "../accelerometer/AccelerometerDriver.h"
#include "../accelerometer/AccelerometerDriverProvider.h"
#include "../button/ButtonCtrl.h"
#include "../button/ButtonDriver.h"
#include "AccelerometerSimulatorDriver.h"
#include "RealAccelerometerDriver.h"
#include "Task.h"
#include "SysTime.h"

struct Scheduler {
    ButtonDriver * buttonDriver;
    Task tasks[4];
};

static void Scheduler_runAt10ms(Scheduler * const self) {
    (void)self;
}

static void Scheduler_runAt20ms(Scheduler * const self) {
    (void)self;
}

static void Scheduler_runAt50ms(Scheduler * const self) {
    (void)self;
    AccelerometerDriver_run(AccelerometerDriverProvider_getCurrentAccelerometerDriver());
    MotionDetector_run();
}

static void Scheduler_runAt100ms(Scheduler * const self) {
    ButtonDriver_run(self->buttonDriver);
}

Scheduler * Scheduler_getInstance(void) {
    static Scheduler self;
    return &self;
}

Scheduler * Scheduler_init(Scheduler * const self) {
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
    RealAccelerometerDriver_init(RealAccelerometerDriver_getInstance());
    AccelerometerSimulatorDriver_init(AccelerometerSimulatorDriver_getInstance());
    AccelerometerDriverProvider_init();
    MotionDetector_init();
    Task_init(&self->tasks[0], 10, self, (Task_operationFun)Scheduler_runAt10ms);
    Task_init(&self->tasks[1], 20, self, (Task_operationFun)Scheduler_runAt20ms);
    Task_init(&self->tasks[2], 50, self, (Task_operationFun)Scheduler_runAt50ms);
    Task_init(&self->tasks[3], 100, self, (Task_operationFun)Scheduler_runAt100ms);
    return self;
}

void Scheduler_run(Scheduler * const self) {
    for (uint8_t i = 0; i < 4; i++) {
        Task_run(&self->tasks[i]);
    }
}
