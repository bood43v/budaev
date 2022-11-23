/// Принадоежности для письма
/// Заголовки методов, описание классов
/// @author Будаев Г.Б.

#include <iostream>
#include <exception>
#include "WritingTools.h"

using namespace std;


int main() {
	try {
		WritingTools Tool("Black", "Blue", 10.5);
		
		Pencil Pencil_v1("Wood", "2H", "Circle");
		Pencil_v1.set_hardness("HB");
		Pencil_v1.setBase("Gray", 15);

		BallPen BallPen_v1("Plastic", 0.5);
		BallPen_v1.set_ballDiameter(0.7);
		BallPen_v1.setBase("Brown", "Blue", 15);

		cout << Tool.toString() << endl;
		cout << Pencil_v1.toString() << endl;
		cout << BallPen_v1.toString() << endl;

		Pencil Pencil_Erichkrause;
		WritingTools Erichkrause;

		WritingTools* Tool_2 = &Pencil_Erichkrause;

		cout << Tool_2->toString();
	}
	catch (invalid_argument e) {
		cout << e.what();
	}
}

