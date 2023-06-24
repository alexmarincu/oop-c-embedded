#include "PushButtonCtrl.h"
#include <stdlib.h>

typedef struct PushButtonCtrl PushButtonCtrl;
struct PushButtonCtrl {
    PushButtonCtrl_onPressFun onPress;
};

static PushButtonCtrl self = {
    .onPress = NULL
};

void PushButtonCtrl_onPress(void) {
    if (self.onPress) {
        self.onPress();
    }
}

void PushButtonCtrl_registerOnPress(PushButtonCtrl_onPressFun const onPress) {
    self.onPress = onPress;
}
