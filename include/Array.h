#pragma once
#include "Figure.h"
#include <vector>

class Array {
private:
    std::vector<Figure*> data;

public:
    Array() = default;
    ~Array();

    void push(Figure* fig);
    void remove(size_t index);

    Figure* operator[](size_t index);
    const Figure* operator[](size_t index) const;

    size_t size() const;

    double totalArea() const;
};
