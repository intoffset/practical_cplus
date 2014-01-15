#include <iostream>

char char1;
char char2;
char char3;

int main(void)
{
	char1 = 'A';
	char2 = 'B';
	char3 = 'C';

	std::cout << char1 << char2 << char3 << " reversed is " <<
		char3 << char2 << char1 << "\n";

	return 0;
}
