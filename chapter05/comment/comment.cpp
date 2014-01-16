#include <iostream>

int height;
int width;
int area;

int main(void)
{
	std::cout << "Enter width height? ";
	std::cin >> width >> height;
	area = (width * height) / 2;
	std::cout << "The area is " << area << '\n';
	return 0;
}
