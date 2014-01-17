#include <iostream>

int celsius;

int main(void)
{
	for (celsius = 0; celsius <= 100; celsius++) {
		std::cout << "Celsius: " << celsius <<
			" Fahrenheit: " << ((celsius * 9) / 5 + 32) << '\n';
	}
	return 0;
}
