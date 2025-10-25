#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <array>

class Trapezoid : public Figure {
public:
    // Defined by 4 vertices in order (convex trapezoid). Input: A B C D
    Trapezoid();
    explicit Trapezoid(const std::array<Point,4>& points);
    Trapezoid(const Trapezoid&) = default;
    Trapezoid(Trapezoid&&) noexcept = default;
    Trapezoid& operator=(const Trapezoid&) = default;
    Trapezoid& operator=(Trapezoid&&) noexcept = default;

    Point center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override; // area
    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

private:
    std::array<Point,4> vertices; // A,B,C,D order
};

#endif // TRAPEZOID_H


