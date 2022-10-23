/// https://pastebin.com/N29yVdwk
#include "pch.h"
#include "../class_fraction/fraction.cpp" /// ñ fraction.h âûäà¸ò îøèáêó LNK2019, ïîêà íå ðàçîáðàëñÿ

/// Èçìåíåíèå äðîáè, ïîëó÷åíèå ÷èñëèòåëÿ è çíàìåíàòåëÿ
TEST(TestFraction, Test_init_getNumDenomF) {
	Fraction f(2, 5);

	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 5);

	f.initF(5, 7);

	EXPECT_EQ(f.getNumeratorF(), 5);
	EXPECT_EQ(f.getDenominatorF(), 7);
}

/// Ñðàâíåíèå äðîáåé
TEST(TestFraction, Test_compareF) {
	Fraction f1(11, 20);
	Fraction f2(10, 20);

	EXPECT_EQ(f1.compareF(f2), 1);
}

/// Ñóììà äðîáåé
TEST(TestFraction, Test_addF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);
	
	Fraction f3 = f1.addF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 11);
	EXPECT_EQ(f3.getDenominatorF(), 5);
}

/// Ðàçíîñòü äðîáåé
TEST(TestFraction, Test_subF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.subF(f2);

	EXPECT_EQ(f3.getNumeratorF(), -7);
	EXPECT_EQ(f3.getDenominatorF(), 5);
}

/// Ïðîèçâåäåíèå äðîáåé
TEST(TestFraction, Test_multF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.multF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 18);
	EXPECT_EQ(f3.getDenominatorF(), 25);
}

/// ×àñòíîå äðîáåé
TEST(TestFraction, Test_divF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.divF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 2);
	EXPECT_EQ(f3.getDenominatorF(), 9);
}

/// Íàèáîëüøèé îáùèé äåëèòåëü
TEST(TestFraction, Test_nod) {
	Fraction f;
	int x = 24;
	int y = 36;

	EXPECT_EQ(f.nod(x,y), 12);
}

/// Ñîêðàùåíèå äðîáè
TEST(TestFraction, Test_shortenF) {
	Fraction f(4, 10);

	f.shortenF();

	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 5);
}
/// Ïåðåâîä äðîáè â âåùåñòâåííîå ÷èñëî
TEST(TestFraction, Test_convertToDoubleF) {
	Fraction f(4, 10);

	EXPECT_EQ(f.convertToDoubleF(), 0.4);

}
