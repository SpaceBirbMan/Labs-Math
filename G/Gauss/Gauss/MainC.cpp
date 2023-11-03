#include <iostream>
#include "Gauss.h"
#include "Run-through.h"
#include "LU.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Методы решения:" << endl;
	cout << "1 - Гаусс и Жордан-Гаусс" << endl;
	cout << "2 - Прогонка" << endl;
	cout << "3 - LU" << endl;
	cout << "4 - Квадратные корни" << endl;
	cout << "5 - Метод простых итераций" << endl;

	cout << "Использовать обратную матрицу [WIP]" << endl;

	unsigned int a;

	cin >> a;
	switch (a)
	{
		case 1: {Gauss(); break; }
		case 2: {RT(); break; }
		case 3: {LU(); break; }
	}
		
	
}