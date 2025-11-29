#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure {
public:
    Rhomb();
    Point CenterOfRotation() const override;
};

#endif // RHOMB_H

