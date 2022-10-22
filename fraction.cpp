#include <iostream>

#include "fraction.h"

using namespace std;


	//Конструктор
    Fraction::Fraction(){ 
    	numerator = 1; denominator = 1;
    }

	//Конструктор с параметрами
	Fraction::Fraction(int num, int denom) {
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
    void Fraction::initF(int num, int denom){  
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
	int Fraction::getNumeratorF() const {
		return numerator;
	}

    //Вернуть знаменатель
	int Fraction::getDenominatorF() const {
		return denominator;
	}



	//Сравнить дроби
	int Fraction::compareF(Fraction f1, Fraction f2) {
		Fraction f;

		f = f1.subF(f2);
		if (f.numerator > 0) {
			return 1;
		}
		else {
			if (f.numerator < 0) {
				return -1;
			}
			else {
				return 0;
			}
		}
		cout << endl;
	}

	//Сумма дробей
    Fraction Fraction::addF( Fraction const& f2 ){
    	Fraction f;
    	int num_ = (this->numerator * f2.denominator) + (f2.numerator* this->denominator);
		int denom_ = this->denominator*f2.denominator;
		return f;
    }

    //Разность дробей
  //  fraction fraction::subF(fraction f1, fraction f2){
  //  	fraction f;
		//numerator = (f1.numerator*f2.denominator) - (f2.numerator*f1.denominator);
		//denominator = f1.denominator*f2.denominator;
		//return f;
  //  }

	Fraction Fraction::subF( Fraction const &f2 ) {  // todo const &
		
		int num_ = (this->numerator * f2.denominator) - (f2.numerator * this->denominator);
		int denom_ = this->denominator * f2.denominator;
		Fraction f(num_, denom_);
		return f;
	}

    //Произведение дробей
    Fraction Fraction::multF( Fraction const& f2 ){

		int num_ = this->numerator*f2.numerator;
		int denom_ = this->denominator*f2.denominator;
		Fraction f(num_, denom_);
		return f;
	}

	//Частное дробей
    Fraction Fraction::divF(Fraction const& f2){

		int num_ = this->numerator*f2.denominator;
		int denom_ = this->denominator*f2.numerator;
		Fraction f(num_, denom_);
		return f;
	}

	//Вывод дроби
	void Fraction::printF() {
		cout << numerator << "/" << denominator;
	}


	//Наибольший общий делитель
	int Fraction::nod(int a, int b)
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
	Fraction Fraction::shortenF(){
		

		int div;
		div = nod(this->numerator, this->denominator);
		int num_ = this->numerator / div;
		int denom_ = this->denominator / div;
		Fraction f(num_, denom_);
		return f;
	}

	//Перевод в десятичную дробь
	double Fraction::convertToDoubleF() 
		{
			return (double(numerator) / double(denominator));
		}




