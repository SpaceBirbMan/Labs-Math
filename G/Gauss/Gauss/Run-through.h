#include <iostream>
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"

using namespace std;


void RT()
{
	int n = 0;
	cin >> n;
	matrix Rt(n, n);
	matrix R(n, n + 1);

	//Подготовка матрицы
	{ 
		
		//todo: Функция прямого хода straight_stroke(количество диагоналей, которые должны остаться (по умолчанию 1))

		Rt.randomize_advanced(1, 10);
		R.randomize_advanced(1, 10);

		Rt.diag_antizero(0, 0);
		Rt.diag_antizero(1, 0);
		//Rt.diag_antizero(0, 1);

		R = Rt;
		m << R;
		cout << endl;

		for (int i = 2; i < n; i++)
			Rt.diag_replace(i, 0);
		for (int i = 2; i < n; i++)
			Rt.diag_replace(0, i);

		R = Rt;
		m << R;
		cout << endl;

	}
	//Вычисление
	{
		matrix X(n);
		for (int i = 1; i < n; i++) {
			double coef = R(i, i - 1) / R(i - 1, i - 1);
			R(i, i) -= coef * R(i - 1, i - 1);
			R(i, n + 1) -= coef * R(i - 1, n + 1);
		}
		m << R;
		cout << endl;

		X(n - 1) = R(n - 1, n + 1) / R(n - 1, n - 1);
		for (int i = n - 2; i >= 0; i--) {
			double sum = R(i, n + 1);
			for (int j = i + 1; j < n; j++) {
				sum -= R(i, j) * X(j);
			}
			X(i) = sum / R(i, i);
		}
		cout << endl;
		m << X;
		
	}
}