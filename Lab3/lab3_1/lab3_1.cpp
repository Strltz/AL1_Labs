// lab3_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Заданы целые числа a1, a2,…, an. Написать программу, которая находит сумму отрицательных элементов 
// (при формировании массива обеспечить, чтобы были отрицательные элементы).
//

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	const unsigned count_of_elements = 10;
	int m[count_of_elements];
	cout << "Введите количество элементов\n";
	m[0] = -1 * (rand() % 10);
	long int summ0 = 0;
	int p[2] = {1, -1};
	cout << m[0] << " ";
	for (size_t i = 1; i < count_of_elements; ++i)
	{
		m[i] = p[rand() % 2] * (rand() % 10);
		cout << m[i]  << " ";
	}
	size_t j = 0;
	cout << endl;
	while (j < count_of_elements)
	{
		if (m[j] < 0)
		{
			summ0 += m[j];
		}
		++j;
	}
	cout << "Сумма отрицательных элементов равна " << summ0;
}
