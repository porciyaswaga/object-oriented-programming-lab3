#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "Array.h"

int main() {
    Array arr;

    int n;
    std::cout << "Введите кол-во фигур: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int type;
        std::cout << "Введите тип фигуры (1 - квадрат, 2 - прямоугольник, 3 - трапеция): ";
        std::cin >> type;

        Figure* fig = nullptr;

        if (type == 1) fig = new Square();
        else if (type == 2) fig = new Rectangle();
        else if (type == 3) fig = new Trapezoid();
        else {
            std::cout << "Неверный тип\n";
            --i;
            continue;
        }

        std::cin >> *fig;
        arr.push(fig);
    }

    std::cout << "\nИнформация о фигурах\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        auto* f = arr[i];
        std::cout << *f;
        auto c = f->geometricCenter();
        std::cout << "Центр: (" << c.first << ", " << c.second << ")\n";
        std::cout << "Площадь: " << f->area() << "\n\n";
    }

    std::cout << "Суммарная площадь: " << arr.totalArea() << "\n";
}
