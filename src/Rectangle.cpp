#include "Rectangle.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Rectangle::Rectangle(const std::array<std::pair<double, double>, 4>& verts) 
    : vertices(verts) {}

std::pair<double, double> Rectangle::geometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& v : vertices) {
        sumX += v.first;
        sumY += v.second;
    }
    return {sumX / 4.0, sumY / 4.0};
}

double Rectangle::area() const {
    double dx1 = vertices[1].first - vertices[0].first;
    double dy1 = vertices[1].second - vertices[0].second;
    double dx2 = vertices[3].first - vertices[0].first;
    double dy2 = vertices[3].second - vertices[0].second;
    double side1 = std::sqrt(dx1*dx1 + dy1*dy1);
    double side2 = std::sqrt(dx2*dx2 + dy2*dy2);
    return side1 * side2;
}

void Rectangle::printVertices(std::ostream& os) const {
    os << "Rectangle vertices:";
    for (const auto& v : vertices) {
        os << " (" << v.first << "," << v.second << ")";
    }
    os << "\n";
}

void Rectangle::readVertices(std::istream& is) {
    for (auto& v : vertices) {
        is >> v.first >> v.second;
    }
}

// Оператор присваивания для override
Figure& Rectangle::operator=(const Figure& other) {
    if (this != &other) {
        const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
        if (!rect) {
            throw std::invalid_argument("Нельзя присвоить объект другого типа Rectangle");
        }
        vertices = rect->vertices;
    }
    return *this;
}

// Сравнение для override
bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&other);
    if (!rect) return false;
    return vertices == rect->vertices;
}

// Дополнительный типизированный оператор присваивания
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) vertices = other.vertices;
    return *this;
}
