/* Лабораторная2_1.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.
  
  Вариант 19 Вычислить, организовав цикл с точностью =10-2,…, 10-6. Определить, как меняется число итераций в зависимости от точности.
 .

*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


long long int fact(int i) // функция факториала
{
    long long int f = 1;
    for (int j = 1; j <= i; j++)
    {
        f *= j;
    }
    return f;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int x;
    cout << "vvedite x" << endl;
    cin >> x;
    for (int t = 2; t <= 6; t++)
    {
        long double tochnost = pow(10, -t);
        cout << tochnost;
        long double  znach_sleva = cos(x);
        long double znach_sprava = 0.0;
        int iter = 0;               // то же , что n, или же число итераций к данному моменту и в конце - итоговое количество итераций
        while (abs(znach_sleva - znach_sprava) > tochnost)
        {
            iter++;
            znach_sprava += pow(-1, iter) * pow(x, 2 * iter) / fact(2 * iter);
            
        }
        cout << "Точность -" << t << ": значение " << znach_sprava << "; кол-во итераций " << iter << endl;
    }
}
