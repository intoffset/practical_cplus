#include <iostream>

int length(char string[]) {
	int index;
	for (index = 0; string[index] != '\0'; index++) {
	}
	return index;
}

int main(void)
{
	char str[] = "string";
	std::cout << "string length is " << length(str) << '\n';
	return 0;
}
