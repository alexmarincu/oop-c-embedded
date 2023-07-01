#include "InterruptHandler.h"
#include "coniow.h"
#include <stddef.h>

typedef struct InterruptHandler InterruptHandler;
struct InterruptHandler {
    InterruptHandler_cbkFun realAccelerometerDataAvailableIntCbk;
    InterruptHandler_cbkFun accelerometerSimulatorDataAvailableIntCbk;
    InterruptHandler_cbkFun pushButtonPressIntCbk;
};

static InterruptHandler self = {
    .realAccelerometerDataAvailableIntCbk = NULL,
    .accelerometerSimulatorDataAvailableIntCbk = NULL,
    .pushButtonPressIntCbk = NULL
};

static void InterruptHandler_cbkCall(InterruptHandler_cbkFun cbk) {
    if (cbk) {
        cbk();
    }
}

void InterruptHandler_registerRealAccelerometerDataAvailableIntCbk(InterruptHandler_cbkFun const realAccelerometerDataAvailableIntCbk) {
    self.realAccelerometerDataAvailableIntCbk = realAccelerometerDataAvailableIntCbk;
}

void InterruptHandler_registerAccelerometerSimulatorDataAvailableIntCbk(
    InterruptHandler_cbkFun const accelerometerSimulatorDataAvailableIntCbk
) {
    self.accelerometerSimulatorDataAvailableIntCbk = accelerometerSimulatorDataAvailableIntCbk;
}

void InterruptHandler_registerPushButtonPressIntCbk(InterruptHandler_cbkFun const pushButtonPressIntCbk) {
    self.pushButtonPressIntCbk = pushButtonPressIntCbk;
}

void InterruptHandler_main(void) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r':
            case 'R': {
                InterruptHandler_cbkCall(self.realAccelerometerDataAvailableIntCbk);
            } break;
            case 's':
            case 'S': {
                InterruptHandler_cbkCall(self.accelerometerSimulatorDataAvailableIntCbk);
            } break;
            case 'b':
            case 'B': {
                InterruptHandler_cbkCall(self.pushButtonPressIntCbk);
            } break;
            default: {
            } break;
        }
    }
}