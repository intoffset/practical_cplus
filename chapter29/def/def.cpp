#include <iostream>
#include <cstdlib>

int main(void)
{
	char line[10];

	while (true) {
		std::cout << "Enter add(a), delete(d), quit(q): ";
		std::cin.getline(line, sizeof(line));

		switch (line[0]) {
			case 'a':
				std::cout << "Add\n";
				break;
			case 'd':
				std::cout << "Delete\n";
				break;
			case 'q':
				std::cout << "Quit\n";
				exit(0);
			default:
				std::cout << "Error: Bad command " << line[0] << '\n';
				break;
		}
	}
	return 0;
}
