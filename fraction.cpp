#include <iostream>

#include "fraction.h"

using namespace std;


	//Конструктор
    fraction::fraction(){ 
    	numerator = 1; denominator = 1;
    }

	//Конструктор с параметрами
	fraction::fraction(int num, int denom) {
		if (denom != 0)
		{
			numerator = num;
			denominator = denom;
		}

		else
		{
			numerator = 1;
			denominator = 1;
		}
;
	}

	////Деструктор
	//fraction::~fraction() { return; }

    //Задание дроби
    void fraction::initF(int num, int denom){  
    	//fraction f;

		//if (denom == 0) throw 

        if (denom != 0) 
	    {
	        numerator = num;
			denominator = denom;	
		}
		else 
		{
			numerator = 1;
			denominator = 1;	
			//return f;
		}
    }

    //Вернуть числитель
	int fraction::getNumeratorF(fraction f) {
		return f.numerator;
	}

    //Вернуть знаменатель
	int fraction::getDenominatorF(fraction f) {
		return f.denominator;
	}

	//Сравнить дроби
	void fraction::compareF(fraction f1, fraction f2) {
		fraction f;
		 
			f = subF(f1,f2);
			if (numerator > 0) {
				cout << f1.numerator << "/" << f1.denominator << " is larger than " 
				<< f2.numerator << "/" << f2.denominator;
			} 
			else {
			if (numerator < 0) {
				cout << f2.numerator << "/" << f2.denominator << " is larger than " 
				<< f1.numerator << "/" << f1.denominator;
			} 
			else {
				cout << f1.numerator << "/" << f1.denominator << " is equal " 
				<< f2.numerator << "/" << f2.denominator;
			}
		}
		cout << endl;
	}

	////Сравнить дроби
	//int fraction::compareF(fraction f1, fraction f2) {
	//	fraction f;

	//	f = subF(f1, f2);
	//	if (numerator > 0) {
	//		return 1;
	//	}
	//	else {
	//		if (numerator < 0) {
	//			return -1;
	//		}
	//		else {
	//			return 0;
	//		}
	//	}
	//	cout << endl;
	//}

	//Сумма дробей
    fraction fraction::addF(fraction f1, fraction f2){
    	fraction f;
    	numerator = (f1.numerator * f2.denominator) + (f2.numerator*f1.denominator);
		denominator = f1.denominator*f2.denominator;
		return f;
    }

    //Разность дробей
    fraction fraction::subF(fraction f1, fraction f2){
    	fraction f;
		numerator = (f1.numerator*f2.denominator) - (f2.numerator*f1.denominator);
		denominator = f1.denominator*f2.denominator;
		return f;
    }

    //Произведение дробей
    fraction fraction::multF(fraction f1, fraction f2){
		fraction f;
		numerator = f1.numerator*f2.numerator;
		denominator = f1.denominator*f2.denominator;
		return f;
	}

	//Частное дробей
    fraction fraction::divF(fraction f1, fraction f2){
		fraction f;
		numerator = f1.numerator*f2.denominator;
		denominator = f1.denominator*f2.numerator;
		return f;
	}

	//Вывод дроби
	void fraction::printF(fraction f) {
		cout << f.numerator << "/" << f.denominator;
	}


	//Наибольший общий делитель
	int fraction::nod(int a, int b)
	{
		a = abs(a);
		b = abs(b);
			while ((a!=0) && (b!=0)) 
			{
				if (a > b) 
				{
					a = a - b;
				} 
				else 
				{
					b = b - a;
				}
			}
		if (a!= 0) 
		{
			return a;
		} 
		else 
		{
			return b;
		}
	}

	//Сокращение
	fraction fraction::shortenF(fraction f1){
		fraction f;
		int div;
		div = nod(f1.numerator, f1.denominator);
		numerator = f1.numerator / div;
		denominator = f1.denominator / div;
		return f;
	}

	//Перевод в десятичную дробь
	double fraction::convertToDoubleF(fraction f1) 
		{
			return (double(f1.numerator) / double(f1.denominator));
		}




