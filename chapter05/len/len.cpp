#include <string>
#include <iostream>

std::string line;

int main(void)
{
	std::cout << "Enter a line: ";
	std::getline(std::cin, line);

	std::cout << "The length of the line is: " << line.length() << '\n';
	return 0;
}
