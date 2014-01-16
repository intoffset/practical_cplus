#include <iostream>

const int N_PRIMES = 7;

int primes[N_PRIMES] = {2, 3, 5, 7, 11, 13, 17};

int main(void)
{
	int index = 10;
	std::cout << "The tenth prime is " << primes[index] << '\n';
	return 0;
}
