#include "c-rational.h"
#include <iostream>


using namespace c;



int nod_c(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int nok_c(int a, int b)
{
	return a * b / nod_c(a, b);
}

rational_num::rational_num(int _numerator, int _denominator) {
	int  _nod = nod_c(_numerator, _denominator);
	rational_num::denominator = _denominator / _nod;
	rational_num::numerator = _numerator / _nod;
}

rational_num c::sum(rational_num first, rational_num second) {
	int numerator = first.numerator + second.numerator;
	int denominator = first.denominator + second.denominator;
	rational_num tmp(numerator, denominator);
	return tmp;
}

rational_num c::dim(rational_num first, rational_num second) {
	int _nok = nok_c(first.denominator,second.denominator);
	int a = _nok / first.denominator;
	int b = _nok / second.denominator;
	first.numerator = first.numerator * a;
	first.denominator = first.denominator * a;
	second.numerator = second.numerator * b;
	second.denominator = second.denominator * b;
	int numerator = first.numerator - second.numerator;
	int denominator = first.denominator;
	rational_num tmp(numerator, denominator);
	return tmp;
}

rational_num c::mul(rational_num first, rational_num second) {
	int numerator = first.numerator * second.numerator;
	int denominator = first.denominator * second.denominator;
	rational_num tmp(numerator, denominator);
	return tmp;
}

rational_num c::div(rational_num first, rational_num second) {
	if (second.numerator == 0) {
		printf("You can't division on 0 \n");
		return rational_num(0, 0);
	}

	int numerator = first.numerator * second.denominator;
	int denominator = first.denominator * second.numerator;
	rational_num tmp(numerator, denominator);
	return tmp;
}

double c::conversion(rational_num num) {
	return ((double)num.numerator / (double)num.denominator);
}

