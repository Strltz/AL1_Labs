// Lab3_1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	size_t count_of_elements;
	cout << "Введите количество чисел\n";
	cin >> count_of_elements;
	int* m = new int[count_of_elements];
	int p[2] = { -1, 1 };
	m[0] = -1 * (rand() % 10);
	cout << m[0] << " ";
	long int sum0 = 0;
	for (size_t i = 1; i < count_of_elements; ++i)
	{
		m[i] = (rand() % 10) * p[rand() % 2];
		cout << m[i] << " ";
	}
	for (size_t j = 0; j < count_of_elements; ++j)
	{
		if (m[j] < 0)
		{
			sum0 += m[j];
		}
	}
	cout << "\nСумма отрицательных чисел равна " << sum0;
	delete[] m;
}

