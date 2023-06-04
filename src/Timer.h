#ifndef Timer_h
#define Timer_h
#include "TimerClass.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    TimerClass * klass;
    uint32_t startTimeInMs;
    uint32_t durationInMs;
    bool isRunning;
} Timer;

Timer * Timer_init(Timer * const self);
void Timer_start(Timer * const self, uint32_t const durationInMs);
bool Timer_isExpired(Timer const * const self);

#endif // Timer_h
