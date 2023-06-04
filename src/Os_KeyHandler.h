#ifndef Os_KeyHandler_h
#define Os_KeyHandler_h

typedef struct Os_KeyHandler Os_KeyHandler;

Os_KeyHandler * Os_KeyHandler_getInstance(void);
Os_KeyHandler * Os_KeyHandler_init(Os_KeyHandler * const self);
void Os_KeyHandler_run(Os_KeyHandler * const self);

#endif // Os_KeyHandler_h
