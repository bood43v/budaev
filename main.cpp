#include <iostream>
#include <stdio.h>
#include "fraction.h"

using namespace std;

int main()
{
	Fraction f1, f2;

	f1.initF(6, 5);//Задание дробей
	f2.initF(4, 5);

	//f1.initF(a, b);//Задание дробей
	//f2.initF(c, d);

	//int a, b, c, d;
	//cout << "Input fractions: " << endl;
	//cin >> a >> b >> c >> d;

	//Fraction f1(a, b);
	//Fraction f2(c, d);

	Fraction f3;

	/// Вывод дробей
	cout << "f1 = ";
	f1.printF();
	cout << endl << "f2 = ";
	f2.printF();
	
	f3 = f1.addF(f2); /// Расчёт суммы дробей
	cout << endl << "f3 = f1 + f2 = ";/// Вывод суммы дробей
	f3.printF();

	int x = f3.getNumeratorF();/// Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;
	
	f3.shortenF();/// Сокращение дроби

	cout << endl << "f3 = ";/// Вывод после сокращения
	f3.printF();
	cout << endl;

	x = f3.getNumeratorF();/// Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;

	double y = f3.convertToDoubleF();/// Перевод в десятичную дробь
	cout << endl << "f3 = " << y << endl;/// Вывод суммы дробей
	

	int sign = f1.compareF(f2);/// Сравнение дробей
	switch (sign) {
	case  0: {
		cout << "f1 is equal f2";
		break;
	}

	case  1: {
		cout << "f1 is larger than f2";
		break;
	}
	case -1: {
		cout << "f2 is larger than f1";
		break;
	}

	}


	cout << endl;
	return 0;
}

    

