#ifndef Scheduler_h
#define Scheduler_h
#include "Task.h"

void Scheduler_setTasks(Task * const tasks, uint8_t const count);
void Scheduler_main(void);

#endif // Scheduler_h
