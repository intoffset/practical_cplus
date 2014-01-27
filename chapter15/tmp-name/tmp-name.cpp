#include <iostream>
#include <cstring>

char* tmp_name(void) {
	static char name[30];
	static int sequence = 0;

	++sequence;

	strcpy(name, "tmp");

	name[3] = static_cast<char>(sequence + '0');
	name[4] = '\0';
	return name;
}

int main(void)
{
	std::cout << "Name: " << tmp_name() << '\n';
	std::cout << "Name: " << tmp_name() << '\n';
	return 0;
}
