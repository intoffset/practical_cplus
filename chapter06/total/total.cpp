#include <iostream>

int total;
int item;

int main(void)
{
	total = 0;
	while (true) {
		std::cout << "Enter # to add \n";
		std::cout << " or 0 to stop:";
		std::cin >> item;

		if (item == 0) {
			break;
		}

		total += item;
		std::cout << "Total: " << total << '\n';
	}
	std::cout << "Final total " << total << '\n';
	return 0;
}
