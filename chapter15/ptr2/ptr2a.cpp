#include <assert.h>
#include <iostream>

int array[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int the_index;

int main(void)
{
	the_index = 0;
	while (true) {
		assert(the_index >= 0);
		assert(the_index < static_cast<int>(sizeof(array)/sizeof(array[0])));

		if (array[the_index] == 0) {
			break;
		}
		++the_index;
	}
	std::cout << "Number of elements before zero " << the_index << '\n';
	return 0;
}
