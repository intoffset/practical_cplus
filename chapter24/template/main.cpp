#include <iostream>
#include "square.h"
#include "integer.h"

int main(void)
{
	integer test(5);
	integer test2 = square(test);
	std::cout << "test2.value = " << test2.value << '\n';
	return 0;
}
