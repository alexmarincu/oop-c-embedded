#include "Os_KeyHandler.h"
#include "AccConfig.h"
#include "Os.h"
#include "RealAccDriver.h"
#include "SimAccDriver.h"
#include "conioWrapper.h"
#include <stdio.h>

struct Os_KeyHandler {
    Os * os;
    AccConfig * accConfig;
    RealAccDriver * realAccDriver;
    SimAccDriver * simAccDriver;
};

Os_KeyHandler * Os_KeyHandler_getInstance(void) {
    static Os_KeyHandler self;
    return &self;
}

Os_KeyHandler * Os_KeyHandler_init(Os_KeyHandler * const self) {
    self->os = Os_getInstance();
    self->accConfig = AccConfig_getInstance();
    self->realAccDriver = RealAccDriver_getInstance();
    self->simAccDriver = SimAccDriver_getInstance();
    return self;
}

static void Os_KeyHandler_rKeyInt(Os_KeyHandler * const self) {
    AccDriver_dataAvailableInt((AccDriver *)self->realAccDriver);
}

static void Os_KeyHandler_sKeyInt(Os_KeyHandler * const self) {
    AccDriver_dataAvailableInt((AccDriver *)self->simAccDriver);
}

static void Os_KeyHandler_tKeyInt(Os_KeyHandler * const self) {
    AccConfig_toggleAccDriver(self->accConfig);
}

static void Os_KeyHandler_qKeyInt(Os_KeyHandler * const self) {
    Os_quit(self->os);
}

void Os_KeyHandler_run(Os_KeyHandler * const self) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r': {
                Os_KeyHandler_rKeyInt(self);
            } break;
            case 's': {
                Os_KeyHandler_sKeyInt(self);
            } break;
            case 't': {
                Os_KeyHandler_tKeyInt(self);
            } break;
            case 'q': {
                Os_KeyHandler_qKeyInt(self);
            } break;
            default: {
            } break;
        }
    }
}
