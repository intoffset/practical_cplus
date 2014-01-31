#include <iostream>
#include <iomanip>

int main(void)
{
	float number1, number2;
	float result;
	int   counter;

	number1 = 1.0;
	number2 = 1.0;
	counter = 0;

	while (number1 + number2 != number1) {
		++counter;
		number2 = number2 / 10.0;
	}

	std::cout << std::setw(2) << counter << " digits accuracy in calculations" << std::endl;

	number2 = 1.0;
	counter = 0;

	while (true) {
		result = number1 + number2;
		if (result == number1) {
			break;
		}
		++counter;
		number2 = number2 / 10.0;
	}
	std::cout << std::setw(2) << counter << " digits accuracy in storage" << std::endl;
	return 0;
}
