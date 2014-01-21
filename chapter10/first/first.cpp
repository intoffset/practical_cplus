#include <iostream>

#define FIRST_PART 7
#define LAST_PART 5
#define ALL_PARTS (FIRST_PART + LAST_PART)

int main(void)
{
	std::cout << "The square of all the parts is " <<
		ALL_PARTS * ALL_PARTS << '\n';
	return 0;
}
