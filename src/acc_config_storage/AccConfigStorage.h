#ifndef AccConfigStorage_h
#define AccConfigStorage_h
#include "../acc_config/AccConfig.h"
#include "../acc_config/AccConfigDao.h"

typedef struct AccConfigStorage AccConfigStorage;

AccConfigStorage * AccConfigStorage_getInstance(void);
AccConfigStorage * AccConfigStorage_init(AccConfigStorage * const self);
AccConfigDao * AccConfigStorage_getAccConfigDao(AccConfigStorage * const self);
void AccConfigStorage_write(AccConfigStorage * const self, AccConfig * const accConfig);
AccConfig * AccConfigStorage_read(AccConfigStorage * const self, AccConfig * const accConfig);

#endif // AccConfigStorage_h
