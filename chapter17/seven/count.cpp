#include <iostream>

int seven_count;
int data[5];
int three_count;

int main(void)
{
	int index;
	void get_data(int data[]);

	seven_count = 0;
	three_count = 0;
	get_data(data);

	for (index = 0; index < 5; index++) {
		if (data[index] == 3) {
			++three_count;
		}
		if (data[index] == 7) {
			++seven_count;
		}
	}
	std::cout << "Three's " << three_count <<
		" Seven's " << seven_count << '\n';
	return 0;
}

/* get_data */
void get_data(int data[]) {
	std::cout << "Enter 5 numbers\n";
	std::cin >> data[0] >> data[1] >> data[2] >> data[3] >> data[4];
}
