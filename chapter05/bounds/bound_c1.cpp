#include <iostream>
#include <assert.h>

const int N_PRIMES = 7;

int primes[N_PRIMES] = {2, 3, 5, 7, 11, 13, 17};

int main(void)
{
	int index = 10;

	assert(index < N_PRIMES);
	assert(index >= 0);
	std::cout << "The tenth prime is " << primes[index] << '\n';
	return 0;
}
