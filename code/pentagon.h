#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <array>

class Pentagon : public Figure {
public:
    // Defined by 5 vertices in order
    Pentagon();
    explicit Pentagon(const std::array<Point,5>& points);
    Pentagon(const Pentagon&) = default;
    Pentagon(Pentagon&&) noexcept = default;
    Pentagon& operator=(const Pentagon&) = default;
    Pentagon& operator=(Pentagon&&) noexcept = default;

    Point center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    explicit operator double() const override; // area
    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

private:
    std::array<Point,5> vertices;
};

#endif // PENTAGON_H


