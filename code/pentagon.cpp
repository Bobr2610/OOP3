#include "pentagon.h"
#include "polygon_utils.h"
#include <iomanip>

Pentagon::Pentagon()
    : vertices{Point{0,1}, Point{0.951056,0.309017}, Point{0.587785,-0.809017}, Point{-0.587785,-0.809017}, Point{-0.951056,0.309017}} {}

Pentagon::Pentagon(const std::array<Point,5>& points) : vertices(points) {}

Point Pentagon::center() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonCentroid(pts);
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon: ";
    os << std::fixed << std::setprecision(6);
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i + 1 != vertices.size()) os << " ";
    }
}

void Pentagon::read(std::istream& is) {
    for (auto& p : vertices) {
        is >> p.x >> p.y;
    }
}

Pentagon::operator double() const {
    std::vector<Point> pts(vertices.begin(), vertices.end());
    return polygonArea(pts);
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* o = dynamic_cast<const Pentagon*>(&other);
    if (!o) return false;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i].x != o->vertices[i].x || vertices[i].y != o->vertices[i].y) return false;
    }
    return true;
}

std::unique_ptr<Figure> Pentagon::clone() const {
    return std::make_unique<Pentagon>(*this);
}


