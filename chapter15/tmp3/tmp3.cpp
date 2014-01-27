#include <iostream>
#include <string>
#include <cstring>

std::string& tmp_name(void) {

	static std::string name;
	static int sequence = 0;

	++sequence;

	name = "tmp";
	name += static_cast<char>(sequence + '0');

	return name;
}

int main(void)
{
	std::string name1 = tmp_name();
	std::string name2 = tmp_name();

	std::cout << "Name: " << name1 << '\n';
	std::cout << "Name: " << name2 << '\n';
	return 0;
}
