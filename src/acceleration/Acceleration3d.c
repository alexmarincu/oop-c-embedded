#include "Acceleration3d.h"
#include <math.h>

Acceleration3d * Acceleration3d_plus(Acceleration3d * const self, Acceleration3d * const other) {
    self->x += other->x;
    self->y += other->y;
    self->z += other->z;
    return self;
}

Acceleration3d * Acceleration3d_div(Acceleration3d * const self, uint8_t other) {
    self->x /= other;
    self->y /= other;
    self->z /= other;
    return self;
}

uint16_t Acceleration3d_magnitude(Acceleration3d * const self) {
    return sqrt(pow(self->x, 2) + pow(self->y, 2) + pow(self->z, 2));
}