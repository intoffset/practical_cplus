#include <iostream>
#include <cstring>
#include <cstdlib>

int main(void)
{
	char line[80];
	char *first_ptr;
	char *last_ptr;

	std::cout << "Enter string\n";

	std::cin.getline(line, sizeof(line));

	last_ptr = line;
	first_ptr = strchr(line, '/');

	if (first_ptr == NULL) {
		std::cerr << "Error: Unable to find slash in " << line << '\n';
		exit(8);
	}

	*first_ptr = '\0';
	++first_ptr;
	std::cout << "First:" << first_ptr << " Last:" << last_ptr << '\n';
	return 0;
}
