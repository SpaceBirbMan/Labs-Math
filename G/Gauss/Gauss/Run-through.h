#include "LibConcentrator.h"
#define RANDOM

using namespace std;
using namespace nstd::matio;

void RT(int inv)
{
	int n = 0;
	cin >> n;
	nstd::matrix Rt(n, n);
	nstd::matrix R(n, n + 1);
#ifdef RANDOM
	//Подготовка матрицы
	{ 
		
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
#else
		/*5 8 0 0 0 4
		3 3 3 0 0 5
		0 7 1 2 0 2
		0 0 1 3 1 7
		0 0 0 4 5 2*/
#endif

	//Вычисление
	{
		nstd::matrix X(n);
		nstd::matrix Q(n-1);
		nstd::matrix P(n);

		//Прямой ход
		{
			P(0) = R(0, n) / R(0, 0);
			Q(0) = R(0, 1) / R(0, 0);
			nstd::matrix f(n);
			nstd::matrix l(n);
			nstd::matrix c(n);
			nstd::matrix r(n);

			//столбец свободных коэффициентов
			for (int i = 0; i < n; i++) {
				f(i) = R(i,n);
			}
			//диагональные элементы
			for (int i = 0; i < n; i++) {
				c(i) = R(i,i);
			}
			//леводиагональные элементы
			/*l(0) = 0.0;*/
			for (int i = 1; i < n; i++) {
				l(i) = R(i,i-1);
			}
			//праводиагональные элементы
			/*r(n - 1) = 0.0;*/
			for (int i = 0; i < n - 1; i++) {
				r(i) = R(i,i+1);
			}

			//cout << R(0, 1) << endl;
			//cout << R(1, 0) << endl;
			/*for (int i = 1; i < n; i++)
			{
				P(i) = (R(i, n) - (R(i, i - 1) * P(i - 1)) / (R(i, i) - R(i, i - 1) * Q(i - 1)));
				if (i < (n - 1)) { Q(i) = R(i, i + 1) / (R(i, i) - (R(i, i - 1) * Q(i - 1))); }
			}*/
			for (int i = 1; i < n; i++) {
				P(i) = ((f(i) - (l(i) * P(i - 1))) / (c(i) - (l(i) * Q(i - 1))));
				if (i < (n - 1)) Q(i) = (r(i) / (c(i) - (l(i) * Q(i - 1))));
			}
			//P(n-1) = (R(n-1, n) - R(n-1, n - 1) * P(n - 1)) / (R(n-1, n-1) - R(n-1, n - 1) * Q(n - 1));
		}
		//Обратный ход
		{
			
			X(n - 1) = P(n - 1);

			for (int i = n - 2; i >= 0; i--)//проверить
				X(i) = P(i) - (Q(i) * X(i + 1));
				
		}
		cout << endl;
		m << X;
		
	}
}