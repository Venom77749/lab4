#include <iostream>
#include <limits>
#include "LineSegment.h"

double readDouble(const char* value)
{
    double x;
    while (true) {
        std::cout << value;
        if (std::cin >> x) {
            return x;
        }
        std::cout << "Ошибка ввода, введите число заново.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    std::cout << "Введите координаты двух отрезков на числовой прямой.\n";

    double a1 = readDouble("Отрезок 1: начало = ");
    double b1 = readDouble("Отрезок 1: конец  = ");

    double a2 = readDouble("Отрезок 2: начало = ");
    double b2 = readDouble("Отрезок 2: конец  = ");

    LineSegment s1(a1, b1);
    LineSegment s2(a2, b2);

    std::cout << "Отрезок 1: " << s1 << "\n";
    std::cout << "Отрезок 2: " << s2 << "\n";

    bool inter = s1.intersects(s2);
    std::cout << std::boolalpha;
    std::cout << "Пересекаются ли отрезки? " << inter << "\n";

    LineSegment s3;
    LineSegment s4(5.1);

    std::cout << "Тест конструкторов:\n";
    std::cout << "s3 (по умолчанию): " << s3 << "\n";
    std::cout << "s4 (точка 5.1):    " << s4 << "\n" << std::endl;

    std::cout << "2 ЗАДАНИЕ" << std::endl;

    std::cout << "Длина отрезка s1: " << !s1 << "\n";

    ++s1;
    std::cout << "После ++s1: " << s1 << "\n";

    s2++;
    std::cout << "После s2++: " << s2 << "\n";

    int ix = s1;               
    double dy = static_cast<double>(s2);
    std::cout << "ix = " << ix << ", dy = " << dy << "\n";

    s3 = s1 - 2;
    std::cout << "s3 = s1 - 2: " << s3 << "\n";

    bool cross = s1 < s2;
    std::cout << "Отрезки s1 и s2 " << (cross ? "пересекаются" : "не пересекаются") << "\n";


    return EXIT_SUCCESS;
}
