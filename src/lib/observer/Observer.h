#ifndef Observer_h
#define Observer_h

typedef struct Observer Observer;
typedef void (*Observer_onUpdateFun)(Observer const * const observer);

struct Observer {
    void * impl;
    Observer_onUpdateFun onUpdate;
};

Observer * Observer_init(Observer * const self, void * const impl, Observer_onUpdateFun const onUpdate);
void Observer_onUpdate(Observer * const self);

#endif // Observer_h
