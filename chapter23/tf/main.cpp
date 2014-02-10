#include <iostream>

extern int counter;

extern void inc_counter();

int main(void)
{
	int index;

	for (index = 0; index < 10; ++index) {
		inc_counter();
	}
	std::cout << "Counter is " << counter << '\n';
	return 0;
}
