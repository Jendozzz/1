#include "cpp-rational.h"
#include <iostream>

using namespace cpp;


int nod(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int nok(int a, int b)
{
	return a * b / nod(a, b);
}


rational_num::rational_num(int numerator, int denominator) {
	int  _nod = nod(numerator, denominator);
	rational_num::denominator = denominator / _nod;
	rational_num::numerator = numerator / _nod;
}

rational_num rational_num::sum(rational_num second) {
	int _numerator = numerator + second.numerator;
	int _denominator = denominator + second.denominator;
	rational_num tmp(_numerator, _denominator);
	return tmp;
}

rational_num rational_num::dim(rational_num second){
	int _nok = nok(denominator, second.denominator);
	int a = _nok / denominator;
	int b = _nok / second.denominator;
	int numerator_first = numerator * a;
	int denominator_first = denominator * a;
	int numerator_second = second.numerator * b;
	int denominator_second = second.denominator * b;
	int numerator = numerator_first - numerator_second;
	int denominator = denominator_second;
	rational_num tmp(numerator, denominator);
	return tmp;
}

rational_num rational_num::mul(rational_num second){
	int _numerator = numerator * second.numerator;
	int _denominator = denominator * second.denominator;
	rational_num tmp(_numerator, _denominator);
	return tmp;
}

rational_num rational_num::div(rational_num second){
	if (second.numerator == 0) {
		printf("You can't division on 0 \n");
		return rational_num(0, 0);
	}
	int _numerator = numerator * second.denominator;
	int _denominator = denominator * second.numerator;
	rational_num tmp(_numerator, _denominator);
	return tmp;
}
double rational_num::conversion(){
	return ((double)numerator / (double)denominator);
}
double rational_num::conversion(rational_num num) {
	return ((double)num.numerator / (double)num.denominator);
}