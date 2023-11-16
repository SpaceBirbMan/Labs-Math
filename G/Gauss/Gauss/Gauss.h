#define CHOOSE 0
#include <iostream>
#include <vector>
#include "C:\Users\kiril\OneDrive\Рабочий стол\Библиотека\matrix.h"
#include "C:\Users\kiril\OneDrive\Рабочий стол\FINAL_COUNTDOWN\FINAL_COUNTDOWN\matrx.h"

using namespace matio;

void Gauss(int inv)
{


	std::cout.precision(2);

	int n = 2;

	std::cin >> n;

	
#if CHOOSE /*<= inv*/
	matrix F(n, n + 1);
	matrix M(n);

	matrix MJG(n, n + 1);

	F.randomize_advanced(-10, 10); //заполнение
	m << F;
	unsigned int k = 1;
	unsigned int km = 0;

	for (k = 1; k <= n; k++) //прямой ход
	{
		km = k - 1;
		if (abs(F(km,km)) < 0.000001)
		{
			for (int i = 0; i < km - 1; i++)
				if (F.M[i][km] != 0)
				{
					M = F(i,km);
					F.M[i][km] = F(km,km);
					F.M[km][km] = *M.A;
					m << F;
				}			
		}


		for (int i = km; i < n - 1; i++) 
			for (int j = km; j < km; j++)
			{
				F.M[i][j] = (F.M[i][j] * F.M[km][km] - F.M[km][j] * F.M[i][km]) / F.M[km][km];
			}
		m << F;

		for (int i = km+1; i < n; i++) //зануление
			F.M[i][km] = 0;
		m << F;

		for (int i = n; i >= 0; i--) //деление на ведущий элемент
		{
			if (F.M[km][km] != 0)
				F.M[km][i] = F.M[km][i] / F.M[km][km];
			else abort;
		}
		m << F;
	}

	float* x = new float[n];

	std::cout << std::endl;

	float y = 0;

	MJG = F;

	///Гаусс

	for (int a = n - 1; a >= 0; a--) //обратный ход
	{
		if (a == n - 1)
			x[a] = F(a,n);
		else
		{
			x[a] = F.M[a][n];
			for (int b = n - 1; b >= a + 1; b--)
			{
				//std::cout << x[a] << " " << x[b] << " " << F.M[a][b] << "\n";
				x[a] = x[a] - x[b] * F.M[a][b];
			}
		}
	}

	

	///Гаусс - Жордан

	//обратный ход

	using namespace std;

	int i = n - 1;

	for (int j = n; j > 0; j--)
	{
		int i = n - 1 - (n - j); //ограничевает i 
		for (i; i > 0; i--)
		{
			MJG.M[i-1][n] = (MJG.M[i-1][n] + (MJG.M[j-1][n] * -1 * MJG.M[i-1][j-1])); 
		}
		m << MJG;
	}

	for (int j = 0; j < n; j++) //нули
		for (int i = 0; i < n; i++)
		{
			if (i == j)
				MJG.M[j][i] = 1;
			else
				MJG.M[j][i] = 0;
		}
			
				

		
	m << MJG;

	cout << endl;

	cout << "Gauss" << endl;
	for (int r = 0; r < n; r++)
	{
		cout << "x" << r + 1 << " " << x[r] << endl;
	}

	cout << '\n';

	cout << "Gauss - Jordan" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " " << MJG.M[i][n] << endl;
	}
	cout << endl << endl;
#else
	nonstd::matrix <double> F2(n, n);
	F2.randomize_advanced(1, 10);
//nonstd::matrix <double> F2(
//	{ 
//	{2, 1, 2, 3, 9},
//	{2, 5, 3, 5, 4},
//	{2, 1, 5, 5, 7},
//	{4, 8, 3, 7, 7},
//	{1, 7, 5, 7, 5} 
//	});

	std::cout << F2 << std::endl;
	F2.inverse();
	std::cout << F2;
#endif
}
