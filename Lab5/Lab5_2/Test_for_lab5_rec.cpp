// Test_for_lab5_rec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    int num = n - 1;
    int max_num = 0;
    max_of_numbers(num, n, max_num);
}
