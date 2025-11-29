#include "include/point.h"
#include <cmath>

#define EPSILON 1e-9

Point::Point() : _x(0.0), _y(0.0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

double Point::X() const {
    return _x;
}

double Point::Y() const {
    return _y;
}

bool Point::operator==(const Point& point) const {
    return (std::abs(_x - point._x) < EPSILON)
        && (std::abs(_y - point._y) < EPSILON);
}

bool Point::operator!=(const Point& point) const {
    return !(*this == point);
}

std::istream& operator>>(std::istream& istream, Point& point) {
    istream >> point._x >> point._y;
    return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Point& point) {
    ostream << "[" << point._x << "; " << point._y << "]";
    return ostream;
}

