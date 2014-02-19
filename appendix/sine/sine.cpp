#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>

int main(int argc, char const* argv[])
{
	float total;
	float new_total;
	float term_top;
	float term_bottom;
	float term;
	float exp;
	float sign;
	float value;
	int index;

	char *float_2_ascii(float number);
	float fix_float(float number);
	float factorial(float number);

	if (argc != 2) {
		std::cerr << "Usage is:\n";
		std::cerr << "  sine <value>\n";
		exit(8);
	}

	value = fix_float(atof(&argv[1][0]));

	total = 0.0;
	exp   = 1.0;
	sign  = 1.0;

	for (index = 0; ; ++index) {
		term_top    = fix_float(pow(value, exp));
		term_bottom = fix_float(factorial(exp));
		term = fix_float(term_top / term_bottom);

		std::cout << "x**" << static_cast<int>(exp) << "     " <<
			float_2_ascii(term_top) << '\n';
		std::cout << static_cast<int>(exp) << "!       " <<
			float_2_ascii(term_bottom) << '\n';
		std::cout << "x**" << static_cast<int>(exp) << "/" <<
			static_cast<int>(exp) << "!  " <<
			float_2_ascii(term) << '\n';

		new_total = fix_float(total + sign * term);
		if (new_total == total) {
			break;
		}

		total = new_total;
		sign = -sign;
		exp = exp + 2;
		std::cout << "  total  " << float_2_ascii(total) << '\n';
		std::cout << '\n';
	}

	std::cout << "  " << (index + 1) << " term computed\n";
	std::cout << "sin(" << float_2_ascii(value) << ")=\n";
	std::cout << "  " << float_2_ascii(total) << '\n';
	std::cout << "Actual sin(" << atof(&argv[1][0]) << ")=" <<
		sin(atof(&argv[1][0])) << '\n';

	return 0;
}

/*************************************************
 * float_2_ascii -- convert float to ascii
 * arguments:
 *   number -- float number
 * return:
 *   pointer of number-character
 *************************************************/
char *float_2_ascii(float number) {
	static char result[10];

	std::sprintf(result, "%8.3E", number);
	return result;
}

/*************************************************
 * fix_float -- convert to low precision number
 * arguments:
 *   number -- float number
 * return:
 *   5 decimal number
 *************************************************/
float fix_float(float number) {
	float result;
	char ascii[11];

	std::sprintf(ascii, "%8.4e", number);
	std::sscanf(ascii, "%e", &result);
	return result;
}

/*************************************************
 * factorial -- calculate fractorial
 * arguments:
 *   number -- float number
 * return:
 *   fractorial(number) or number!
 *************************************************/
float factorial(float number) {
	if (number <= 1.0) {
		return number;
	} else {
		return (number * factorial(number - 1.0));
	}
}
