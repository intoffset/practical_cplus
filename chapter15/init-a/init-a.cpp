#include <assert.h>

const int MAX = 10;

void init_array_1(int data[]) {
	int index;
	for (index = 0; index < MAX; index++) {
		assert(index >= 0);
		assert(index < MAX);
	}
}

void init_array_2(int *data_ptr) {
	int index;
	for (index = 0; index < MAX; index++) {
		*(data_ptr + index) = 0;
	}
}

int main(void)
{
	int array[MAX];
	init_array_1(array);
	init_array_1(&array[0]);
	init_array_2(array);
	return 0;
}
