//A: Sosnov Kirill
#pragma once //вызов единожды
#include <fstream>
#include <string>
#include <vector>


///Расчитывает катет треугольника (а - катет, с - гипотенуза)
float calcb(float a, float c);
///Расчитывает радиус вписанной окружности в треугольник (а,b,c - стороны треугольника)
float calcr(float a, float b, float c);
///Создаёт случайные вещественные числа, принимая пороговые значения для выбора числа
float GetRandomNumber(int min, int max);
float SmRand(int A, int B);

std::vector<float> stov(std::string input); //выводит данные из строки в вектор
namespace Mtrx //class items
{
	class Matrix //класс матрицы
	{
	private:

		float** matrix_creator(unsigned int n, unsigned int m); //создаёт матрицу n на m
		float* array_creator(unsigned int n); //создаёт массив, размерностью n

	public:

		float** M = NULL; //указатель на матрицу
		float* A = NULL; //указатель на массив

		unsigned int nl = 0; //строки
		unsigned int ml = 0; //столбцы

		Matrix(unsigned int n, unsigned int m); //конструктор матрицы
		Matrix(unsigned int n); //конструктор массива

		void clean(); //очищает конструкцию 

		void randomize(int min, int max); //рандомайзер матрицы
		float AMult(); //перемножает числа в массиве
		std::string print(); //выводит на экран и в строку массив/матрицу
	};

	class File //класс для работы с файлами
	{
	private:

		std::string tname; //имя файла
		std::ofstream F; //поток записи
		std::ifstream IF; //поток чтения

	public:
		File(std::string name); //конструктор файла, принимает название файла строкой
		void open(int key); //открывает файл (ключ 1 - на запись, ключ 2 - на чтение)
		void close(); //закрывает файлы
		void print(std::string data); //выводит в файл значения в виде строки (todo: решить проблему со строкой, файл не обязан быть текстовым)
		std::string read(); //считывает данные из файла и выводит их в строку
	};
}

std::vector<float> vrand(std::vector<float> input);
Mtrx::Matrix vtoar(std::vector<float> input); //переводит данные вещественного вектора в массив
std::string vprint(std::vector<float> inp);
float vmult(const std::vector<float> &inp); //перемножает все числа в векторе


