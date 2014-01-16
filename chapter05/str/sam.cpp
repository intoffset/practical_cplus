#include <iostream>
#include <cstring>

char name[30];

int main(void)
{
	std::strcpy(name, "Sam");
	std::cout << "This name is " << name << '\n';
	return 0;
}
