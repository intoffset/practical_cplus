#include <iostream>
#include <assert.h>

int main(void)
{
	float triangle(float width, float height);

	std::cout << "Triangle #1 " << triangle(1.3, 8.3) << '\n';
	std::cout << "Triangle #2 " << triangle(4.8, 9.8) << '\n';
	std::cout << "Triangle #3 " << triangle(1.2, 2.0) << '\n';
	return 0;
}

/***************************************
 * calc triangle area
 * arguments
 *   width -- base width of triangle
 *   height -- height of triangle
 * return
 *   area of triangle
 **************************************/
float triangle(float width, float height) {
	float area;

	assert(width >= 0.0);
	assert(height >= 0.0);

	area = width * height / 2.0;

	return area;
}

