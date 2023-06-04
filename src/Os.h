#ifndef Os_h
#define Os_h

typedef struct Os Os;

Os * Os_getInstance(void);
Os * Os_init(Os * const self);
void Os_run(Os * const self);
void Os_quit(Os * const self);

#endif // Os_h
