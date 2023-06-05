#ifndef Timer_h
#define Timer_h
#include "TimeSource.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct Timer Timer;
typedef struct TimerClass TimerClass;
struct Timer {
    TimerClass * klass;
    uint32_t startTimeIn1ms;
    uint32_t durationIn1ms;
    bool isRunning;
};

TimerClass * TimerClass_getInstance(void);
TimerClass * TimerClass_init(TimerClass * const self, TimeSource * const timeSource);
Timer * Timer_init(Timer * const self);
void Timer_start(Timer * const self, uint32_t const durationIn1ms);
bool Timer_isExpired(Timer const * const self);

#endif // Timer_h
