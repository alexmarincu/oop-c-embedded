#include "AccDriverSwitch.h"
#include "RealAccDriver.h"
#include "SimAccDriver.h"

struct AccDriverSwitch {
    Observer observer;
    AccCtrl * accCtrl;
    AccConfig * accConfig;
    RealAccDriver * realAccDriver;
    SimAccDriver * simAccDriver;
};

static void AccDriverSwitch_onConfigChange(AccDriverSwitch * const self);

AccDriverSwitch * AccDriverSwitch_getInstance(void) {
    static AccDriverSwitch self;
    return &self;
}

AccDriverSwitch * AccDriverSwitch_init(AccDriverSwitch * const self) {
    Observer_init((Observer *)self, (Observer_onUpdateFun)AccDriverSwitch_onConfigChange);
    self->accConfig = AccConfig_getInstance();
    self->accCtrl = AccCtrl_getInstance();
    self->realAccDriver = RealAccDriver_getInstance();
    self->simAccDriver = SimAccDriver_getInstance();
    Subject_registerObserver((Subject *)self->accConfig, (Observer *)self);
    return self;
}

static void AccDriverSwitch_onConfigChange(AccDriverSwitch * const self) {
    if (AccConfig_isSimulatorEnabled(self->accConfig)) {
        AccCtrl_setAccDriver(self->accCtrl, (AccDriver *)self->simAccDriver);
    } else {
        AccCtrl_setAccDriver(self->accCtrl, (AccDriver *)self->realAccDriver);
    }
}