#ifndef os_KeyHandler_h
#define os_KeyHandler_h

typedef struct os_KeyHandler os_KeyHandler;

os_KeyHandler * os_KeyHandler_getInstance(void);
os_KeyHandler * os_KeyHandler_init(os_KeyHandler * const self);
void os_KeyHandler_run(os_KeyHandler * const self);

#endif // os_KeyHandler_h
