#include "Os_KeyHandler.h"
#include "Os.h"
#include "Os_Interrupts.h"
#include "conioWrapper.h"

struct Os_KeyHandler {
    Os * os;
};

Os_KeyHandler * Os_KeyHandler_getInstance(void) {
    static Os_KeyHandler self;
    return &self;
}

Os_KeyHandler * Os_KeyHandler_init(Os_KeyHandler * const self) {
    self->os = Os_getInstance();
    return self;
}

static void Os_KeyHandler_onRKeyPress(Os_KeyHandler * const self) {
    (void)self;
    Os_Interrupts_realAccDataAvailable();
}

static void Os_KeyHandler_onSKeyPress(Os_KeyHandler * const self) {
    (void)self;
    Os_Interrupts_simAccDataAvailable();
}

static void Os_KeyHandler_onTKeyPress(Os_KeyHandler * const self) {
    (void)self;
    Os_Interrupts_buttonPress();
}

static void Os_KeyHandler_onQKeyPress(Os_KeyHandler * const self) {
    Os_quit(self->os);
}

void Os_KeyHandler_run(Os_KeyHandler * const self) {
    if (_kbhit()) {
        int key = _getch();
        switch (key) {
            case 'r': {
                Os_KeyHandler_onRKeyPress(self);
            } break;
            case 's': {
                Os_KeyHandler_onSKeyPress(self);
            } break;
            case 't': {
                Os_KeyHandler_onTKeyPress(self);
            } break;
            case 'q': {
                Os_KeyHandler_onQKeyPress(self);
            } break;
            default: {
            } break;
        }
    }
}
