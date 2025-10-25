#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
#include <utility>
#include "point.h"

class Figure {
public:
    virtual ~Figure() = default;

    virtual Point center() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual explicit operator double() const = 0; // area
    virtual bool operator==(const Figure& other) const = 0;

    virtual std::unique_ptr<Figure> clone() const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& f) {
    f.read(is);
    return is;
}

#endif // FIGURE_H


