#pragma once
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include <iostream>
#include <cmath>

void Quads(int inv)
{

	int n = 5;

	matrix A(n, 1 + n), L(n, n), U(n, n);
	matrix B(n), Y(n), X(n);

	/*A.randomize_advanced(0, 10);*/

	A(0, 0) = 9; A(0, 1) = 6; A(0, 2) = 3; A(0, 3) = 1; A(0, 4) = 3; A(0, 5) = 35;
	A(1, 0) = 6; A(1, 1) = 8; A(1, 2) = 4; A(1, 3) = 4; A(1, 4) = 6; A(1, 5) = 48;
	A(2, 0) = 3; A(2, 1) = 4; A(2, 2) = 4; A(2, 3) = 1; A(2, 4) = 4; A(2, 5) = 29;
	A(3, 0) = 1; A(3, 1) = 4; A(3, 2) = 1; A(3, 3) = 8; A(3, 4) = 3; A(3, 5) = 31;
	A(4, 0) = 3; A(4, 1) = 6; A(4, 2) = 4; A(4, 3) = 3; A(4, 4) = 9; A(4, 5) = 41;
	//проверка на невырожденность в новой матрице
		

	B = A += n + 1;
	
	A << A;

	L >> 0;
	U >> 0;

	{
		L(0, 0) = sqrt(A(0, 0));

		for (int i = 1; i < n; i++)
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
			for (int m = 0; m < i; m++)
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
			for (int m = i + 1; m < n; m++)
				X(i) = X(i) - U(i, m) * X(m);
			X(i) = X(i) / U(i, i);
		}
	}

	X << X;
}