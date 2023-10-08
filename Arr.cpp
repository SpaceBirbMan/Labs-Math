//A: Sosnov Kirill

#define NDEBUG //отключение assertов
#include <iostream> //std функции
#include <cassert> //assertы
#include "Lib.h" //библиотека
#include <vector> //векторы


using namespace std; //пространство имён для удобство работы с std конструкциями
using namespace ci; //пространство имён из библиотеки



int main(int argc, char* argv[])
{
start:
	try
	{
		vector<float> V1; //вектор вывода
		int ch = 0; //переменная для кейсов

		vector<float> AT(6); //массив для проверки из 6 чисел
		for (int i = 1; i <= 6; i++)
			AT[i - 1] = i;
		assert(vmult(AT) == 720); //проверка правильности вычисления


		vector<float> AT2(12); //массив для проверки из 12 чисел
		for (int i = 1; i <= 12; i++)
			AT2[i - 1] = i * 0.21;
		assert(vmult(AT2) == 3.52345); //проверка правильности высчисления

		cout << "Choose fill method (1 or 2)" << endl;
		cin >> ch;

		File TX("jesus.txt"); //инициализация файла
		switch (ch)
		{
		case 1: //заполнение случайными числами и тут же вычисление через файл
		{

			vector<float> Ar(10);
			Ar = vrand(Ar);
			TX.open(1); //открытие файла для записи
			TX.print(vprint(Ar)); //запись строки в файл 
			cout << endl;
			TX.close();	//закрытие файла

			TX.open(2); //открытие файла для чтения
			V1 = stov(TX.read()); //перезапись данных в вектор
			TX.close(); //закрытие
			break;
		}
		case 2: //вывод данных из файла и вычисление
		{
			TX.open(2); //открытие файла для чтение

			V1 = stov(TX.read()); //перезапись данных в вектор

			TX.close(); //закрытие файла
			break;
		}
		default:
		{
			throw 2;
			goto start;
			break;
		}
		}



		vprint(V1); 
		cout << '\n';
		cout << vmult(V1) << endl; //вычисление и вывод результата в консоль

	}
	catch (int a)
	{
		switch (a)
		{
			case -1:
			{
				cout << "Detected wrong string in file. No futher calculations possible. The program has aborted." << endl;
				break;
			}
			case 1:
			{
				cout << "Data file does not exist. Program restarted. Put data file into directory or use first filling method." << endl;
				goto start;
			}
			case 2:
			{
				cout << "Wrong fill argument. Program has been eliminated" << endl;
				return 0;
				break;
			}
		}
	}

	if (argc > 1)
	{
		cout << argv[1] << endl;

		string arg = argv[1];

		if (arg == "no_retry")
		{
			return 0;
		}
	}
	
		char fch;
		cout << "Retry?" << endl;
		cin >> fch;
		if (fch == 'y') goto start;
		else return 0;
	

}
