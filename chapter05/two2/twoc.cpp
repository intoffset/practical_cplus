#include <iostream>

signed char ch;

int main(void)
{
	ch = 37;
	std::cout << "The number is " << static_cast<int>(ch) << '\n';
	return 0;
}
