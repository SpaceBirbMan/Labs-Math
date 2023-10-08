//A: Sosnov Kirill
#include <iostream>
#include <cmath>
#include <random>
#include "Lib.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>



//рандомайзер (от минимального до максимального значения)
float GetRandomNumber(int min, int max)
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(min, max); // distribute results between min and max inclusive.
	return dist(gen)+dist(gen)*0.1; // pass the generator to the distribution.
}

float SmRand(int A, int B)
{
	time_t now = time(0);
	float res;
	res = A + rand() % ((B + 1) - A); //todo: srand
	return res + rand() * 0.1;
}

std::vector<float> stov(std::string input)
{
	std::vector<float> Av; //выходной вектор
	bool c = false; //триггер начала чисел

	// std::cout << " --- " <<  input.size() << std::endl;
	int cnt = 0;
	std::string sa = "";
	Av.resize(input.length(), 0);
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ',' || input[i] != '\n')
		{
			int b = (int)input[i];
			if ((b >= 48 && b <= 57) || b == 44 || b == 46)
			{
				sa = sa + input[i]; //строка собирается от запятой до запятой
		    	// std::cout << " -> " << sa << std::endl;
				c = true;
			}
			else
			{
				throw -1;
				abort();
			}
		}
		
		if (input[i] == ',')
			if(sa != "" and c == true)
			{			
				Av[cnt] = stof(sa); //строка переводится в число
				sa = ""; //строка обнуляется
				cnt++;
			}
		
		
	}
	Av.resize(cnt);
	// std::cout << Av[3] << std::endl;
	return Av; 
}



		float** Mtrx::Matrix::matrix_creator(unsigned int n, unsigned int m) //делает матрицу размерностью n на m
		{
			M = new float*[n]; //сама матрица
			 for (int i = 0; i < n; i++)
			 {
			 	M[i] = new float[m]; //строка матрицы
			 }
		return M;
		}

		float* Mtrx::Matrix::array_creator(unsigned int n) //делает массив размерностью n
		{
			 	A = new float[n]; //массив
		return A;
		}

		Mtrx::Matrix::Matrix (unsigned int n, unsigned int m) //конструктор матрицы размерностью n на m (конструктор объекта)
		{
			
			M = matrix_creator(n,m); //создаёт матрицу
			nl = n;
			ml = m;
		}

		Mtrx::Matrix::Matrix (unsigned int n) //конструктор матрицы размерностью n на m (конструктор объекта)
		{
			
			A = array_creator(n); //создаёт массив
			nl = n;
		}

		void Mtrx::Matrix::clean()
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

		void Mtrx::Matrix::randomize(int min, int max) //рандомайзер матрицы (от минимального до максимального значения)
		{
			if (M != NULL) //если у нас матрица
			{
				for (int i = 0; i < nl; i++)
				{
					for (int j = 0; j < ml; j++)
						{
							M[i][j] =SmRand(-10,10); //присвоение случайного числа 
						}
				}
			}
			if (A != NULL) //если у нас массив
			{
				for (int i = 0; i < nl; i++)
				{
					A[i] = SmRand(-10,10); //присвоение случайного числа 
				}
			}
			
		}

		float Mtrx::Matrix::AMult() //перемножает все числа в массиве
		{
		float res = 1.0; //для адекватного подсчёта
		for (int i = 0; i < nl; i++)
		{
			res = res * A[i];
		}
		return res;
		}

		std::string Mtrx::Matrix::print()
		{
			std::string data = "";
			if (M != NULL) //если у нас матрица
			{
				for (int i = 0; i < nl; i++)
				{
					std::cout << std::endl; 
					for (int j = 0; j < ml; j++)
						{
							std::cout << std::setw(5) << M[i][j] << std::setfill(' ');
							data = data + " " + std::to_string(M[i][j]);
						}
					data = data + "\n"; //перенос строки для создания новвой строки матрицы
				}
			}
			if (A != NULL) //если у нас массив
			{
				for (int i = 0; i < nl; i++)
				{
					std::cout << A[i] << "  "; 
					data = data + std::to_string(A[i]) + ",";
				}
			}
			std::cout << std::endl;
			return data; //если нам надо куда-то вывести строку
		}
	

		Mtrx::File::File (std::string name)
		{
			tname = name; //имя файла, которое всеми будет использоваться
		}
		void Mtrx::File::open(int key)
		{
			switch (key)
			{
			case 1: F.open(tname); break; //открывает файл для записи
			case 2: IF.open(tname); break;//открывает файл для чтения
			}
		}
		void Mtrx::File::close()
		{
			if (F.is_open())
				F.close();
			if (IF.is_open())
				IF.close();
		}
		void Mtrx::File::print(std::string data)
		{
			if (F.is_open())
				F << data; 	//вывод в файл	
		}
		std::string Mtrx::File::read()
		{
			std::string data = "";
			if (IF.is_open())
				IF >> data; //вывод из файла
			else
				throw 1;
			return  data;
		}


///Функция считает второй катет у треугольника
float calcb(float a, float c)
{
	return sqrt(c * c - a * a); //вычисление длины катета по теореме пифагора;
} 

///Функция считает радиус вписанной окружности
float calcr(float a, float b, float c)
{
	return (a + b - c)/2; //вычисление длины радиуса вписанной окружности
}

Mtrx::Matrix vtoar(std::vector<float> input)
{
	int l = input.size(); //размер для создания массива
	Mtrx::Matrix Out(l); //объект класса на вывод
	for (int i = 0; i < l; i++)
	{
		Out.A[i] = input[i]; //перенос данных
		// std::cout << Out.A[i] << ' ' << input[i] << std::endl;
	}
	return Out;
}

Mtrx::Matrix stoar(std::string input)
{
	float a = 0.0; //число для вектора
	std::vector<float> Av; //выходной вектор
	int g = 0; //счётчик чисел (длмна массива в будущем)
	bool c = false; //триггер начала чисел

	// std::cout << " --- " <<  input.size() << std::endl;

	std::string sa = "";
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ','  or input[i] != '\n')
		{
			sa = sa + input[i]; //строка собирается от запятой до запятой
		    // std::cout << " -> " << sa << std::endl;
			c = true;
		}

		if (input[i] == ',')
			if(sa != "" and c == true)
			{
				a = stof(sa); //строка переводится в число
				sa = ""; //строка обнуляется
				g++; //счётчик + 1
				// std::cout << g << std::endl;
			}
		Av.resize(g, a);
		// l = g; //длина на вывод

		
	}

	Mtrx::Matrix Ot(g);
	for (int i = 0; i < g; i++)
		{
			Ot.A[i] = Av[i];
		}
	// std::cout << Av[3] << std::endl;
	return Ot;

	
}

std::vector<float> vrand(std::vector<float> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		input[i] = SmRand(-10,10);
	}
	return input;
}

std::string vprint(std::vector<float> inp)
{
	std::string out;
	for (int i = 0; i < inp.size(); i++)
	{
		std::cout << inp[i] << "  ";
		out = out + std::to_string(inp[i]) + ",";
	}
	return out;
}

float vmult(const std::vector<float> &inp) //перемножает все числа в векторе
{
	float res = 1.0; //для адекватного подсчёта
	for (int i = 0; i < inp.size(); i++)
	{
		res = res * inp[i];
	}
	return res;
}