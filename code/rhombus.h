#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <array>

class Rhombus : public Figure {
public:
    // Defined by 4 vertices in order
    Rhombus();
    explicit Rhombus(const std::array<Point,4>& points);
    Rhombus(const Rhombus&) = default;
    Rhombus(Rhombus&&) noexcept = default;
    Rhombus& operator=(const Rhombus&) = default;
    Rhombus& operator=(Rhombus&&) noexcept = default;

    Point center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override; // area
    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

private:
    std::array<Point,4> vertices;
};

#endif // RHOMBUS_H


