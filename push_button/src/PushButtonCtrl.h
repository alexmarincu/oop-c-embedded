#ifndef PushButtonCtrl_h
#define PushButtonCtrl_h

typedef void (*PushButtonCtrl_onPressFun)(void);

void PushButtonCtrl_onPress(void);
void PushButtonCtrl_registerOnPress(PushButtonCtrl_onPressFun const onPress);

#endif // PushButtonCtrl_h
