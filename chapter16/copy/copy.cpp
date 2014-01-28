#include <cstdio>
#include <cstdlib>
#include <iostream>

const char FILE_NAME[] = "input.txt";

int main(void)
{
	int count = 0;
	std::FILE *in_file;
	
	int ch;

	in_file = std::fopen(FILE_NAME, "rb");
	if (in_file == NULL) {
		std::cerr << "Can not open " << FILE_NAME << '\n';
		exit(8);
	}
	while (true) {
		ch = std::fgetc(in_file);
		if (ch == EOF) {
			break;
		}
		++count;
	}
	std::cout << "Number of characters in " << FILE_NAME
		<< " is " << count << '\n';
	std::fclose(in_file);
	return 0;
}
