#include <iostream>

int total;
int current;
int counter;

int main(void)
{
	total = 0;

	for (counter = 0; counter < 5; counter++) {
		std::cout << "Number? ";

		std::cin >> current;
		total += current;
	}
	std::cout << "The grand total is " << total << '\n';
	return 0;
}
