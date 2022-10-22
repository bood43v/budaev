#include <iostream>

using namespace std;

class fraction
{

	private:
	    int numerator;
	    int denominator;
    

  	public:
  		//Конструктор без параметров
	    fraction();

		//Конструктор с параметрами
		fraction(int num, int denom);

		////Деструктор
		//~fraction();
		
	    //Задание дроби
	    void initF(int num, int denom);

	    //Вернуть знаменатель
	    int getNumeratorF(fraction f);

	    //Вернуть числитель
	    int getDenominatorF(fraction f);

	    //Сравнение дробей
	    void compareF(fraction f1, fraction f2);

		////Сравнение дробей
		//int compareF(fraction f1, fraction f2)

	    //Сумма дробей
	    fraction addF(fraction f1, fraction f2);

	    //Разность дробей
	   	fraction subF(fraction f1, fraction f2);

	   	//Произведение дробей
	    fraction multF(fraction f1, fraction f2);

	    //Частное дробей
	    fraction divF(fraction f1, fraction f2);

	    //Вывод дроби
		void printF(fraction f);

		//Наибольший общий делитель
		int nod(int a, int b);

		//Сокращение
		fraction shortenF(fraction f1);

		//Перевод в десятичную дробь
		double convertToDoubleF(fraction f);

};

