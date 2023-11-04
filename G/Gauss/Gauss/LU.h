#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include <iostream>
#pragma once


using namespace std;
using namespace matio;

void LU(int inv)
{
	int n = 0;
	cin >>  n;
	matrix L(n, n), U(n, n), A(n, n);
	matrix X(n), Y(n), B(n);



	float sum1 = 0, sum2 = 0;

	
	L >> 0;
	U >> 0;

	A.randomize_advanced(1, 20);
	
	B = A += n;

	B << B;
	A << A;

	float f = L(1, 1);

	{
		
		for (int i = 0; i < n; i++)
		{
			L(i, 0) = A(i, 0);
			U(0, i) = A(0, i) / f;
		}

		for (int k = 1; k < n; k++)
		{
			float f2 = L(k, k);

			for (int i = k; i < n; i++)
			{
				for (int m = 0; m < k; m++)
					sum1 = sum1 + L(i, m) * U(m, k);
				L(i, k) = A(i, k) - sum1;
			}

			for (int j = k + 1; j < n; j++)
			{
				for (int m = 0; m < k; m++)
					sum2 = sum2 + L(k, m) * U(m, j);
				U(k, j) = (1 / f2) * (A(k, j) - sum2);
			}
		}
	}
	
	L << L;
	U << U;

	{
		Y(0) = B(0) / f;

		float sum = 0;

		for (int i = 1; i < n; i++)
		{
			for (int m = 0; m < i - 1; m++)
				sum = L(i,m)*Y(m);
			Y(i) = (1 / L(i, i)) * (B(i) - sum);
		}
	}


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
