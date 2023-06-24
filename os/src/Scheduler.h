#ifndef Scheduler_h
#define Scheduler_h
#include "Task.h"

void Scheduler_init(Task * const tasks, uint8_t const count);
void Scheduler_run(void);

#endif // Scheduler_h
