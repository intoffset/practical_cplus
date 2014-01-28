#include <iostream>
#include <iomanip>

int main(void)
{
	int number = 12;
	float real = 12.34;

	std::cout << "123456789012345678901234567890\n";
	std::cout << number << "<-\n";
	std::cout << std::setw(5) << number << "<-\n";
	std::cout << std::setw(5) << std::setfill('*') << number << "<-\n";
	std::cout << std::setiosflags(std::ios::showpos|std::ios::left) <<
		std::setw(5) << number << "<-\n";
	std::cout << real << "<-\n";
	std::cout << std::setprecision(1) <<
		std::setiosflags(std::ios::fixed) << real << "<-\n";
	std::cout << std::setiosflags(std::ios::scientific) << real << "<-\n";
	return 0;
}
