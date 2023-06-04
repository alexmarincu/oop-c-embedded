#include "Subject.h"
#include <string.h>

Subject * Subject_init(Subject * const self) {
    memset(self->observers, 0, sizeof(self->observers));
    self->count = 0;
    return self;
}

void Subject_registerObserver(Subject * self, Observer * observer) {
    if (self->count < Subject_observersMaxCount) {
        self->observers[self->count++] = observer;
    }
}

void Subject_notifyObservers(Subject * self, void * data) {
    for (uint32_t i = 0; i < self->count; ++i) {
        Observer * observer = self->observers[i];
        observer->update(observer, data);
    }
}