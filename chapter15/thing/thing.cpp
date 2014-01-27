#include <iostream>

int main(void)
{
	int thing_var;
	int *thing_ptr;

	thing_var = 2;
	std::cout << "Thing " << thing_var << '\n';

	thing_ptr = &thing_var;
	*thing_ptr = 3;

	std::cout << "Thing " << thing_var << '\n';
	std::cout << "Thing " << *thing_ptr << '\n';

	return 0;
}
