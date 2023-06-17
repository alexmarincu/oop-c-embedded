#include "AccelerometerDriverProvider.h"
#include "../accelerometer_data_models/AccelerometerConfig.h"
#include "../accelerometer_data_storage/AccelerometerConfigStorage.h"
#include "../lib/observer/Observer.h"
#include "../lib/observer/Subject.h"
#include "AccelerometerSimulatorDriver.h"
#include "RealAccelerometerDriver.h"
#include <stdio.h>

struct AccelerometerDriverProvider {
    Observer observer;
    AccelerometerConfigStorage * accelerometerConfigStorage;
    RealAccelerometerDriver * realAccelerometerDriver;
    AccelerometerSimulatorDriver * accelerometerSimulatorDriver;
    AccelerometerDriver * currentAccelerometerDriver;
};

static void AccelerometerDriverProvider_onConfigChange(AccelerometerDriverProvider * const self);

AccelerometerDriverProvider * AccelerometerDriverProvider_getInstance(void) {
    static AccelerometerDriverProvider self;
    return &self;
}

AccelerometerDriverProvider * AccelerometerDriverProvider_init(AccelerometerDriverProvider * const self) {
    Observer_init((Observer *)self, self, (Observer_onUpdateFun)AccelerometerDriverProvider_onConfigChange);
    self->realAccelerometerDriver = RealAccelerometerDriver_init(
        RealAccelerometerDriver_getInstance(),
        AccelerometerCtrl_init(
            AccelerometerCtrl_getInstance(),
            MotionDetector_init(MotionDetector_getInstance())
        )
    );
    self->accelerometerSimulatorDriver = AccelerometerSimulatorDriver_init(
        AccelerometerSimulatorDriver_getInstance(),
        AccelerometerCtrl_init(
            AccelerometerCtrl_getInstance(),
            MotionDetector_init(MotionDetector_getInstance())
        )
    );
    self->accelerometerConfigStorage = AccelerometerConfigStorage_getInstance();
    self->currentAccelerometerDriver = (AccelerometerDriver *)self->realAccelerometerDriver;
    Subject_registerObserver((Subject *)self->accelerometerConfigStorage, (Observer *)self);
    return self;
}

static void AccelerometerDriverProvider_onConfigChange(AccelerometerDriverProvider * const self) {
    AccelerometerConfig * accelerometerConfig =
        AccelerometerConfigStorage_read(self->accelerometerConfigStorage, &(AccelerometerConfig){ 0 });
    if (accelerometerConfig->isSimulatorEnabled) {
        self->currentAccelerometerDriver = (AccelerometerDriver *)self->accelerometerSimulatorDriver;
        printf("Switch to acc sim\n");
    } else {
        self->currentAccelerometerDriver = (AccelerometerDriver *)self->realAccelerometerDriver;
        printf("Switch to acc\n");
    }
}

AccelerometerDriver * AccelerometerDriverProvider_getCurrentAccelerometerDriver(AccelerometerDriverProvider * const self) {
    return self->currentAccelerometerDriver;
}
