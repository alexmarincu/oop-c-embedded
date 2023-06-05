#ifndef Observer_h
#define Observer_h

typedef struct Observer Observer;
typedef void (*Observer_onUpdateFun)(Observer const * const observer);

struct Observer {
    Observer_onUpdateFun onUpdate;
};

Observer * Observer_init(Observer * const self, Observer_onUpdateFun const onUpdate);

#endif // Observer_h
