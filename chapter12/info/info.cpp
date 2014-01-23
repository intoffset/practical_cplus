#include <iostream>

struct info {
	unsigned int valid:1;
	int data:31;
};

struct info a_info;

int main(void)
{
	a_info.valid = 1;
	if (a_info.valid == 1) {
		std::cout << "a_info is valid\n";
	}
	return 0;
}
