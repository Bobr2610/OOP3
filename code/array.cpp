#include "array.h"

FigureArray::FigureArray(const FigureArray& other) {
    items.reserve(other.items.size());
    for (const auto& ptr : other.items) {
        items.push_back(ptr ? ptr->clone() : nullptr);
    }
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this == &other) return *this;
    std::vector<std::unique_ptr<Figure>> newItems;
    newItems.reserve(other.items.size());
    for (const auto& ptr : other.items) {
        newItems.push_back(ptr ? ptr->clone() : nullptr);
    }
    items.swap(newItems);
    return *this;
}

void FigureArray::add(std::unique_ptr<Figure> f) {
    items.push_back(std::move(f));
}

bool FigureArray::removeAt(size_t index) {
    if (index >= items.size()) return false;
    items.erase(items.begin() + static_cast<std::ptrdiff_t>(index));
    return true;
}

double FigureArray::totalArea() const {
    double sum = 0.0;
    for (const auto& ptr : items) {
        sum += static_cast<double>(*ptr);
    }
    return sum;
}


