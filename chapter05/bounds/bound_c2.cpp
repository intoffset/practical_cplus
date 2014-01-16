#include <iostream>
#include <assert.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17};

int main(void)
{
	int index = 10;

	assert(index < static_cast<int>((sizeof(primes) / sizeof(primes[0]))));
	assert(index >= 0);
	std::cout << "The tenth prime is " << primes[index] << '\n';
	return 0;
}
