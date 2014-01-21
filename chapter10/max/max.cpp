#include <iostream>

#define MAX 10

int main(void)
{
	int counter;

	for (counter=MAX; counter > 0; --counter) {
		std::cout << "Hi there\n";
	}
	return 0;
}
