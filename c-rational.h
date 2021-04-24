#pragma once 


namespace c {
	struct rational_num {
		int numerator; // числитель
		int denominator; // знаменатель
		rational_num(int _numerator, int _demoninator);
	};

	rational_num sum(rational_num first, rational_num second);
	rational_num dim(rational_num first, rational_num second);
	rational_num mul(rational_num first, rational_num second);
	rational_num div(rational_num first, rational_num second);
	double conversion(rational_num num);
}