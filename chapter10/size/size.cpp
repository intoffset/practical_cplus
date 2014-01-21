#include <iostream>

#define SIZE 10
#define FUDGE SIZE - 2

int main(void)
{
	int size;

	size = FUDGE;
	std::cout << "Size is " << size << '\n';
	return 0;
}

