#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <memory>
#include "figure.h"

class FigureArray {
public:
    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept = default;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept = default;

    void add(std::unique_ptr<Figure> f);
    bool removeAt(size_t index);
    size_t size() const { return items.size(); }
    const Figure& at(size_t index) const { return *items.at(index); }

    double totalArea() const;

    template <class F>
    void forEach(F&& fn) const {
        for (const auto& ptr : items) fn(*ptr);
    }

private:
    std::vector<std::unique_ptr<Figure>> items;
};

#endif // ARRAY_H


