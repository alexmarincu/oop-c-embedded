#ifndef Subject_h
#define Subject_h
#include "Observer.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct Subject Subject;

#define Subject_observersMaxCount 1
struct Subject {
    Observer * observers[Subject_observersMaxCount];
    uint32_t count;
};

Subject * Subject_init(Subject * const self);
void Subject_registerObserver(Subject * self, Observer * observer);
void Subject_notifyObservers(Subject * self, void * data);

#endif // Subject_h
