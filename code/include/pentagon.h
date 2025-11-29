#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure {
public:
    Pentagon();
    Point CenterOfRotation() const override;
};

#endif // PENTAGON_H


