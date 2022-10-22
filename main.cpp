#include <iostream>
#include <stdio.h>
#include "fraction.h"

using namespace std;

int main()
{
	//fraction f1, f2, f3;
	fraction f3;
	//f1.initF(7, 16);//Задание дробей
	//f2.initF(1, 2);

	int a, b, c, d;
	cout << "Input fractions: " << endl;
	cin >> a >> b >> c >> d;

	//f1.initF(a, b);//Задание дробей
	//f2.initF(c, d);

	fraction f1(a, b);
	fraction f2(c, d);

	f3.addF(f1,f2);//Расчёт суммы дробей
	cout << "f1 = ";

	f1.printF(f1);//Вывод дробей
	cout << endl << "f2 = ";
	f2.printF(f2);
	
	cout << endl << "f3 = f1 + f2 = ";//Вывод суммы дробей
	f3.printF(f3);

	int x = f3.getNumeratorF(f3);//Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;
	
	f3.shortenF(f3);//Сокращение дроби

	cout << endl << "f3 = ";//Вывод суммы дробей
	f3.printF(f3);
	cout << endl;

	x = f3.getNumeratorF(f3);//Получение знаменателя дроби f3
	cout << endl << "f3.numerator = " << x << endl;

	double y = f3.convertToDoubleF(f3);//Перевод в десятичную дробь
	cout << endl << "f3 = " << y << endl;//Вывод суммы дробей
	
	f3.compareF(f1, f2);//Сравнение дробей

	cout << endl;
	return 0;
}

    
//Сравнение
	// int sign = f3.compareF(f1, f2);//Сравнение дробей
	// switch(sign){
	// 	case  0: {
	// 		cout << "f1 is equal f2";
	// 		break;
	// 	}

	// 	case  1: {
	// 		cout << "f1 is larger than f2";
	// 		break;
	// 	}
	// 	case -1: {
	// 		cout << "f2 is larger than f1";
	// 		break;
	// 	}
		
	// }