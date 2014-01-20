#include <iostream>

const int & min(const int& i1, const int& i2) {
	if (i1 < i2) {
		return i1;
	}
	return i2;
}

int main(void)
{
	const int& i = min(1+2, 3+4);
	std::cout << "i = " << i << '\n';
	return 0;
}
