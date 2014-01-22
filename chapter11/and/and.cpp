#include <iostream>

int main(void)
{
	int i1, i2;

	i1 = 4;
	i2 = 2;

	if ((i1 != 0) && (i2 != 0)) {
		std::cout << "Both are not zero #1\n";
	}
	if (i1 && i2) {
		std::cout << "Both are not zero #2\n";
	}
	if (i1 & i2) {
		std::cout << "Both are not zero #3\n";
	}
	return 0;
}
