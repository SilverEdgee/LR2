#include <iostream>

int main() {
    double b1;
    const int n = 23; // номер в журнале
    double q = 1.0 / (n + 1);
    std::cout << "Введите первый член геометрической прогрессии: ";
    std::cin >> b1;
    double sum = b1 / (1 - q);
    std::cout << "Результат - " << sum << std::endl;

    return 0;
}
