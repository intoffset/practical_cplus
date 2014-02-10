#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>

#include "ia.h"

const int NUMBER_OF_LINES = 50;
const int LOW_BOUND = 0;
const int HIGH_BOUND = 99;

const int FACTOR = ((HIGH_BOUND - LOW_BOUND + 1) / NUMBER_OF_LINES);

const int WIDTH = 60;

static infinite_array data_array;

static int data_items;

int main(int argc, char const* argv[])
{
	void read_data(const char *const name);
	void print_histogram();

	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments\n";
		std::cerr << "Usage is:\n";
		std::cerr << "  hist <data-file>\n";
		exit(8);
	}
	data_items = 0;
	
	read_data(argv[1]);
	print_histogram();
	return 0;
}

void read_data(const char *const name) {
	std::ifstream in_file(name);
	int data;

	if (in_file.bad()) {
		std::cerr << "Error: Unable to open " << name << '\n';
		exit(8);
	}
	while (!in_file.eof()) {
		in_file >> data;
		if (in_file.eof()) {
			break;
		}
		data_array[data_items] = data;
		++data_items;
	}
}

void print_histogram() {
	int counters[NUMBER_OF_LINES];
	int low;
	int out_of_range = 0;
	int max_count = 0;
	float scale;
	int index;

	std::memset(counters, '\0', sizeof(counters));

	for (index = 0; index < data_items; ++index) {
		int data;

		data = data_array[index];

		if ((data < LOW_BOUND) || (data > HIGH_BOUND)) {
			++out_of_range;
		} else {
			int count_index;
			count_index = static_cast<int>(static_cast<float>(data - LOW_BOUND) / FACTOR);
			assert(count_index >= 0);
			assert(count_index <
					static_cast<int>(sizeof(counters)/sizeof(counters[0])));
			++counters[count_index];
			if (counters[count_index] > max_count) {
				max_count = counters[count_index];
			}
		}
	}

	scale = float(max_count) / float(WIDTH);

	low = LOW_BOUND;

	for (index = 0; index < NUMBER_OF_LINES; ++index) {
		int char_index;
		int number_of_dots;
		std::cout << std::setw(2) << index << ' ' <<
			std::setw(3) << low << "-" <<
			std::setw(3) << (low + FACTOR - 1) << " (" <<
			std::setw(4) << counters[index] << "): ";

		number_of_dots = int(float(counters[index]) / scale);
		for (char_index = 0; char_index < number_of_dots; ++char_index) {
			std::cout << '*';
		}
		std::cout << '\n';
		low += FACTOR;
	}
	std::cout << out_of_range << " items out of range\n";
}
