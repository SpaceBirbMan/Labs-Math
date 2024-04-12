#include <iostream>
#include "Gauss.h"
#include "Run-through.h"
#include "LU.h"
#include "Quads.h"
#include "SInert.h"
#include "qrcp.h"
#include "pytoc.h"
#include "Interpolation.h"
#include "IDiff.h"
#include "Integrating.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	start:
	cout << "Методы решения:" << endl;
	cout << "1 - Гаусс и Жордан-Гаусс" << endl;
	cout << "2 - Прогонка" << endl;
	cout << "3 - LU" << endl;
	cout << "4 - Квадратные корни" << endl;
	cout << "5 - Метод Зейделя" << endl;
	cout << "6 - QR" << endl;
	cout << "7 - Решение нелинейного уравнения методом половинного деления" << endl;
	cout << "8 - Решение нелинейного уравнения комбинированным методом" << endl;
	cout << "9 - Интерполяция" << endl;
	cout << "10 - Производная" << endl;
	cout << "11 - Интегрирование" << endl;

	

	unsigned int ch_calc, ch_inv;

	cin >> ch_calc;

	if (ch_calc <= 5)
	{
		cout << "1 - Расчитывать обратную матрицу (Метод простых итераций для 5), 0 - Обычный расчёт" << endl;
		cin >> ch_inv;
	}
	else if (ch_calc == 6) 
	{
		cout << "1 - С++ версия, 2 - python версия" << endl;
		cin >> ch_inv;
	}
	else if (ch_calc == 9)
	{
		cout << "1 - Жордан-Гаусс\n2 - Лагранж\n3 - Ньютон\n4 - Сплайнами" << endl;
		cin >> ch_inv;
	}
		

		
	switch (ch_calc)
	{
	case 1: {Gauss(ch_inv); break; }
	case 2: {/*RT(ch_inv)*/; break; }
	case 3: {LU(ch_inv); break; }
	case 4: {Quads(ch_inv); break; }
	case 5: {SIter(ch_inv); break; }
	case 6: {if (ch_inv == 1) Qr(); else qr(); break; }
	case 7: { half_divide(); break; }
	case 8: { combin_method(); break; }
	case 9: { interpolation(ch_inv); break; }
	case 10: { iDiff(); break; }
	case 11: { I(); break; }
	default: goto start;
	}
}