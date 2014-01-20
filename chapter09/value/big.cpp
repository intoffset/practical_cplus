#include <iostream>

int& biggest(int array[], int n_elements) {
	int index;   // current index
	int biggest; // index of biggest element

	biggest = 0;
	for (index = 0; index < n_elements; index++) {
		if (array[biggest] < array[index]) {
			biggest = index;
		}
	}
	return array[biggest];
}

int main(void)
{
	int item_array[] = {1, 2, 5000, 3, 4};
	std::cout << "The biggest element is " <<
		biggest(item_array, 5) << '\n';

	int &big_reference = item_array[2];
	big_reference = 0;

	std::cout << "The biggest element is " <<
		biggest(item_array, 5) << '\n';

	biggest(item_array, 5) = 0;

	std::cout << "The biggest element is " <<
		biggest(item_array, 5) << '\n';

	return 0;
}
