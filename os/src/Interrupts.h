#ifndef Interrupts_h
#define Interrupts_h

typedef void (*Interrupts_callbackFun)(void);

void Interrupts_init(void);
void Interrupts_r(void);
void Interrupts_s(void);
void Interrupts_b(void);
void Interrupts_registerRCallback(Interrupts_callbackFun const callback);
void Interrupts_registerSCallback(Interrupts_callbackFun const callback);
void Interrupts_registerBCallback(Interrupts_callbackFun const callback);

#endif // Interrupts_h
