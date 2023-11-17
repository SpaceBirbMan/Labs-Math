#include <iostream>
#include "Gauss.h"
#include "Run-through.h"
#include "LU.h"
#include "Quads.h"
#include "SInert.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Методы решения:" << endl;
	cout << "1 - Гаусс и Жордан-Гаусс" << endl;
	cout << "2 - Прогонка" << endl;
	cout << "3 - LU" << endl;
	cout << "4 - Квадратные корни" << endl;
	cout << "5 - Метод Зейделя" << endl;

	

	unsigned int ch_calc, ch_inv;

	cin >> ch_calc;
	cout << "1 - Расчитывать обратную матрицу (Метод простых итераций для 5), 0 - Обычный расчёт" << endl;
	cin >> ch_inv;
	switch (ch_calc)
	{
	case 1: {Gauss(ch_inv); break; }
	case 2: {RT(ch_inv); break; }
	case 3: {LU(ch_inv); break; }
	case 4: {Quads(ch_inv); break; }
	case 5: {SIter(ch_inv); break; }
	}
		
	
}