/// Принадлежности для письма
/// Заголовки методов, описание классов
/// @author Будаев Г.Б.

#include <iostream>
#include <exception>
#include <string>
#include "WritingTools.h"

using namespace std;

string eraseNulls(double number) {
	string numStr = to_string(number);
	if (numStr[numStr.size() - 1] == '0')
		for (size_t i = numStr.size() - 1; numStr[i] == '0'; i--)
			numStr.erase(i, 1);

	if (numStr[numStr.size() - 1] == '.')
	numStr.erase(numStr.size() - 1, 1);
	return numStr;
}

	WritingTools::WritingTools() { /// Конструктор без параметров
		mainColor = "Black";
		writingColor = "Black";
		lenght_sm = 12;
	}

	WritingTools::WritingTools(string color1, string color2, double len) { /// Конструктор с параметрами
		if (color1 == "") throw invalid_argument("Error: field mainColor is empty");
		if (color2 == "") throw invalid_argument("Error: field writingColor is empty");
		if (len != (double)len) throw invalid_argument("Error: diameter isn't number");
		if (len <= 0) throw invalid_argument("Error: field l <= 0");
		mainColor = color1;
		writingColor = color2;
		lenght_sm = len;
	}

	WritingTools::~WritingTools(){} /// Деструктор

	string WritingTools::toString() /// Вывод в одну строку
	{
		return mainColor + " " + writingColor + " " + eraseNulls(lenght_sm) + " sm";
	}

	void WritingTools::set_lenght(double l) { /// Установить длину
		if (l != (double)l) throw invalid_argument("Error: diameter isn't number");
		if (l <= 0) throw invalid_argument("Error: field l <= 0");
		lenght_sm = l;
	}

	double WritingTools::get_length() { /// Вернуть длину
		return lenght_sm;
	}

	void WritingTools::set_mainColor(string color) { /// Установить основной цвет
		if (color == "") throw invalid_argument("Error: field mainColor is empty");
		mainColor = color;
	}

	string WritingTools::get_mainColor() { /// Вернуть основной цвет
		return mainColor;
	}

	void WritingTools::set_writingColor(string color) { /// Установить цвет письма
		if (color == "") throw invalid_argument("Error: field writingColor is empty");
		writingColor = color;
	}

	string WritingTools::get_writingColor() { /// Вернуть цвет письма
		return writingColor;
	}


	Pencil::Pencil() { /// Конструктор без параметров
		shellMaterial = "edit";
		hardness = "edit";
		sectionShape = "edit";
	}

	Pencil::Pencil(string material, string key, string shape) { /// Конструктор с параметрами
		if (material == "") throw invalid_argument("Error: field shellMaterial is empty");
		if (key == "") throw invalid_argument("Error: field hardness is empty");
		if (shape == "") throw invalid_argument("Error: field sectionShape is empty");
		shellMaterial = material;
		hardness = key;
		sectionShape = shape;
	}

	Pencil::~Pencil() {} /// Деструктор

	void Pencil::setBase(string color1, double len) { /// Конструктор с параметрами
		if (color1 == "") throw invalid_argument("Error: field mainColor is empty");
		//if (color2 == "") throw invalid_argument("Error: field writingColor is empty");
		if (len != (double)len) throw invalid_argument("Error: diameter isn't number");
		if (len <= 0) throw invalid_argument("Error: field l <= 0");
		mainColor = color1;
		//writingColor = color2;
		lenght_sm = len;
	}

	string Pencil::toString() /// Вывод в одну строку
	{
		return WritingTools::toString() + " " + shellMaterial + " " + hardness + " " + sectionShape;
		//return  mainColor + " " + writingColor + " " + eraseNulls(lenght_sm) + " cm" + " " + shellMaterial + " " + hardness + " " + sectionShape;
	}



	void Pencil::set_bodyMaterial(string material) /// Установить материал оболочки
	{
		if (material == "") throw invalid_argument("Error: field material is empty");
		shellMaterial = material;
	}

	string Pencil::get_bodyMaterial() /// Вернуть материал оболочки
	{
		return shellMaterial;
	}

	void Pencil::set_hardness(string key) /// Установить твёрдость стержня
	{
		if (key == "") throw invalid_argument("Error: field hardness is empty");
		hardness = key;
	}

	string Pencil::get_hardness() /// Вернуть твёрдость стержня
	{
		return hardness;
	}

	void Pencil::set_sectionShape(string shape) /// Установить форму сечения
	{
		if (shape == "") throw invalid_argument("Error: field shape is empty");
		sectionShape = shape;
	}

	string Pencil::get_sectionShape() /// Вернуть форму сечения
	{
		return sectionShape;
	}




	BallPen::BallPen() { /// Конструктор без параметров
		bodyMaterial = "edit";
		ballDiameter = 1;
	}

	BallPen::BallPen(string material, double d) { /// Конструктор с параметрами
		if (material == "") throw invalid_argument("Error: field material is empty");
		if (d != (double)d) throw invalid_argument("Error: diameter isn't number");//todo
		if (d <= 0) throw invalid_argument("Error: field d <= 0");
		bodyMaterial = material;
		ballDiameter = d;
	}

	BallPen::~BallPen() {} /// Деструктор

	void BallPen::setBase(string color1, string color2, double len) { /// Конструктор с параметрами
		if (color1 == "") throw invalid_argument("Error: field mainColor is empty");
		if (color2 == "") throw invalid_argument("Error: field writingColor is empty");
		if (len != (double)len) throw invalid_argument("Error: diameter isn't number");
		if (len <= 0) throw invalid_argument("Error: field l <= 0");
		mainColor = color1;
		writingColor = color2;
		lenght_sm = len;
	}

	string BallPen::toString() /// Вывод в одну строку
	{
		return WritingTools::toString() + " " + bodyMaterial + " " + eraseNulls(ballDiameter) + " mm";
		//return mainColor + " " + writingColor + " " + eraseNulls(lenght_sm) + " cm" + " " + bodyMaterial + " " + eraseNulls(ballDiameter) + " mm";
	}

	void BallPen::set_bodyMaterial(string material) /// Установить материал корпуса
	{
		if (material == "") throw invalid_argument("Error: field material is empty");
		bodyMaterial = material;
	}

	string BallPen::get_bodyMaterial() /// Вернуть материал корпуса
	{
		return bodyMaterial;
	}

	void BallPen::set_ballDiameter(double d) /// Установить диаметр шарика
	{
		if (d != (double)d) throw invalid_argument("Error: diameter isn't number");//todo
		if (d <= 0) throw invalid_argument("Error: field d <= 0");
		ballDiameter = d;
	}

	double BallPen::get_ballDiameter() /// Вернуть диаметр шарика
	{
		return ballDiameter;
	}

