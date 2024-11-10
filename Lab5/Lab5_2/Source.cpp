
#include "Header.h"
#include <iostream>

void max_of_numbers(int num, int n, int max_num)
{
    if (n != num)
    {
        std::cout << "Number: ";
        std::cin >> num;
        max_num = std::max(max_num, num);
        max_of_numbers(num, n, max_num);
    }
    else
    {
        std::cout << "MAX: " << max_num;
        return;
    }
}
