// Lab5_3_mb_itog.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "Header.h"

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    int num = n - 1;
    std::cout << "Numbers:\n";
    int m = 0;
    while (n != num)
    {
        std::cin >> num;
        m = check_max(num, m);
    }
    std::cout << "MAX: " << m;
}
