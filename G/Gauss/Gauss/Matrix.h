#pragma once

namespace nstd
{
	class matrix //класс матрицы
	{
	private:

		float** matrix_creator(unsigned int n, unsigned int m); //создаёт матрицу n на m
		float* array_creator(unsigned int n); //создаёт массив, размерностью n

		unsigned int nl = 0; //строки
		unsigned int ml = 0; //столбцы

		float GetRandomNumber(int min, int max);

	public:

		const int ncl = nl;
		const int mcl = ml; //надо get,set вместо них

		float** M = nullptr; //указатель на матрицу
		float* A = nullptr; //указатель на массив

		matrix(unsigned int, unsigned int); //конструктор матрицы
		matrix(unsigned int); //конструктор массива
		matrix();

		float& operator () (int x, int y = -1); //оператор получения значения по индексу //todo: заполнять строку через эту штуку
		matrix& operator = (const matrix& R); //оператор присваивания
		matrix& operator* (const float x); // Оператор умножения на скаляр
		matrix& operator* (matrix& I); // Оператор умножения на матрицу
		matrix& operator/ (matrix& I); // Оператор деления на матрицу
		matrix& operator- (matrix& I); // Оператор вычитания матрицы из матрицы
		matrix& operator-= (int j); // Оператор выноса столбца в массив (даже если на вход подаётся матрица)
		matrix& operator+= (int i); // Оператор выноса строки в массив (даже если на выход подаётся матрица)
		void operator >> (float inp); //оператор заполнения всей матрицы одним числом
		void operator << (const matrix& R); // оператор вывода матрицы
		//std::string operator << (matrix& R);

		void clean(); //очищает конструкцию 

		void randomize(int min, int max); //рандомайзер матрицы
		void randomize_advanced(int min, int max); //рандомайзер матрицы
		float AMult(); //перемножает числа в массиве
		std::string tos(); //выводит на экран и в строку массив/матрицу
		void diag_antizero(unsigned int n, unsigned int m);
		void diag_replace(unsigned int n, unsigned int m, double x = 0);
		void inverse(); //делает обратную матрицу

		//todo: iterator и negiterator
		//resize
		//шаблоны и перегрузка под двадцатый стандарт
		//get|set
		//transpond
	};

	namespace matio //не очень полезен
	{
		static matrix m;
	}
}


