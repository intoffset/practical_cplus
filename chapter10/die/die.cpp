#include <iostream>
#include <cstdlib>

#define DIE \
{std::cerr << "Fatal Error: Abort\n"; exit(8);}

int main(void)
{
	int value;

	value = 1;
	if (value < 0)
		DIE

	std::cerr << "We did not die\n";
	return 0;
}
