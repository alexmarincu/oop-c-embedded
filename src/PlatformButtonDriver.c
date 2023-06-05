#include "PlatformButtonDriver.h"

struct PlatformButtonDriver {
    ButtonDriver buttonDriver;
};

PlatformButtonDriver * PlatformButtonDriver_getInstance(void) {
    static PlatformButtonDriver self;
    return &self;
}

PlatformButtonDriver * PlatformButtonDriver_init(PlatformButtonDriver * const self) {
    ButtonDriver_init((ButtonDriver *)self);
    return self;
}
