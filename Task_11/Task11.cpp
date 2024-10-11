#include <iostream>

int main() {
    int h1, min1, h2, min2;
    std::cout << "Введите время начала (часы и минуты): ";
    std::cin >> h1 >> min1;
    
    std::cout << "Введите время окончания (часы и минуты): ";
    std::cin >> h2 >> min2;
    if (h1 > 24 || h2 > 24 || min1 > 60 || min2 > 60) {
        std::cout << "Введите правильный формат времени" << std::endl;
        return 1;
    }
    int start_minutes = h1 * 60 + min1;
    int end_minutes = h2 * 60 + min2;
    if (end_minutes < start_minutes) {
        end_minutes += 24 * 60;
    }
    int total_minutes = end_minutes - start_minutes;
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;
    std::cout << "Студент решал задачи: " << hours << " часов и " << minutes << " минут." << std::endl;
    
    return 0;
}
