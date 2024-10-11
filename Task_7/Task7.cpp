#include <iostream>

int main() {
    long double a, b, c;
    int N;
    std::cout << "Введите N, a, b, c: ";
    std::cin >> N >> a >> b >> c;
    switch(N) {
        case 2:
        std::cout << "Результат выражения - " << b * c - a * a << std::endl;
        break;
        case 56:
        std::cout << "Результат выражения - " << b * c << std::endl;
        break;
        case 7:
        std::cout << "Результат выражения - " << a * a + c << std::endl;
        break;
        case 3:
        std::cout << "Результат выражения - " << a - b * c << std::endl;
        break;
        default:
        std::cout << "Результат выражения - " << (a + b) * (a + b) * (a + b) << std::endl;
        break;
    }
}