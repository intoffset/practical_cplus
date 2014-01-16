#include <iostream>
#include <string>

std::string first_name;
std::string last_name;
std::string full_name;

std::string main_string;
std::string sub_string;

int main(void)
{
	first_name = "Steve";
	last_name  = "Oualline";
	full_name  = first_name + " " + last_name;
	std::cout << "Full name is " << full_name << "\n";

	std::cout << "Full name is " << full_name.length() << " long\n";

	std::cout << "first character of first name is " << first_name.at(0) << "\n";
	std::cout << "first character of last name is " << last_name.at(0) << "\n";

	main_string = "This is a test";
	sub_string  = main_string.substr(5,6);
	std::cout << "substitute string is \"" << sub_string << "\"\n";
	return 0;
}
