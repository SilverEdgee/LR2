#include <iostream>

int main() {
    double x,y;
    std::cout << "Введите x, y: ";
    std::cin >> x >> y;
    if (x == 0 && y == 0) {
        std::cout << "НОД не определен";
    }    
    if (x == 0 || y == 0) {
        std::cout << "НОД = " << (x == 0 ? x : y);
    }
    while (x != y ) {
        std::cout << "x = " << x << "\ty = " << y << "\n";
        if (x > y) {
            x -= y;
        }
        else {
            y -= x;
        }
    }
    std::cout << "y = " << y << "\tx = " << x << "\n";
    std::cout << "НОД двух чисел = " << y << std::endl;

}