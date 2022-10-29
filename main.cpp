/// Обыкновенные дроби и операции над ними
/// Главная программа
/// @author Будаев Г.Б.
#include <iostream>
#include <stdio.h>
#include <exception>
#include "fraction.h"

using namespace std;


int main()
{
	try {
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
		a = 2; b = 7; c = 4; d = 14;
		//cout << "Input fractions: " << endl;
		//cin >> a >> b >> c >> d;

		Fraction f5;

		Fraction f3(a, b); ///Задание дробей
		Fraction f4(c, d);
		cout << endl << "f3 = " << f3.stringFraction() << endl; /// Вывод дробей
		cout << "f4 = " << f4.stringFraction() << endl;


		f5 = f3.addF(f4); /// Расчёт суммы дробей
		cout << endl << "f5 = f3 + f4 = " + f5.stringFraction(); /// Вывод суммы дробей


		cout << endl << "f5.numerator = " << f5.getNumeratorF() << endl; /// Получение знаменателя дроби f3

		//f3.shortenF();/// Сокращение дроби
		//cout << endl << "f3(shorten) = " + f3.stringFraction() << endl; /// Вывод после сокращения


		cout << endl << "f5 = " << f5.convertToDoubleF() << endl<< endl; /// Перевод в десятичную дробь


			/// Массив из объектов
			const int size = 5;
			Fraction *arrF = new Fraction [size];
			int j = 2;

			for (int i = 1; i < size; i++) { /// Задание значений объектов
				arrF[i].initF(i, j);
				j++;
			}

			for (int i = 1; i < size; i++) { /// Вывод объектов
				cout << "fr[" << i << "] = " << arrF[i].stringFraction() << endl;
			}

			/// Вывод чистилеля 3-й дроби
			cout << endl << "fr[" << 3 << "].numerator = "<< arrF[3].getNumeratorF() << endl;
			/// Сумма дробей
			Fraction f_sum = arrF[3].addF(arrF[4]);
			cout << endl << "f_sum = fr[" << 3 << "] + fr[" << 4 << "] = " + f_sum.stringFraction(); /// Вывод суммы дробей

			delete []arrF;/// Освобождение памяти


			/// Массив из указателей на объекты
			Fraction *aF[size];

			for (int i = 1; i < size; i++) { /// Присваивание массиву aF указателей на массив arrF
				aF[i] = &arrF[i];
			}

			for (int i = 1; i < size; i++) { /// Вывод числителей объектов через указатели
				cout << endl << "aF[" << i << "].numerator = " << aF[i]->getNumeratorF() << endl;
			}
	}
	
	catch (invalid_argument e) {
		cout << e.what();
	}
	
	return 0;
}

    

