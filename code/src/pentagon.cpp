#include "include/pentagon.h"

Pentagon::Pentagon() : Figure(5) {}

Point Pentagon::CenterOfRotation() const {
    return Figure::CenterOfRotation();
}


