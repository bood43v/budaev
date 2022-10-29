#include <iostream>
#include <stdio.h>
#include "fraction.h"

using namespace std;


int main()
{
	Fraction f1, f2;
	f1.initF(6, 5);/// Задание дробей
	f2.initF(4, 5);

	cout << "f1 = " << f1.stringFraction() << endl;/// Вывод дробей
	cout << "f2 = " << f2.stringFraction() << endl;

	int sign = f1.compareF(f2);/// Сравнение дробей
	switch (sign) {
		case  0: {
			cout << "f1 is equal f2" << endl;
			break;
		}

		case  1: {
			cout << "f1 is larger than f2" << endl;
			break;
		}
		case -1: {
			cout << "f2 is larger than f1" << endl;
			break;
		}

	}




	int a, b, c, d;
	a = 2; b = 7; c = -3; d = 14;
	//cout << "Input fractions: " << endl;
	//cin >> a >> b >> c >> d;
	
	Fraction f5;

	Fraction f3(a, b); ///Задание дробей
	Fraction f4(c, d);
	cout << endl << "f3 = " << f3.stringFraction() << endl;/// Вывод дробей
	cout << "f4 = " << f4.stringFraction() << endl;

	
	f5 = f3.addF(f4); /// Расчёт суммы дробей
	cout << endl << "f5 = f3 + f4 = " + f5.stringFraction(); /// Вывод суммы дробей
	
	
	cout << endl << "f5.numerator = " << f5.getNumeratorF() << endl; /// Получение знаменателя дроби f3
	
	//f3.shortenF();/// Сокращение дроби
	//cout << endl << "f3(shorten) = " + f3.stringFraction() << endl;/// Вывод после сокращения
	
	
	cout << endl << "f5 = " << f5.convertToDoubleF() << endl;/// Перевод в десятичную дробь
	


	
	return 0;
}

    

