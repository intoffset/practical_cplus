#include <iostream>

int array[3][5] = {
	{0,1,2,3,4},
	{10,11,12,13,14},
	{20,21,22,23,24},
};

int main(void)
{
	std::cout << "Last elemet is " << array[2][4] << '\n';
	return 0;
}
