#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Point CenterOfRotation() const override;
};

#endif // TRAPEZOID_H


