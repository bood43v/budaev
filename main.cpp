/// Обыкновенные дроби и операции над ними
/// Главная программа
/// @author Будаев Г.Б.
#include <iostream>
#include <stdio.h>
#include <exception>
#include <fstream>
#include <string>
#include "fraction.h"

using namespace std;

void outputFraction(Fraction f, string name, int number) {//Вывод дроби в файл
	ofstream outFile(name, ios_base::app);

	if (name == "")  throw invalid_argument("File's name error");/// Если имя файла пустое
	if (!outFile.is_open()) /// Вызов метода is_open()
		throw invalid_argument("File isn't open!");/// Если файл не открыт

	outFile << "f[" << number <<"] = " << f.stringFraction() << endl;/// Вывод дробей
	//outFile << f.stringFraction() << endl;/// Вывод дробей

	outFile.close();// Закрытие файла
}

/// Количество строк в файле
int rowsNumber(string name) {
	ifstream inFile(name);

	if (name == "")  throw invalid_argument("File's name error");
	//Если файл не открыт
	if (!inFile.is_open()) // вызов метода is_open()
		throw invalid_argument("File isn't open!");//Если файл не открыт

	string s;//Буферная строка 

	int k = 0;
	while (inFile.peek() != EOF) {
		getline(inFile, s);
		k++;
	}
	inFile.close();// Закрытие файла
	if (k == 0) throw invalid_argument("Empty file");
	return k;
}

/// Чтение объектов из файла строк в файле
void getFraction(Fraction *f, string name, int k) 

	{
		int num = 0, denom = 0;

		ifstream in_file(name);

		if (name == "")  throw invalid_argument("File's name error");
		if (!in_file.is_open()) /// Вызов метода is_open()
		    throw invalid_argument("File isn't open!");/// Если файл не открыт

		string s;
		string num_str = "", denom_str = "";/// Для чтения числителей и знаменателей
		int skip = 0;/// Для пропуска слэша
		
		string str;/// Для чтения файла строкамии
		while (getline(in_file, str))/// Чтение файла строками
		{
			s += str + "\n";/// Добавления символа перехода на новую строку
		}
		int i = 0;/// Для перехода по символам в строке
		int j = 0;/// Для индекса дроби

	label:/// Метка для перехода при переходе на новую строку
		//cout << "s";
		while (s[i] != '\0') {/// Пока не достигнут конец всей строки
			if (skip == 0)
			{
				if (s[i] == '/')/// Если есть слэш, меняем skip, чтобы читать знаменатнль
				{
					skip = 1;
				}
				else
				{
					//cout << s[i];
					num_str = num_str + s[i];/// Заносим символ в строку с числителем
				}
			}
			else
			{
				if ((s[i + 1] == '\n'))/// Если найден переход на новую строку
				{
					denom_str = denom_str + s[i];/// Добавляем последний символ знаменателя
					//cout << "n";
					skip = 0;/// Ставим skip = 0, чтобы считывать следующий возможный числитель
					f[j].initF(stoi(num_str), stoi(denom_str));/// Изменяем дробь
					j++;/// Меняем индекс для следующей возможной дроби
					//cout << endl << "s1 = " << num_str << endl << "s2 = " << denom_str;/// Проверка
					num_str = ""; denom_str = "";/// Обнуление строк для следующей дроби

					i++; i++;/// Перескакиваем через 2 символа - \0 и \n

					goto label;/// Переход на метку назад для повторного прогона. Если найден конец файла, то ничего считываться не будет
				}
				else {
					//cout << s[i];
					denom_str = denom_str + s[i];/// Для обычного считывания, если конец знаменателя не скоро
				}
			}
			i++;
		}
		in_file.close();// Закрытие файла
	}

int main()
{
	string fileOutName = "outFile.txt";/// Имя файла вывода
	string fileOutName_2 = "outFile_2.txt";/// Имя файла вывода 2
	string fileInName = "inFile.txt";/// Имя файла вывода
	int k;/// Количество строк в файле ввода

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

			outputFraction(f1, fileOutName, 1);/// Вывод дробей в файл
			outputFraction(f2, fileOutName, 2);
			outputFraction(f3, fileOutName, 3);
			outputFraction(f4, fileOutName, 4);
			outputFraction(f5, fileOutName, 5);

			for (int i = 1; i <= 4; i++) /// Вывод массива дробей в файл
			{
				outputFraction(arrF[i], fileOutName, i);
			}


			
			
			/// Задание объектов, введённых через файл
			k = rowsNumber(fileInName);/// Количество строк (объектов) в файле
			//cout << k;

			Fraction *arr2 = new Fraction [k];/// Выделение памяти под заданное кол-во объектов
			
			getFraction(arr2, fileInName, k);/// Чтение объектов из файла

			for (int i = 0; i < k; i++) /// Вывод массива дробей в файл
			{
				outputFraction(arr2[i], fileOutName_2, i+1);
			}

}
	
	catch (invalid_argument e) {
		cout << e.what();
	}

	
	return 0;
}

    

