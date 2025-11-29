#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
    Point();
    Point(double x, double y);
    Point(const Point& point) = default;
    Point(Point&& point) noexcept = default;

    double X() const;
    double Y() const;

    bool operator==(const Point& point) const;
    bool operator!=(const Point& point) const;

    Point& operator=(const Point& point) = default;
    Point& operator=(Point&& point) noexcept = default;

    friend std::istream& operator>>(std::istream& istream, Point& point);
    friend std::ostream& operator<<(std::ostream& ostream, const Point& point);

private:
    double _x;
    double _y;
};

std::istream& operator>>(std::istream& istream, Point& point);
std::ostream& operator<<(std::ostream& ostream, const Point& point);

#endif // POINT_H


