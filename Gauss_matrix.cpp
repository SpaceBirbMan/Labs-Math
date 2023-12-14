#include <iostream>
#include <random>
#include <iomanip>
#include <math.h>

std::random_device rd;
std::mt19937 gen(rd());



int random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

const int n = 4;

float Matrix[n][n+1];
float a;
unsigned int step = 0;
//todo: динамическая матрица


void Randomizer(float M[n][n+1])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			M[i][j] = random(1, 100) + 0.1 * random(0, 10);
		}
		std::cout << std::endl;
	}
}

void Matrix_Print(float M[n][n + 1])
{
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			std::cout << std::setfill(' ') << std::setw(12) << std::fixed << M[i][j];
		}
		std::cout << std::endl;
	}
}

//bool Check (unsigned int step)
void Calculator(float M[n][n + 1])
{
	for (int i = 0; i < n; i++)
	{
		 a = M[i][i];
		for (int j = 0; j < n + 1; j++)
		{
			M[i][j] = M[i][j] / a;
		}
	}
}
int main()
{
	std::cout.precision(2);
	Randomizer(Matrix);
	Matrix_Print(Matrix);
	Calculator(Matrix);
	Matrix_Print(Matrix);
}