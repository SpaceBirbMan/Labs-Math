#pragma once
#include "LibConcentrator.h"

float f1(float x)
{
	return 1 / (sqrt((2 * x * x) + 8));
}

float f2(float x)
{
	return cos((x * x) - 1) / ((x * x) + 2);
}

void I()
{
	// интеграл от 0.5 до 1.5 (dx/(sqrt(2x^2 + 8))
	// интеграл от 1.2 до 2.0 ((cos(x^2-1)/(x^2 + 2))dx)

	int n = 10;
	float a = 0.5;
	float b = 1.5;
	float h = (b - a) / n;
	float s = 0;
	for (int k = 1; k <= n - 1; ++k)
		s += f1(a + k * h);
	s = (h / 2) * (f1(a) + f1(b) + 2 * s);

	std::cout << s << '\n';

	//0.013905
	n = 50;
	int m = n / 2;
	a = 1.2;
	b = 2.0;
	h = (b - a) / n;
	float s1 = 0;
	for (int k = 1; k <= m; ++k)
		s1 += f2(a + (2 * k - 1) * h);
	float s2 = 0;
	for (int k = 1; k <= m - 1; k++)
		s2 += f2(a + 2 * k * h);
	s = (h / 3) * (f2(a) + f2(b) + 4 * s1 + 2 * s2);
	std::cout << s;
}