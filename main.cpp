#include <iostream>
#include <stdio.h>
#include "fraction.h"

using namespace std;

int main()
{
	//fraction f1, f2, f3;
	Fraction f3;
	//f1.initF(7, 16);//Задание дробей
	//f2.initF(1, 2);

	//f1.initF(a, b);//Задание дробей
	//f2.initF(c, d);

	int a, b, c, d;
	cout << "Input fractions: " << endl;
	cin >> a >> b >> c >> d;

	Fraction f1(a, b);
	Fraction f2(c, d);

	f3 = f1.addF(f2);//Расчёт суммы дробей
	cout << "f1 = ";

	f1.printF();//Вывод дробей
	cout << endl << "f2 = ";
	f2.printF();
	
	cout << endl << "f3 = f1 + f2 = ";//Вывод суммы дробей
	f3.printF();

	int x = f3.getNumeratorF();//Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;
	
	f3.shortenF();//Сокращение дроби

	cout << endl << "f3 = ";//Вывод суммы дробей
	f3.printF();
	cout << endl;

	x = f3.getNumeratorF();//Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;

	double y = f3.convertToDoubleF();//Перевод в десятичную дробь
	cout << endl << "f3 = " << y << endl;//Вывод суммы дробей
	

	int sign = f3.compareF(f1, f2);//Сравнение дробей
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

    

