#include <iostream>

int main() {
    int  X, Y; 
    double A, B, C, K;
    std::cout << "Введите переменные X, Y, A, B, C, K: ";
    std::cin >> X >> Y >> A >> B >> C >> K;
    if (X < Y) {
        X = 0;
    }
    else if (X > Y) {
        Y = 0;
    } else {
        X = Y = 0;
    }
    if (A > B && A > C) {
        A -= K;
    } else if (B > A && B > C) {
        B -= K;
    } else {
        C -= K;
    }
    std::cout << "X = " << X << std::endl;
    std::cout << "Y = " << Y << std::endl;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    std::cout << "C = " << C << std::endl;

    return 0;
}
