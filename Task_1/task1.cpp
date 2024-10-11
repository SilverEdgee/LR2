 #include <iostream>

int main() {
    std::cout << "Введите x - "; 
    double x;
    std::cin >> x;
    double x2 = x * x;   //1
    double r = 69 * x2 + 8; //2
    double t = x * (23 * x2 + 32); //3

   std::cout << "Результат первого выражения - " << r + t << std::endl;
   std::cout << "Результат второго выражения - " << r - t << std::endl;

    return 0;
}
