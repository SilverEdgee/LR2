#include <iostream>
long double sqrt(long double n);
long double abs(long double x);
long double cos(long double x);
long double arccos(long double x);
long double side_measurement(long double x1, long double x2, long double y1, long double y2);
long double height_measurement(long double x1, long double x2, long double y1, long double y2, long double m, long double n);
long double median_measurement(long double x1, long double x2, long double y1, long double y2, long double m, long double n);
long double bisector_measurement(long double a, long double b, long double c);
long double angle_measurement(long double x1, long double x2, long double y1, long double y2, long double x3, long double y3);

int main() {
    long double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите x1, y1, x2, y2, x3, y3: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    long double first_side = side_measurement(x1, x2, y1, y2);
    long double second_side = side_measurement(x2, x3, y2, y3);
    long double third_side = side_measurement(x1, x3, y1, y3);

    long double first_height = height_measurement(x2, x3, y2, y3, x1, y1);
    long double second_height = height_measurement(x1, x3, y1, y3, x2, y2);
    long double third_height = height_measurement(x1, x2, y1, y2, x3, y3);

    long double first_median = median_measurement(x2, x3, y2, y3, x1, y1);
    long double second_median = median_measurement(x1, x3, y1, y3, x2, y2);
    long double third_median = median_measurement(x1, x2, y1, y2, x3, y3);

    long double first_bisector = bisector_measurement(first_side, second_side, third_side);
    long double second_bisector = bisector_measurement(second_side, third_side, first_side);
    long double third_bisector = bisector_measurement(third_side, first_side, second_side);

    long double first_angle = angle_measurement(x2, x3, y2, y3, x1, y1);
    long double second_angle = angle_measurement(x1, x3, y1, y3, x2, y2);
    long double third_angle = angle_measurement(x1, x2, y1, y2, x3, y3);
    long double S1 = 0.5 * first_side * third_height;
    long double S2 = 0.5 * first_side * second_side * sqrt(1 - cos(second_angle) * cos(second_angle));
    
    long double R = first_side * second_side * third_side / (4 * S1 == 0 ? 1 : 4 * S1);
    long double p = (first_side + second_side + third_side) / 2;
    long double r = S1 / p;

    long double S3 = sqrt(p * (p - first_side) * (p - second_side) * (p - third_side));
    
    long double pi = arccos(-1);
    long double S_of_R = pi * R * R, S_of_r = pi * r * r;
    long double L = 2 * pi * R, l = 2 * pi * r;
    long double P = first_side + second_side + third_side;

    std::cout << "Длины сторон треугольника: " << first_side << " " << second_side << " " << third_side << "\n";
    std::cout << "Длины высот треугольника: " << first_height << " " << second_height << " " << third_height << "\n";
    std::cout << "Длины медиан треугольника: " << first_median << " " << second_median << " " << third_median << "\n";
    std::cout << "Длины биссектрис треугольника: " << first_bisector << " " << second_bisector << " " << third_bisector << "\n";
    std::cout << "Градусная/радианная мера углов треугольника: " << first_angle * 180/pi << "°/" << first_angle << " "
              << second_angle * 180/pi << "°/" << second_angle << " " << third_angle * 180/pi << "°/" << third_angle << "\n";
    std::cout << "Радиусы вписанной и описанной окружностей треугольника: " << r << " " << R << "\n";
    std::cout << "Длины вписанной и описанной окружностей треугольника: " << l << " " << L << "\n";
    std::cout << "Площади вписанной и описанной окружностей треугольника: " << S_of_r << " " << S_of_R << "\n";
    std::cout << "Периметр и площадь треугольника тремя способами: " << P << " " << S1 << " " << S2 << " " << S3 << "\n";
}

long double sqrt(long double n) {
    long double low = 0, high = n;
    if (n == 0) return 0;
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

long double cos(long double x) {
    long double n = 1, coef = 1, sum = coef;
    for (int i = 0; i < 5000; i++) {
        coef *= -x * x / (n * (n + 1));
        sum += coef;
        n += 2;
    } 
    return sum;
}

long double arccos(long double x) {
    long double low = 0, high = 3.14159265359, accuracy = 1e-14, mid = 0;
    for (int i = 0; i < 5000; i++) {
        mid = (high + low) / 2;
        if (cos(mid) > x) low = mid;
        else high = mid;
    }
    return mid;
}

long double side_measurement(long double x1, long double x2, long double y1, long double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

long double height_measurement(long double x1, long double x2, long double y1, long double y2, long double m, long double n) {
    long double A = y2 - y1, B = x1 - x2, C = -(y2 - y1) * x2 - (x1 - x2) * y2;
    return abs(A * m + B * n + C) / (sqrt(A * A + B * B) == 0 ? 1 : sqrt(A * A + B * B));
}

long double median_measurement(long double x1, long double x2, long double y1, long double y2, long double m, long double n) {
    long double x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
    return sqrt((m - x0) * (m - x0) + (n - y0) * (n - y0));
}

long double bisector_measurement(long double a, long double b, long double c) {
    return sqrt(a * b * (a + b + c) * (a + b - c)) / (a + b);
}


long double angle_measurement(long double x1, long double x2, long double y1, long double y2, long double x3, long double y3) {
    long double a = side_measurement(x1, x2, y1, y2); 
    long double b = side_measurement(x2, x3, y2, y3); 
    long double c = side_measurement(x1, x3, y1, y3);
    if (a == 0 || b == 0 || c == 0) {
        return 0;
    }
    long double cos_angle = (b * b + c * c - a * a) / (2 * b * c);
    return arccos(cos_angle);
}