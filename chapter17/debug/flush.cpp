#include <iostream>

int main(void)
{
	int i, j;

	i = 1;
	j = 0;
	std::cout << "Starting\n";
	std::cout.flush();
	std::cout << "Before divide...";
	std::cout.flush();
	i = i / j;
	std::cout << "After\n";
	std::cout.flush();
	return 0;
}
