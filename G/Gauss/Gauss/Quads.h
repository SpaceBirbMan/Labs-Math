#pragma once
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include <iostream>
#include <cmath>

void Quads(int inv)
{

	int n = 0;
	cin >> n;

	matrix A(n, 1 + n), L(n, n), U(n, n);
	matrix B(n), Y(n), X(n);

	A.randomize_advanced(0, 10);

	B = A += n + 1;
	
	A << A;

	L >> 0;
	U >> 0;

	{
		L(0, 0) = sqrt(A(0, 0));

		for (int i = 0; i < n; i++)
			L(i, 0) = A(i, 0) / L(0, 0);

		for (int k = 1; k < n; k++)
		{
			float sqSum = 0;
			for (int m = 0; m < k; m++)
				sqSum = sqSum + L(k, m) * L(k, m);
			L(k, k) = sqrt(A(k, k) - sqSum);
			if (k < n)
				for (int i = k + 1; i < n; i++)
				{
					float pairSum = 0;
					for (int m = 0; m < k; m++)
						pairSum = pairSum + L(i, m) * L(k, m);
					L(i, k) = (A(i, k) - pairSum) / L(k, k);
				}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				U(i, j) = L(j, i);

	}

	L << L;
	U << U;

	{
		Y(0) = B(0) / L(0, 0);

		for (int i = 1; i < n; i++)
		{
			Y(i) = B(i);
			for (int m = 0; m < i - 1; m++)
				Y(i) = Y(i) - L(i, m) * Y(m);
			Y(i) = Y(i) / L(i, i);
		}
	}

	Y << Y;

	{
		X(n - 1) = Y(n - 1) / U(n - 1, n - 1);
		for (int i = n - 1 /* n - 2*/; i >= 0; i--)
		{
			X(i) = Y(i);
			for (int m = i + 1; i < n; m++)
				X(i) = X(i) - U(i, m) * X(m);
			X(i) = X(i) / U(i, i);
		}
	}

	X << X;
}