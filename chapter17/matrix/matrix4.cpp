#include <assert.h>

const int X_SIZE = 60;
const int Y_SIZE = 32;

int matrix[X_SIZE][Y_SIZE];

void int_matrix() {
	register int x, y;
	for (y = 0; y < Y_SIZE; y++) {
		for (x = 0; x < X_SIZE; x++) {
			assert((x >= 0) && (x < X_SIZE));
			assert((y >= 0) && (y < Y_SIZE));
			matrix[x][y] = -1;
		}
	}
}
