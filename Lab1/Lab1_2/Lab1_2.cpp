﻿/* Lab1_2.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.

Variant 19
Определить, попадает ли точка M(x, y) в круг радиусом r с центром в точке (x0, y0) */

#include <iostream>
using namespace std;

int  main()
{
	setlocale(LC_ALL, "ru");
	double r, x0, y0, x, y;
	cout << "Введите радиус и координаты центра круга (х0 и у0): сначала радиус, потом х0, затем у0,после ввода каждого значения нажимайте Enter\n";
	cin >> r >> x0 >> y0;
	cout << "Введите координаты точки (x и y)\n";
	cin >> x >> y;
	if (((x - x0) * (x - x0) + (y - y0) * (y - y0)) < r*r)
	{
		cout << "Попадает";
	}
	else if ((((x - x0) * (x - x0) + (y - y0) * (y - y0))) == r*r)
	{
		cout << "Точка лежит на окружности";
	}
	else
	{
		cout << "Не попадает";
	}
}