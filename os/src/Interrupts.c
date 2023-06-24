#include "Interrupts.h"
#include <stdlib.h>

typedef struct Interrupts Interrupts;
struct Interrupts {
    Interrupts_callbackFun r;
    Interrupts_callbackFun s;
    Interrupts_callbackFun b;
};

static Interrupts self;

void Interrupts_init(void) {
    self.r = NULL;
    self.s = NULL;
    self.b = NULL;
}

void Interrupts_r(void) {
    if (self.r) {
        self.r();
    }
}

void Interrupts_s(void) {
    if (self.s) {
        self.s();
    }
}

void Interrupts_b(void) {
    if (self.b) {
        self.b();
    }
}

void Interrupts_registerRCallback(Interrupts_callbackFun const callback) {
    self.r = callback;
}
void Interrupts_registerSCallback(Interrupts_callbackFun const callback) {
    self.s = callback;
}
void Interrupts_registerBCallback(Interrupts_callbackFun const callback) {
    self.b = callback;
}