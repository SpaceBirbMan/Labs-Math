#pragma once
#include "LibConcentrator.h"

using namespace std;
using namespace nonstd;

// Подпрограмма перемены местами строк в матрице
template <typename T>
void SwapRows(nonstd::matrix<T>& mx, int i, int j)
{
    for (int k = 0; k < mx.get_col_count(); ++k)
    {
        T temp = mx(i, k);
        mx(i, k) = mx(j, k);
        mx(j, k) = temp;
    }
}

// Подпрограмма решения СЛАУ методом Жордана-Гаусса
template <typename T>
void JG(nonstd::matrix<T>& F, int n)
{
    nonstd::matrix<T> M(n);
    nonstd::matrix<T> MJG(n, n + 1);
    unsigned int k = 1;
    unsigned int km = 0;

    for (k = 1; k <= n; k++) //прямой ход
    {
        km = k - 1;
        if (abs(F(km, km)) < 0.000001)
        {
            for (int i = 0; i < km; i++) // изменено условие здесь
            {
                if (F(i, km) != 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        T temp = F(i, j);
                        F(i, j) = F(km, j);
                        F(km, j) = temp;
                    }
                    break; // выход из цикла после обмена строк
                }
            }
        }


        for (int i = km; i < n - 1; i++)
            for (int j = km; j < km; j++)
            {
                F(i,j) = (F(i,j) * F(km,km) - F(km,j) * F(i,km)) / F(km,km);
            }
        for (int i = km + 1; i < n; i++) //зануление
            F(i,km) = 0;
        for (int i = n; i >= 0; i--) //деление на ведущий элемент
        {
            if (F(km,km) != 0)
                F(km,i) = F(km,i) / F(km,km);
            else abort;
        }
    }

    float* x = new float[n];

    std::cout << std::endl;

    float y = 0;

    MJG = F;

    int i = n - 1;

    for (int j = n; j > 0; j--)
    {
        int i = n - 1 - (n - j); //ограничевает i 
        for (i; i > 0; i--)
            MJG(i - 1,n) = (MJG(i - 1, n) + (MJG(j - 1, n) * -1 * MJG(i - 1, j - 1)));
    }

    for (int j = 0; j < n; j++) //нули
        for (int i = 0; i < n; i++)
        {
            if (i == j)
                MJG(j, i) = 1;
            else
                MJG(j, i) = 0;
        }

    cout << "Gauss - Jordan" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " " << MJG(i,n) << endl;
    }
    cout << endl << endl;
}

void interpolation(int ch_inv)
{
	/*
	x -1  0  1  2  3  4
	y  6  0 -8 -6 -4 -5
	*/
	

	switch (ch_inv)
	{
	case 1: 
	{
        // Решение СЛАУ
        nonstd::matrix<double> X({ { -1,0,1,2,3,4 } });
        nonstd::matrix<double> Y({ {6,0,-8,-6,-4,-5} });
        nonstd::matrix<double> mx(X.get_col_count(), X.get_col_count()+1);
        int n = X.get_col_count();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n + 1; j++)
                mx(i, j) = pow(X(0,i), j);
            mx(i, n) = Y(0,i);
        }

        JG(mx, 6);

        break;
	}

    case 2:
    {
        nonstd::matrix<double> mx({ { -1,0,1,2,3,4 }, {6,0,-8,-6,-4,-5} });
        double X = 0;
        cin >> X;
        double LGrng = 0;
        double nm, dnm;
        for (int k = 0; k < mx.get_col_count(); k++)
        {
            nm = 1; dnm = 1;
            for (int m = 0; m < mx.get_col_count(); m++)
                if (m != k)
                {
                    nm *= X - mx(0, m);
                    dnm *= mx(0, k) - mx(0, m);
                }
            LGrng += mx(1, k) * nm / dnm;
        }
        cout << LGrng << endl;
        break;
    }

    case 3:
    {
        const int n = 6;
        nonstd::matrix<double> x ({ { -1,0,1,2,3,4 } });
        nonstd::matrix<double> preparing({ {6,0,-8,-6,-4,-5} });
        nonstd::matrix<double> y(n, n);
        double NF, NB, num, den, xo, d;
        for (int i = 0; i < n; i++)
            y(i, 0) = preparing(0, i);

        for (int j = 1; j < n; j++)
            for (int i = 0; i < n; i++)
            {
                num = y(i + 1, j - 1) - y(i, j - 1);
                den = x(0, i + j) - x(0, i);
                y(i, j) = num / den;
            }
        cin >> xo;
        NF = y(0, 0);
        d = 1;
        for (int k = 1; k < n; k++)
        {
            d *= xo - x(0, k - 1);
            NF += y(0, k) * d;
        }
        cout << NF << endl;

        NB = y(n - 1, 0);
        d = 1;
        for (int k = 1; k < n; k++)
        {
            d *= xo - x(0, (n - 1) + 1 - k);
            NB += y((n - 1) - k, k) * d;
        }
        cout << NB << endl;
        break;
    }

    case 4:
    {
        int n = 6;
        nonstd::matrix<double> x({ {-1.2, -0.5, 0.5, 1.2, 2.5, 3.3} });
        nonstd::matrix<double> y({ {3.38688, -4.59375, 11.71875, 27.37152, 9.84375, 6.76863} });

        double a[6];
        double b[6];
        double c[6];
        double z[6]{ 1, 0, 0, 0, 0, 0 };
        double w[6]{ 1, 0, 0, 0, 0, 0 };
        double d[6];
        double dx = 0, e = 0;
        for (int k = 1; k < n; k++)
        {
            dx = x(0, k) - x(0, k - 1);
            e = y(0, k) - y(0, k - 1);
            a[k] = e / (dx * dx * dx) - z[k - 1] / (dx * dx) - w[k-1]/(2*dx);
            b[k] = 3 * e / (dx * dx) - 3 * z[k - 1] / dx - w[k - 1];
            c[k] = 3*e/ dx - 2 * z[k-1] - w[k-1] * dx/2;
            d[k] = y(0, k);
            z[k] = c[k];
            w[k] = 2 * b[k];
            cout << z[k] << "       " << w[k] << "      " << a[k] << "      " << b[k] << "    " << c[k] << "        " << d[k] << endl;
        }
        break;
    }

	}
}