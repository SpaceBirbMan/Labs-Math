#pragma once
#include "LibConcentrator.h"
float f(float x)
{
	return pow(sin(x), 3);
}
void iDiff()
{
	/*
	f(x) = sin^3x, x0 = pi/4, M1 = 21, M2 = 183
	*/

	float pi = 3.141592654;
	int M1 = 21;
	int M2 = 183;
	float x0 = pi / 4;
	float eps = 0.001;
	float h1 = 0;
	float h2 = 0;
	std::cout << "F1 " << pow((6 * eps / M1), 0.5) << std::endl;
	std::cin >> h1;
	float diff1 = (f(x0 + h1) - f(x0 - h1)) / (2 * h1);
	std::cout << "F2 " << pow((30 * eps/M2), 0.25) << std::endl;
	std::cin >> h2;
	float diff2 = (f(x0 - 2 * h2) - 8 * f(x0 - h2) + 8 * f(x0 + h2) - f(x0 + 2 * h2)) / (12 * h2);
	std::cout << diff1 << " " << diff2 << std::endl << "\n";

	/*
	-50 -45 -40 -35 -30 -25 -20 -15
	7.88745 8.07634 8.27774 8.49344 8.72562 8.97700 9.25107 9.55231
	*/

	nonstd::matrix<float> xi({ { -50, -45, -40, -35, -30, -25, -20, -15 } }); // Увеличил количество элементов в массиве xi
	nonstd::matrix<float> yi({ {7.88745, 8.07634, 8.27774, 8.49344, 8.72562, 8.97700, 9.25107, 9.55231} });
	//nonstd::matrix<float> xi({ { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7 } }); 
	//nonstd::matrix<float> yi({ {1, 0.9950, 9.9801, 0.9553, 0.9211, 0.8776, 0.8441, 0.8082} });
	nonstd::matrix<float> X(8);
	nonstd::matrix<float> Y(8, 8); 
	nonstd::matrix<float> r(12, 12);
	float kmx = -45;
	float h = 0.1;
	for (int i = 0; i < 8; ++i)
	{
		X(i) = kmx + h * i; //*
		Y(i, 0) = pow((1 + X(i) * X(i)), 0.5);
		r(i, 1) = i;
		r(i, 2) = X(i);
		r(i, 3) = Y(i, 0);
	}
	for (int j = 1; j < 8; ++j) 
		for (int i = 0; i < 8 - j; ++i) 
		{
			Y(i, j) = Y(i + 1, j - 1) - Y(i, j - 1);
			r(i, j + 3) = Y(i, j);
		}
	float s = 0;
	float d = -1;
	float delta = 0;
	for (int j = 1; j < 7; ++j)
	{
		d = (-1) * d;
		s = s + d * Y(0, j) / (j * h);
		
			delta = abs(Y(0, j + 1) / ((j + 1) * h));
			r(9, j + 3) = s; // Изменил индекс столбца
			std::cout << "s " << s << std::endl;
			r(10, j + 3) = delta; // Изменил индекс столбца
			std::cout << "dlt " << delta << std::endl;
		
	}

	std::cout << r << std::endl;
}