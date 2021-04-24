#pragma once 

namespace cpp {


	class rational_num {
		int numerator;
		int denominator;

	public:
		rational_num(int numerator, int denominator);
		int get_num() {
			return numerator;
		}
		int get_den() {
			return denominator;
		}
		rational_num sum(rational_num second);
		rational_num dim(rational_num second);
		rational_num mul(rational_num second);
		rational_num div(rational_num second);
		double conversion();
		static double conversion(rational_num num);


	};



}
