#include <iostream>

int old_number;
int current_number;
int next_number;

int main(void)
{
	old_number = 1;
	current_number = 1;

	std::cout << "1\n";

	while (current_number < 100) {
		std::cout << current_number << '\n';
		next_number = current_number + old_number;

		old_number = current_number;
		current_number = next_number;
	}
	return 0;
}
