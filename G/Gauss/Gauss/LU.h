#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include <iostream>
#pragma once


using namespace std;
using namespace matio;

void LU()
{
	int n = 0;
	cin >> n;
	matrix L(n, n);
	matrix U(n, n);
	matrix A(n, n);

	A.randomize_advanced(1, 20);

	L = A;
	U = A;
	
	m << A;

	m << L;
	for (int k = 0; k < n; k++)
	{
		for (int i = k; i < n - 1; i++)
			for (int j = k; j < k; j++)
			{
				if (i > j)
				{
					U(i, j) = (U(i, j) * U(k, k) - U(k, j) * U(i, k)) / U(k, k);
				}
				if (i == j)
				{
					L(i, j) = (L(i, j) * L(k, k) - L(k, j) * L(i, k)) / L(k, k);
					U(i, j) = (U(i, j) * U(k, k) - U(k, j) * U(i, k)) / U(k, k);
				}
				if (i < j)
				{
					L(i, j) = (L(i, j) * L(k, k) - L(k, j) * L(i, k)) / L(k, k);
				}
			}
		for (int i = k + 1; i < n; i++)
		{
			U(i, k) = 0;
			L(k, i) = 0;
		}
	}
	m << L;
	m << U;

	for (int i = 0; i < n; i++)
	{
		A(i, 0) = L(i, 0);
		U(0, i) = A(0, i) / L(0, 0);

		for (int k = 2; k < n; k++)
		{
			float sum0, sum, sum2 = 0;
			for (int m = 0; m < k-1; m++)
			{
				sum0 = L(i, m) * U(m, 1);
				sum = L(i, m) * U(m, k);
				sum2 = L(k, m) * U(m, i);
			}
			L(i, 1) = A(i, 1) - sum0;
			L(i, k) = A(i, k) - sum;
			U(k, i) = (1 / L(k, k)) * (A(k, i) - sum2);
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
