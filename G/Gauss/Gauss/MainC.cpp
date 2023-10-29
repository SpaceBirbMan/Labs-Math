#include <iostream>
#include "Gauss.h"
#include "Run-through.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Методы решения:" << endl;
	cout << "1 - Гаусс и Жордан-Гаусс" << endl;
	cout << "2 - Прогонка" << endl;

	unsigned int a;

	cin >> a;
	switch (a)
	{
		case 1: {Gauss(); break; }
		case 2: {RT(); break; }
	}
		
	
}