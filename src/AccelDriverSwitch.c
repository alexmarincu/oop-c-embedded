#include "AccelDriverSwitch.h"
#include "RealAccelDriver.h"
#include "SimAccelDriver.h"

struct AccelDriverSwitch {
    Observer observer;
    AccelCtrl * accelCtrl;
    AccelConfig * accelConfig;
    RealAccelDriver * realAccelDriver;
    SimAccelDriver * simAccelDriver;
};

static void AccelDriverSwitch_onConfigChange(AccelDriverSwitch * const self, bool * const isSimulatorEnabled);

AccelDriverSwitch * AccelDriverSwitch_getInstance(void) {
    static AccelDriverSwitch self;
    return &self;
}

AccelDriverSwitch * AccelDriverSwitch_init(AccelDriverSwitch * const self) {
    Observer_init((Observer *)self, (Observer_updateFun)AccelDriverSwitch_onConfigChange);
    self->accelConfig = AccelConfig_getInstance();
    self->accelCtrl = AccelCtrl_getInstance();
    self->realAccelDriver = RealAccelDriver_getInstance();
    self->simAccelDriver = SimAccelDriver_getInstance();
    Subject_registerObserver((Subject *)self->accelConfig, (Observer *)self);
    return self;
}

static void AccelDriverSwitch_onConfigChange(AccelDriverSwitch * const self, bool * const isSimulatorEnabled) {
    if (*isSimulatorEnabled) {
        AccelCtrl_setAccelDriver(self->accelCtrl, (AccelDriver *)self->simAccelDriver);
    } else {
        AccelCtrl_setAccelDriver(self->accelCtrl, (AccelDriver *)self->realAccelDriver);
    }
}