#include <iostream>

int main(void)
{
	int counter;
	for (counter = 0; counter < 3; counter++) {
		int temporary = 1;
		static int permanent = 1;

		std::cout << "Temporary " << temporary <<
			" Permanent " << permanent << '\n';
		++temporary;
		++permanent;
	}
	return 0;
}
