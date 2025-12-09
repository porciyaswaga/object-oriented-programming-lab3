#pragma once
#include "Figure.h"
#include <array>

class Rectangle : public Figure {
private:
    std::array<std::pair<double, double>, 4> vertices;

public:
    Rectangle() = default;
    Rectangle(const std::array<std::pair<double, double>, 4>& verts);

    std::pair<double, double> geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readVertices(std::istream& is) override;
    
    Figure& operator=(const Figure& other) override;
    bool operator==(const Figure& other) const override;
    Rectangle& operator=(const Rectangle& other);
};
