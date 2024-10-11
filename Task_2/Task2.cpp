#include <iostream>

int main() {
    double x, y, z;
    std::cout << "Введите стороны x, y, z: ";
    std::cin >> x >> y >> z;

    if (x + y > z && x + z > y && y + z > x) {
        std::cout << "Треугольник существует" << std::endl;
    } else {
        std::cout << "Треугольник не существует" << std::endl;
    }

    return 0;
}
