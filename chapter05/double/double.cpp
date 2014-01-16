#include <iostream>

int value;

int main(void)
{
	std::cout << "Enter a value: ";
	std::cin >> value;
	std::cout << "Twice " << value << " is " << value*2 << '\n';
	return 0;
}
