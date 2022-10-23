#include <iostream>

#include "fraction.h"

using namespace std;


	/// Конструктор
    Fraction::Fraction(){ 
    	numerator = 1; denominator = 1;
    }

	/// Конструктор с параметрами
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

	//Деструктор
	Fraction::~Fraction() { return; }

    /// Задание дроби
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

    /// Вернуть числитель
	int Fraction::getNumeratorF() const {
		return numerator;
	}

    /// Вернуть знаменатель
	int Fraction::getDenominatorF() const {
		return denominator;
	}



	/// Сравнить дроби
	int Fraction::compareF(Fraction f1) { 
		Fraction f;

		f = (*this).subF(f1);
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

	/// Сумма дробей
    Fraction Fraction::addF( Fraction const& f1 ){

    	int num_ = (this->numerator * f1.denominator) + (f1.numerator* this->denominator);
		int denom_ = this->denominator*f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
		//return Fraction((this->numerator * f1.denominator) + (f1.numerator * this->denominator), this->denominator * f1.denominator);
    }

	/// Вычитание дроби
	Fraction Fraction::subF( Fraction const &f1 ) {  
		
		int num_ = (this->numerator * f1.denominator) - (f1.numerator * this->denominator);
		int denom_ = this->denominator * f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

    /// Произведение дробей
    Fraction Fraction::multF( Fraction const& f1 ){

		int num_ = this->numerator*f1.numerator;
		int denom_ = this->denominator*f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

	/// Частное дробей
    Fraction Fraction::divF(Fraction const& f1){

		int num_ = this->numerator*f1.denominator;
		int denom_ = this->denominator*f1.numerator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

	/// Вывод дроби
	void Fraction::printF() {
		cout << numerator << "/" << denominator;
	}


	/// Наибольший общий делитель
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


	/// Сокращение
	Fraction Fraction::shortenF() {
		
		int div = nod(this->numerator, this->denominator);
		numerator = this->numerator / div;
		denominator = this->denominator / div;
		return *this;
	}

	/// Перевод в десятичную дробь
	double Fraction::convertToDoubleF() 
		{
			return (double(numerator) / denominator);
		}




