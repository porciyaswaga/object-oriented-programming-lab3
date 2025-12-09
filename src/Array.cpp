#include "Array.h"
#include <stdexcept>

Array::~Array() {
    for (auto* f : data) {
        delete f;
    }
}

void Array::push(Figure* fig) {
    data.push_back(fig);
}

void Array::remove(size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Ошибка с индексом");
    }
    delete data[index];
    data.erase(data.begin() + index);
}

Figure* Array::operator[](size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Ошибка с индексом");
    }
    return data[index];
}

const Figure* Array::operator[](size_t index) const {
    if (index >= data.size()) {
        throw std::out_of_range("Ошибка с индексом");
    }
    return data[index];
}

size_t Array::size() const {
    return data.size();
}

double Array::totalArea() const {
    double sum = 0;
    for (const auto* f : data) {
        sum += f->area();
    }
    return sum;
}
