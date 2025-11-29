#include "include/trapezoid.h"

Trapezoid::Trapezoid() : Figure(4) {}

Point Trapezoid::CenterOfRotation() const {
    return Figure::CenterOfRotation();
}


