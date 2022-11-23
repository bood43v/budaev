/// Принадлежности для письма
/// Заголовки методов, описание классов
/// @author Будаев Г.Б.

#include <iostream>

using namespace std;

class WritingTools /// Класс принадлежности для письма
{
protected:
	double lenght_sm;
	string mainColor; /// Основной цвет
	string writingColor;/// Цвет письма

public:

	WritingTools(); /// Конструктор без параметров

	WritingTools(string color1, string color2, double len); /// Конструктор с параметрами

	~WritingTools(); /// Деструктор

	virtual string toString(); /// Вывод в одну строку

	void set_lenght(double l); /// Установить длину

	double get_length(); /// Вернуть длину

	void set_mainColor(string color); /// Установить основной цвет

	string get_mainColor(); /// Вернуть основной цвет

	void set_writingColor(string color); /// Установить цвет письма

	string get_writingColor(); /// Вернуть цвет письма

};

class Pencil : public WritingTools /// Класс простого карандаша
{
private:
	string shellMaterial; /// Материал оболочки
	string hardness; /// Твёрдость
	string sectionShape; /// Форма в разрезе

public:
	Pencil(); /// Конструктор без параметров

	Pencil(string material, string key, string shape);/// Конструктор с параметрами

	~Pencil(); /// Деструктор

	void setBase(string color1, double len);

	string toString() override; /// Вывод в одну строку /// Метод переопределён

	void set_bodyMaterial(string material); /// Установить материал оболочки

	string get_bodyMaterial();/// Вернуть материал оболочки

	void set_hardness(string key); /// Установить твёрдость стержня

	string get_hardness(); /// Вернуть твёрдость стержня


	void set_sectionShape(string shape); /// Установить форму сечения

	string get_sectionShape(); /// Вернуть форму сечения
};


class BallPen : public WritingTools /// Класс шариковая ручка
{
protected:
	string bodyMaterial; /// Материал корпуса
	double ballDiameter; /// Диаметр шарика

public:

	BallPen(); /// Конструктор без параметров

	BallPen(string material, double d); /// Конструктор с параметрами

	~BallPen(); /// Деструктор

	void setBase(string color1, string color2, double len);

	string toString() override; /// Вывод в одну строку

	void set_bodyMaterial(string material); /// Установить материал корпуса

	string get_bodyMaterial(); /// Вернуть материал корпуса

	void set_ballDiameter(double d); /// Установить диаметр шарика

	double get_ballDiameter(); /// Вернуть диаметр шарика
};
