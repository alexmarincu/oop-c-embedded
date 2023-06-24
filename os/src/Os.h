#ifndef Os_h
#define Os_h
#include "Task.h"

void Os_init(Task * const tasks, uint8_t const count);
void Os_run(void);
void Os_quit(void);

#endif // Os_h
