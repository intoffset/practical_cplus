#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>

int main(void)
{
	const int DATA_SIZE = 100;
	int data_array[DATA_SIZE];
	std::ifstream data_file("numbers.dat");
	int i;

	if (data_file.fail()) {
		std::cerr << "Error: Could not open numbers.dat\n";
		exit(8);
	}

	for (i = 0; i < DATA_SIZE; i++) {
		assert(i >= 0);
		assert(i < static_cast<int>(sizeof(data_array)/sizeof(data_array[0])));
		data_file >> data_array[i];
	}

	int total;

	total = 0;
	for (i = 0; i < DATA_SIZE; i++) {
		assert(i >= 0);
		assert(i < static_cast<int>(sizeof(data_array)/sizeof(data_array[0])));
		total += data_array[i];
	}
	std::cout << "Total of all the numbers is " << total << '\n';
	return 0;
}
