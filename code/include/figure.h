#ifndef FIGURE_H
#define FIGURE_H

#include <cstdint>
#include <iostream>
#include <vector>
#include "point.h"

class Figure {
public:
    explicit Figure(std::uint64_t points_count);
    Figure(const Figure& figure);
    Figure(Figure&& figure) noexcept;
    virtual ~Figure() noexcept = default;

    virtual Point CenterOfRotation() const;

    std::istream& Input(std::istream& istream);
    std::ostream& Output(std::ostream& ostream) const;

    Figure& operator=(const Figure& figure);
    Figure& operator=(Figure&& figure) noexcept;

    bool operator==(const Figure& figure) const;
    bool operator!=(const Figure& figure) const;

    explicit operator double() const;

protected:
    std::vector<Point> _points;
    std::uint64_t _points_count;
};

std::istream& operator>>(std::istream& istream, Figure& figure);
std::ostream& operator<<(std::ostream& ostream, const Figure& figure);

#endif // FIGURE_H


