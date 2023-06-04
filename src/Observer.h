#ifndef Observer_h
#define Observer_h

typedef struct Observer Observer;
typedef void (*Observer_updateFun)(Observer const * const observer, void * const data);

struct Observer {
    Observer_updateFun update;
};

Observer * Observer_init(Observer * const self, Observer_updateFun const update);

#endif // Observer_h
