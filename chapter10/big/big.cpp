#include <iostream>

#define BIG_NUMBER 10 * 10

int main(void)
{
	int index;
	index = 1;
	while (index < BIG_NUMBER) {
		index = index * 8;
		std::cout << "index = " << index << std::endl;
	}
	return 0;
}
