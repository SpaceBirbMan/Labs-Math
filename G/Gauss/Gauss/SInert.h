#pragma once
#include <iostream>
#include <cmath>
#include "C:\Users\kiril\OneDrive\Ðàáî÷èé ñòîë\FINAL_COUNTDOWN\FINAL_COUNTDOWN\matrx.h" //библиотека из репозитория EXPER MATRIX

using namespace std;

void SIter(int kc)
{
	setlocale(LC_ALL, "russian");
	int n = 5;

	nonstd::matrix <int> A(n, n + 1);
	float* XN = new float[n];
	float* XO = new float[n];

		A(0, 0) = 28; A(0, 1) = 1; A(0, 2) = 1; A(0, 3) = 1; A(0, 4) = 3; A(0, 5) = 38; 
		A(1, 0) = 2; A(1, 1) = 23; A(1, 2) = 3; A(1, 3) = 4; A(1, 4) = 2; A(1, 5) = 67;
		A(2, 0) = 5; A(2, 1) = 2; A(2, 2) = 39; A(2, 3) = 1; A(2, 4) = 3; A(2, 5) = 131;
		A(3, 0) = 2; A(3, 1) = 4; A(3, 2) = 2; A(3, 3) = 24; A(3, 4) = 2; A(3, 5) = 66;
		A(4, 0) = 2; A(4, 1) = 2; A(4, 2) = 5; A(4, 3) = 3; A(4, 4) = 34; A(4, 5) = 61;
	
	float EPS = 0.0001;
	n = A.get_row_count();
	int itr = 0;

	cout << A;

	bool fl = true;
	while (true)
	{
		fl = true;
		itr += 1;

		for (int k = 0; k < n; k++)
		{
			XN[k] = A(k, n);
			for (int j = 0; j < n; j++)
				if (j != k)
					if (kc == 1)
					XN[k] = XN[k] - A(k, j) * XO[j]; //итерации
					else
					XN[k] = XN[k] - A(k, j) * XN[j]; //зейдель
			XN[k] = XN[k] / A(k, k);
			if (abs(XN[k] - XO[k]) > EPS) fl = false;
		}
		string outstr = "Итер. " + to_string(itr);
		for (int e = 0; e < n; e++)
			outstr += " " + to_string(XN[e]);
		cout << outstr << endl;
		
		for (int i = 0; i < n; i++)
			XO[i] = XN[i];
		if (fl) break;
	}
}
