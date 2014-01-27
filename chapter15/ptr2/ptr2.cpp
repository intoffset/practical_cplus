#include <iostream>

int array[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int *array_ptr;

int main(void)
{
	array_ptr = array;

	while ((*array_ptr) != 0) {
		++array_ptr;
	}
	std::cout << "Number of elements before zero " <<
		(array_ptr - array) << '\n';
	return 0;
}
