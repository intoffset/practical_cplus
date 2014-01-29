const int X_SIZE = 60;
const int Y_SIZE = 30;

int matrix[X_SIZE][Y_SIZE];

void int_matrix() {
	register int index;
	register int *matrix_ptr;
	
	matrix_ptr = &matrix[0][0];
	for (index = 0; index < X_SIZE * Y_SIZE; index++) {
		*matrix_ptr = -1;
		++matrix_ptr;
	}
}
