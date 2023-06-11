#ifndef Acceleration3d_h
#define Acceleration3d_h
#include <stdint.h>

typedef struct Acceleration3d Acceleration3d;
struct Acceleration3d {
    int16_t x;
    int16_t y;
    int16_t z;
};

Acceleration3d * Acceleration3d_plus(Acceleration3d * const self, Acceleration3d * const other);
Acceleration3d * Acceleration3d_div(Acceleration3d * const self, uint8_t other);
uint16_t Acceleration3d_magnitude(Acceleration3d * const self);

#endif // Acceleration3d_h
