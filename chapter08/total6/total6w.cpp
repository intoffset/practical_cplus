#include <iostream>

int total;
int current;
int counter;

int main(void)
{
	total = 0;
	counter = 0;

	while (counter < 5) {
		std::cout << "Number? ";

		std::cin >> current;
		total += current;

		++counter;
	}
	std::cout << "The grand total is " << total << '\n';
	return 0;
}
