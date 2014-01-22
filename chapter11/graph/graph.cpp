#include <iostream>
#include <assert.h>

const int X_SIZE = 40;
const int Y_SIZE = 60;

char graphics[X_SIZE / 8][Y_SIZE];

inline void set_bit(const int x, const int y) {
	assert((x >= 0) && (x < X_SIZE));
	assert((y >= 0) && (y < Y_SIZE));

	graphics[(x)/8][y] |= static_cast<char>(0x80 >> ((x)%8));
}

int main(void)
{
	int loc;
	void print_graphics();

	for (loc = 0; loc < X_SIZE; loc++) {
		set_bit(loc, loc);
	}

	print_graphics();
	return 0;
}

void print_graphics(void) {
	int x;
	int y;
	int bit;

	for (y = 0; y < Y_SIZE; ++y) {
		for (x = 0; x < X_SIZE / 8; ++x) {
			assert((x >= 0) && (x < (X_SIZE/8)));
			assert((y >= 0) && (y < Y_SIZE));
			for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if ((graphics[x][y] & bit) != 0) {
					std::cout << "X";
				} else {
					std::cout << ".";
				}
			}
		}
		std::cout << '\n';
	}
}
