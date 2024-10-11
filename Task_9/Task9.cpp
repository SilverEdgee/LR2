#include <iostream>
#include <cmath>

int main() {
    int q;
    double a, b, z, x, y;
    std::cout << "Введите a, b, z: ";
    std::cin >> a >> b >> z;
    if (z <= 0) {
        x = z * z / 2;
    } else {
        x = sqrt(z);
    }
    std::cout << "Введите значение для q (1, 2 или 3): ";
    std::cin >> q;
    switch (q) {
        case 1:
            q = 2 * x;
            break;
        case 2:
            q = pow(x, 3);
            break;
        case 3:
            q = x / 3;
            break;
        default:
            std::cout << "Неверное значение q!" << std::endl;
            return 1;
    }
    y = b * q / cos(x) + a * log(abs(tan(x / 2)));

    std::cout << "Полученное значение y: " << y << std::endl;

    return 0;
}