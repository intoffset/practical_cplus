#include <iostream>

int main(void)
{
	int number;

	std::cout << "Enter a number: ";

	std::cin >> number;

	if (number != 2) {
		std::cout << "Number is not two\n";
	} else {
		std::cout << "Number is two\n";
	}
	return 0;
}
