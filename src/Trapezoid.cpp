#include "Trapezoid.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Trapezoid::Trapezoid(const std::array<std::pair<double, double>, 4>& verts) : vertices(verts) {}

std::pair<double, double> Trapezoid::geometricCenter() const {
    double sumX = 0, sumY = 0;
    for (const auto& v : vertices) {
        sumX += v.first;
        sumY += v.second;
    }
    return {sumX / 4.0, sumY / 4.0};
}

double Trapezoid::area() const {
    double base1 = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) +
                             std::pow(vertices[1].second - vertices[0].second, 2));
    double base2 = std::sqrt(std::pow(vertices[3].first - vertices[2].first, 2) +
                             std::pow(vertices[3].second - vertices[2].second, 2));
    double height = std::abs(vertices[0].second - vertices[2].second);
    return (base1 + base2) * height / 2.0;
}

void Trapezoid::printVertices(std::ostream& os) const {
    os << "Trapezoid vertices:";
    for (const auto& v : vertices) {
        os << " (" << v.first << "," << v.second << ")";
    }
    os << "\n";
}

void Trapezoid::readVertices(std::istream& is) {
    for (auto& v : vertices) {
        is >> v.first >> v.second;
    }
}

Figure& Trapezoid::operator=(const Figure& other) {
    if (this != &other) {
        const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
        if (!trap) throw std::invalid_argument("Нельзя присвоить объект другого типа Trapezoid");
        vertices = trap->vertices;
    }
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* trap = dynamic_cast<const Trapezoid*>(&other);
    if (!trap) return false;
    return vertices == trap->vertices;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) vertices = other.vertices;
    return *this;
}
