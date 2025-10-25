#include "rhombus.h"
#include "polygon_utils.h"
#include <iomanip>

Rhombus::Rhombus() : vertices{Point{-1,0}, Point{0,1}, Point{1,0}, Point{0,-1}} {}

Rhombus::Rhombus(const std::array<Point,4>& points) : vertices(points) {}

Point Rhombus::center() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonCentroid(pts);
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: ";
    os << std::fixed << std::setprecision(6);
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i + 1 != vertices.size()) os << " ";
    }
}

void Rhombus::read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

Rhombus::operator double() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonArea(pts);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* o = dynamic_cast<const Rhombus*>(&other);
    if (!o) return false;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i].x != o->vertices[i].x || vertices[i].y != o->vertices[i].y) return false;
    }
    return true;
}

std::unique_ptr<Figure> Rhombus::clone() const {
    return std::make_unique<Rhombus>(*this);
}


