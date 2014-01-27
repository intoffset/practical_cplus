#include <assert.h>
#include <iostream>
#include <iomanip>

const int ARRAY_SIZE = 10;
char array[ARRAY_SIZE] = "012345678";

int main(void)
{
	int index;

	for (index = 0; index < ARRAY_SIZE; index++) {
		std::cout << std::hex;
		assert(index >= 0);
		assert(index < static_cast<int>(sizeof(array)/sizeof(array[0])));

		std::cout << "&array[index]=0x" <<
			reinterpret_cast<int>(&array[index]) <<
			" (array+index)=0x" <<
			reinterpret_cast<int>(array+index) <<
			" array[index]=" << std::dec <<
			array[index] << '\n';
		std::cout << std::dec;
			
	}
	return 0;
}
