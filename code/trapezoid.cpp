#include "trapezoid.h"
#include "polygon_utils.h"
#include <iomanip>

Trapezoid::Trapezoid() : vertices{Point{0,0}, Point{1,0}, Point{0.7,1}, Point{-0.3,1}} {}

Trapezoid::Trapezoid(const std::array<Point,4>& points) : vertices(points) {}

Point Trapezoid::center() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonCentroid(pts);
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: ";
    os << std::fixed << std::setprecision(6);
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i + 1 != vertices.size()) os << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

Trapezoid::operator double() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonArea(pts);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* o = dynamic_cast<const Trapezoid*>(&other);
    if (!o) return false;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i].x != o->vertices[i].x || vertices[i].y != o->vertices[i].y) return false;
    }
    return true;
}

std::unique_ptr<Figure> Trapezoid::clone() const {
    return std::make_unique<Trapezoid>(*this);
}


