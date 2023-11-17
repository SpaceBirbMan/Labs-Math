#define CHOOSE 0
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include "C:\Users\kiril\OneDrive\Рабочий стол\FINAL_COUNTDOWN\FINAL_COUNTDOWN\matrx.h"
#include <iostream>
#pragma once


using namespace std;
using namespace matio;

void LU(int inv)
{
#if CHOOSE
	int n = 0;
	cin >>  n;
	matrix L(n, n), U(n, n), A(n, n+1);
	matrix X(n), Y(n), B(n);
	
	L >> 0; //инициализация матриц нулями
	U >> 0;

	A.randomize_advanced(1, 20);
	
	B = A += n+1; //копия столбца в массив

	B << B; //вывод
	A << A; //вывод 


	{
		for (int i = 0; i < n; i++)
			L(i, 0) = A(i, 0);
		for (int j = 1; j < n; j++)
			U(0, j) = A(0, j) / L(0, 0);

		for (int k = 1; k < n; k++)
		{
			for (int i = k; i < n; i++)
			{
				L(i, k) = A(i, k);
				for (int m = 0; m < k; m++)
					L(i, k) = L(i, k) - L(i, m) * U(m, k);
			}

			if (k <= n - 1)
				for (int j = k + 1 ; j < n; j++)
				{
					U(k, j) = A(k, j);
					for (int m = 0; m < k; m++)
						U(k, j) = U(k,j) - L(k, m) * U(m,j);
					U(k, j) = U(k, j) / L(k, k);
				}
		}
	}
	
	L << L;
	U << U;

	{
		Y(0) = B(0) / L(0,0);

		for (int i = 1; i < n; i++)
		{
			Y(i) = B(i);
			for (int m = 0; m < i; m++)
				Y(i) = Y(i) - L(i, m) * Y(m);
			Y(i) = Y(i)/L(i,i);
		}
	}

	{
		X(n - 1) = Y(n - 1);

		for (int i = n - 1; i >= 0; i--)
		{
			X(i) = Y(i);
			for (int m = i + 1; m < n; m++)
				X(i) = X(i) - U(i, m) * X(m);
		}
	}

	X << X;

#else
	int n = 0;
	cin >> n;

	nonstd::matrix <float> A(n, n);
	A.randomize_advanced(1, 10);
	A.inverse("lu");
	cout << A;
#endif
}
//int i = n - 1;
//
//for (int j = n; j > 0; j--)
//{
//	int i = n - 1 - (n - j); //ограничевает i 
//	for (i; i > 0; i--)
//	{
//		U.M[i - 1][n] = (U.M[i - 1][n] + (U.M[j - 1][n] * -1 * U.M[i - 1][j - 1]));
//	}
//	m << U;
//}
//
//for (int j = 0; j < n; j++) //нули
//	for (int i = 0; i < n; i++)
//	{
//		U.M[j][i] = 1;
//	}
