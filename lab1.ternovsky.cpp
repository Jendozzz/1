#include <iostream>
#include "c-rational.h"
#include "cpp-rational.h"


const int size_mass = 100; //input
const int code_sign_minus = 45;//input
const int code_dot = 46;//input
const int code_digit_0 = 48;//input
const int code_digit_9 = 57;//input

double determinate_num(const char* ptr) { //input
	int length_str = strlen(ptr) - 1;
	for (int i = 0; i < length_str; i++)
	{
		if (ptr[i] > code_digit_9 || ptr[i] < code_digit_0 && ptr[0] != code_sign_minus && ptr[i] != code_dot)
			return nan("1");
	}
	return strtod(ptr, NULL);
}

double input_num() { //input
	char mass[size_mass] = "0";
	double num = 0;
	do {
		memset(mass, 0, sizeof(char) * size_mass);
		fgets(mass, size_mass, stdin);
		num = determinate_num(mass);
		if (num != num)
			printf("Number is uncorrect. Try again: ");
		else
			break;
	} while (true);
	return num;

}


int main() {

	printf("Put numerator first num\n");
	int numerator1 = (int)input_num();
	printf("Put denominator first num\n");
	int denominator1 = (int)input_num();
	while (denominator1 == 0) {
		printf("Denominator incorect , try another\n");
		denominator1 = (int)input_num();
	}
	
	printf("Put numerator second num\n");
	int numerator2 = (int)input_num();
	printf("Put denominator second num\n");
	int denominator2 = (int)input_num();
	while (denominator2 == 0) {
		printf("Denominator incorect , try another\n");
		denominator2 = (int)input_num();
	}
	{
		using namespace c;
		rational_num a1(numerator1, denominator1);
		rational_num a2(numerator2, denominator2);
		printf("a1 : %d/%d\n", a1.numerator, a1.denominator);
		printf("a2 : %d/%d\n", a2.numerator, a2.denominator);
		rational_num a3 = sum(a1, a2);
		printf("a1+a2 %d/%d\n", a3.numerator, a3.denominator);
		rational_num a4 = dim(a1, a2);
		printf("a1-a2 %d/%d\n", a4.numerator, a4.denominator);
		rational_num a5 = mul(a1, a2);
		printf("a1*a2 %d/%d\n", a5.numerator, a5.denominator);
		rational_num a6 = div(a1, a2);
		printf("a1/a2 %d/%d\n", a6.numerator, a6.denominator);
		double a7 = conversion(a2);
		printf("a2  %f\n", a7);
	}
	printf("\n\n\n\n");
	{
		using namespace cpp;
		rational_num a1(numerator1, denominator1);
		rational_num a2(numerator2, denominator2);
		printf("a1 : %d/%d\n", a1.get_num(), a1.get_den());
		printf("a2 : %d/%d\n", a2.get_num(), a2.get_den());
		rational_num a3 = a1.sum(a2);
		printf("a1+a2 %d/%d\n", a3.get_num(), a3.get_den());
		rational_num a4 = a1.dim(a2);
		printf("a1-a2 %d/%d\n", a4.get_num(), a4.get_den());
		rational_num a5 = a1.mul(a2);
		printf("a1*a2 %d/%d\n", a5.get_num(), a5.get_den());
		rational_num a6 = a1.div(a2);
		printf("a1/a2 %d/%d\n", a6.get_num(), a6.get_den());
		double a7 = rational_num::conversion(a2);
		double a8 = a2.conversion();
		printf("a2  %f\n", a7);
		printf("a2  %f\n", a8);

	}

}

