#include <iostream>
#include <cstring>

char first[100];
char last[100];
char full_name[100];

int main(void)
{
	std::strcpy(first, "Steve");
	std::strcpy(last, "Oualline");

	std::strcpy(full_name, first);
	std::strcat(full_name, " ");
	std::strcat(full_name, last);

	std::cout << "This full name is " << full_name << '\n';
	return 0;
}
