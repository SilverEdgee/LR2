#include <iostream>

long double sqrt(long double n);
long double abs(long double n);

int main() {
    long double x1, y1, r, x2, y2, R;
    std::cout << "Введите x1, y1, r, x2, y2, R: ";
    std::cin >> x1 >> y1 >> r >> x2 >> y2 >> R;
    long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d < R - r) {
        std::cout << "Да\n";
    } else if (d < r - R) {
        std::cout << "Да, но справедливо обратное для двух фигур\n";
    } else if (abs(R - r) <= d && d <= R + r) {
        std::cout << "Фигуры пересекаются\n";
    } else {
        std::cout << "Ни одно условие не выполнено\n";
    }
}

long double sqrt(long double n) {
    long double low = 0, high = n;
    if(n < 1)
        low = n, high = 1;
    for(int i = 0; i < 5000; i++) {
        long double mid = (high + low) / 2;
        if (mid * mid < n) low = mid;
        else high = mid;
    }
    return high;
}

long double abs(long double x) {
    return (x < 0) ? -x : x;
}
