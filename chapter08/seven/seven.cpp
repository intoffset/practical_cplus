#include <iostream>

int seven_count;
int data[5];
int three_count;
int index;

int main(void)
{
	seven_count = 0;
	three_count = 0;

	std::cout << "Enter 5 numbers\n";
	std::cin >> data[0] >> data[1] >> data[2] >> data[3] >> data[4];

	for (index = 0; index < 5; index++) {
		if (data[index] == 3) {
			++three_count;
		}
		if (data[index] == 7) {
			++seven_count;
		}
	}
	std::cout << "Threes " << three_count << " Sevens " << seven_count << '\n';
	return 0;
}
