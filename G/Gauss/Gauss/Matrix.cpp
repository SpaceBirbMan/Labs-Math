#include <iostream>
#include "matrix.h"
#include <random>
#include <iomanip>
#include <time.h>
#include <string>

float nstd::matrix::GetRandomNumber(int min, int max)
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(min, max); // distribute results between min and max inclusive.
	return dist(gen) + dist(gen) * 0.1; // pass the generator to the distribution.
}

float SmRand(int A, int B)
{
	srand(time(NULL));
	time_t now = time(0);
	float res;
	res = A + rand() % ((B + 1) - A); //todo: srand
	return res + rand() * 0.1;
}

float** nstd::matrix::matrix_creator(unsigned int n, unsigned int m) //делает матрицу размерностью n на m
{
	M = new float* [n]; //сама матрица
	for (int i = 0; i < n; i++)
	{
		M[i] = new float[m]; //строка матрицы
	}
	return M;

	*this >> 0;
}

float* nstd::matrix::array_creator(unsigned int n) //делает массив размерностью n
{
	A = new float[n]; //массив
	return A;
	*this >> 0;
}

nstd::matrix::matrix(unsigned int n, unsigned int m) //конструктор матрицы размерностью n на m (конструктор объекта)
{

	M = matrix_creator(n, m); //создаёт матрицу
	nl = n;
	ml = m;
}

nstd::matrix::matrix(unsigned int n) //конструктор матрицы размерностью n на m (конструктор объекта)
{

	A = array_creator(n); //создаёт массив
	nl = n;
}

void nstd::matrix::clean()
{
	if (M != NULL) //если у нас матрица
	{
		delete[] M;
	}
	if (A != NULL) //если у нас массив
	{
		delete[] A;
	}
}

nstd::matrix::matrix() {}

void nstd::matrix::randomize(int min, int max) //рандомайзер матрицы (от минимального до максимального значения)
{
	if (M != NULL) //если у нас матрица
	{
		for (int i = 0; i < nl; i++)
		{
			for (int j = 0; j < ml; j++)
			{
				M[i][j] = SmRand(min, max); //присвоение случайного числа 
			}
		}
	}
	if (A != NULL) //если у нас массив
	{
		for (int i = 0; i < nl; i++)
			A[i] = SmRand(min, max); //присвоение случайного числа 
	}

}

void nstd::matrix::randomize_advanced(int min, int max) //рандомайзер матрицы (от минимального до максимального значения)
{
	if (M != NULL) //если у нас матрица
	{
		for (int i = 0; i < nl; i++)
		{
			for (int j = 0; j < ml; j++)
			{
				M[i][j] = GetRandomNumber(min, max); //присвоение случайного числа 
			}
		}
	}
	if (A != NULL) //если у нас массив
	{
		for (int i = 0; i < nl; i++)
		{
			A[i] = GetRandomNumber(-10, 10); //присвоение случайного числа 
		}
	}

}

float nstd::matrix::AMult() //перемножает все числа в массиве
{
	float res = 1.0; //для адекватного подсчёта
	for (int i = 0; i < nl; i++)
	{
		res = res * A[i];
	}
	return res;
}

std::string nstd::matrix::tos()
{
	std::string data = "";
	if (M != NULL) //если у нас матрица
	{
		for (int i = 0; i < nl; i++)
		{
			for (int j = 0; j < ml; j++)
			{
				data = data + " " + std::to_string(M[i][j]);
			}
			data = data + "\n"; //перенос строки для создания новвой строки матрицы
		}
	}
	if (A != NULL) //если у нас массив
	{
		for (int i = 0; i < nl; i++)
		{
			data = data + std::to_string(A[i]) + ",";
		}
	}
	std::cout << std::endl;
	return data; //если нам надо куда-то вывести строку
}

float& nstd::matrix::operator () (int x, int y)
{
	if (y > -1)
		return this -> M[x][y];
	else
		return this -> A[x];
}

void nstd::matrix::operator << (const matrix & R)
{
	if (R.M != NULL) //если у нас матрица
	{
		for (int i = 0; i < R.nl; i++)
		{
			for (int j = 0; j < R.ml; j++)
			{
				std::cout << std::setw(5) << R.M[i][j] << std::setfill(' ');
			}
			std::cout << std::endl;
		}
	}
	if (R.A != NULL) //если у нас массив
	{
		for (int i = 0; i < R.nl; i++)
		{
			std::cout << R.A[i] << " ";
		}
	}
	std::cout << std::endl;	
}

//std::string matrix::operator << (matrix& R)
//{
//	std::string out = "";
//	if (R.M) //если у нас матрица
//	{
//		for (int i = 0; i < R.nl; i++)
//		{
//			for (int j = 0; j < R.ml; j++)
//				out += std::to_string(R.M[i][j]) + " ";
//		}
//		out += '\n';
//	}
//
//	if (R.A) //если у нас массив
//	{
//		for (int i = 0; i < R.nl; i++)
//		{
//			out += std::to_string(R.A[i]) + " ";
//		}
//	}
//	return out;
//}


nstd::matrix& nstd::matrix::operator = (const matrix& R)
{
	if (&R != this && this->nl >= R.nl && this->ml >= R.ml)
	{
		if (this->A != nullptr)
			for (int i = 0; i < R.nl; i++)
			{
				this->A[i] = R.A[i];
			}

		if (this->M != nullptr)
			for (int i = 0; i < R.nl; i++)
				for (int j = 0; j < R.ml; j++)
				{
					this->M[i][j] = R.M[i][j];
				}
	}

	else
	{
		std::cout << "INCOMPATBLE_MATRICES" << std::endl;
		abort;
	}

	return *this;
}

void nstd::matrix::diag_antizero(unsigned int n, unsigned int m)
{
	nstd::matrix M(nl, ml);
	for (int i = n; i < nl; i++)
	{
		if (abs(this->M[i][i]) < 0.000001)
		{
			for (int ii = 0; ii < m - 1; ii++)
				if (this->M[i][i] != 0)
				{
					M = this->M[ii][i];
					this->M[ii][i] = this->M[i][i];
					this->M[i][i] = *M.A;
				}
		}
	}
}

nstd::matrix& nstd::matrix::operator* (const float x) // Оператор умножения на скаляр
{
	if (M)
		for (int i = 0; i < ncl; i++)
			for (int j = 0; j < mcl; j++)
				M[i][j] = x * M[i][j];
	if (A)
			for (int j = 0; j < mcl; j++)
				A[j] = x * A[j];
	return *this;
}

nstd::matrix& nstd::matrix::operator- (nstd::matrix& I) // -
{
	if (M)
		for (int i = 0; i < ncl; i++)
			for (int j = 0; j < mcl; j++)
				M[i][j] = M[i][j] - I(i,j);
	if (A)
		for (int j = 0; j < mcl; j++)
			A[j] = A[j] - I(j);
	return *this;
}

nstd::matrix& nstd::matrix::operator+= (int j) // -=
{
	matrix I(nl);
	for (int i = 0; i < nl; i++)
		I(i) = this->M[i][j-1];
	return I;
}

nstd::matrix& nstd::matrix::operator-= (int i) // +=
{
	matrix J(ml);
	for (int j = 0; j < nl; j++)
		J(j) = this->M[i-1][j];
	return J;
}

void nstd::matrix::diag_replace(unsigned int n, unsigned int m, double x )
{
	for (int i = 0; i < nl - n && i < ml - m; i++)
		M[i + m][i + n] = x;
}

void nstd::matrix::operator >> (float inp)
{
	if (M != 0)
		for (int i = 0; i < nl; i++)
			for (int j = 0; j < ml; j++)
				this->M[i][j] = inp;
	if (A != 0)
		for (int j = 0; j < ml; j++)
			this->A[j] = inp;

	return;
}

nstd::matrix& nstd::matrix::operator* (nstd::matrix& I) // Оператор умножения на матрицу
{
	if (this->ml != I.nl) {
		// Матрицы несовместимы для умножения
		// Можно добавить обработку ошибки или вернуть пустую матрицу 
		throw 2; //да сделай уже энумератор или возьми существующий, хорош мучаться
		exit;
	}

	matrix result(this->ml, I.nl);

	for (int i = 0; i < this->ml; ++i) {
		for (int j = 0; j < I.nl; ++j) {
			double sum = 0.0;
			for (int k = 0; k < this -> nl; ++k) {
				sum += this->M[i][k] * I(k,j);
			}
			result(i,j) = sum;
		}
	}

	return result;
}

nstd::matrix& nstd::matrix::operator/ (nstd::matrix& I) // Оператор деления на матрицу
{
	return *this;
}

void nstd::matrix::inverse()
{
	matrix Adv (4, 8);

	for (int k = 0; k < nl; k++)
	{

	}

	/*

		15 ' Пересчёт по методу Жордана-Гаусса
		16 For k = 0 To n - 1
		17 ' Методом прямоугольника пересчитываем все элементы
		18 ' правее ведущего столбца и не в ведущей строке
		19 For i = 0 To n - 1
		20 For j = k + 1 To 2 * n - 1
		21 If i <> k Then
		22 B(i, j) = (B(i, j) * B(k, k) - B(k, j) * B(i, k)) / B(k, k)
		23 End If
		24 Next j
		25 Next i
		26
		27 ' Обнуляем элементы ведущего столбца (кроме ведущего элемента)
		28 For i = 0 To n - 1
		29 If i <> k Then
		30 B(i, k) = 0
		31 End If
		32 Next i
		33
		34 ' Делим ведущую строку на ведущий элемент
		35 For j = 2 * n - 1 To k Step - 1
		36 B(k, j) = B(k, j) / B(k, k)
		37 Next j
		38
		39 ' Выводим на лист очередную матрицу
		40 For i = 0 To n - 1
		41 For j = 0 To 2 * n - 1
		42 Cells(i + 6 + 5 * k, j + 1) = B(i, j)
		43 Next j
		44 Next i
		45
		46 Next k
		47
		48 End Sub*/
}