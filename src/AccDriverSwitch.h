#ifndef AccDriverSwitch_h
#define AccDriverSwitch_h

typedef struct AccDriverSwitch AccDriverSwitch;

AccDriverSwitch * AccDriverSwitch_getInstance(void);
AccDriverSwitch * AccDriverSwitch_init(AccDriverSwitch * const self);
void AccDriverSwitch_toggleAccDriver(void);

#endif // AccDriverSwitch_h
