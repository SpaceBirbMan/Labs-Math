//A: Sosnov Kirill

// #define NDEBUG //отключение assertов
#include <iostream> //std функции
#include <cassert> //assertы
#include "Lib.h" //модуль

using namespace std;



int main()
{
	//Константа точности для проверки вещественных чисел на точность подсчёта
	const float EPS = 0.01;
	///Блок проверок
	assert(calcb(3,5) == 4);
	assert(calcb(6,10) == 8);
	assert(calcr(3,4,5) == 1);
	assert(calcr(6,8,10) == 2);
	assert(abs(1.64 - calcr(6,5.29,8)) < EPS);


	///Исполнительный блок
	std::cout << "Enter hypotenuse c and leg a" << std::endl;
	float b; //катет б
	float r; //радиус вписанной окружности
	float a; //катет а
	float c1; //гипотенуза
	std::cin >> c1;
	std::cin >> a;
	b = calcb(a,c1); //расчёт второго катета
	r = calcr(a,b,c1); //Расчёт радиуса вписанной окружности
	std::cout << "For given sides of a right triangle " << a << " and " << c1 << std::endl;
	std::cout << "The second leg is equal " << b << std::endl;
	std::cout << "The radius of the circle is " << r;
}