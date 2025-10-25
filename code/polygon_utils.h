#ifndef POLYGON_UTILS_H
#define POLYGON_UTILS_H

#include <vector>
#include "point.h"

double polygonArea(const std::vector<Point>& pts);
Point polygonCentroid(const std::vector<Point>& pts);

#endif // POLYGON_UTILS_H


