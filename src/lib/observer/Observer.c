#include "Observer.h"

Observer * Observer_init(Observer * const self, void * const impl, Observer_onUpdateFun const onUpdate) {
    self->impl = impl;
    self->onUpdate = onUpdate;
    return self;
}

void Observer_onUpdate(Observer * const self) {
    return self->onUpdate(self->impl);
}
