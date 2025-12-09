#pragma once
#include <iostream>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readVertices(std::istream& is) = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual bool operator==(const Figure& other) const = 0;

    std::ostream& print(std::ostream& os) const {
        printVertices(os);
        return os;
    }

    std::istream& input(std::istream& is) {
        readVertices(is);
        return is;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    return fig.print(os);
}

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    return fig.input(is);
}
