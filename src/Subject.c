#include "Subject.h"

Subject * Subject_init(Subject * const self, Observer ** const observers, uint32_t const maxCount) {
    self->observers = observers;
    self->count = 0;
    self->maxCount = maxCount;
    return self;
}

void Subject_registerObserver(Subject * self, Observer * observer) {
    if (self->count < self->maxCount) {
        self->observers[self->count++] = observer;
    }
}

void Subject_notifyObservers(Subject * self, void * data) {
    for (uint32_t i = 0; i < self->count; ++i) {
        Observer * observer = self->observers[i];
        observer->update(observer, data);
    }
}