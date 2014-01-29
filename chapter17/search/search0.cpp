#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <assert.h>

const int MAX_NUMBERS = 1000;
const char *const DATA_FILE = "numbers.dat";

int data[MAX_NUMBERS];
int max_count;

int main(void)
{
	std::ifstream in_file;
	int middle;
	int low, high;
	int search;

	in_file.open(DATA_FILE, std::ios::in);
	if (in_file.fail()) {
		std::cerr << "Error: Unable to open " << DATA_FILE << '\n';
		exit(8);
	}

	max_count = 0;

	while (true) {
		char line[30];
		if (in_file.eof()) {
			break;
		}
		in_file.getline(line, sizeof(line));

		assert(max_count >= 0);
		assert(max_count < static_cast<int>(sizeof(data)/sizeof(data[0])));
		std::sscanf(line, "%d", &data[max_count]);
		if (data[max_count] == -1) {
			break;
		}
		++max_count;
	}

	while (true) {
		std::cout << "Enter number to search for or -1 to quit: ";
		std::cin >> search;

		if (search == -1) {
			break;
		}

		low = 0;
		high = max_count;

		while (true) {
			middle = (low + high) / 2;

			assert(middle >= 0);
			assert(middle < static_cast<int>(sizeof(data)/sizeof(data[0])));

			if (data[middle] == search) {
				std::cout << "Found at index " << middle << '\n';
				break;
			}

			if (low >= high) {
				std::cout << "Not found\n";
				break;
			}

			assert(middle >= 0);
			assert(middle < static_cast<int>(sizeof(data)/sizeof(data[0])));

			if (data[middle] < search) {
				low = middle + 1;
			} else {
				high = middle - 1;
			}
		}
	}
	
	return 0;
}
