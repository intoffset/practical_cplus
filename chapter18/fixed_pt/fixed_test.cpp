#include <iostream>
#include "fixed_pt.h"

int main(void)
{
	std::cout << "Expect 1.23 " << fixed_pt::fixed_pt(1.23) << std::endl;
	std::cout << "Expect 1.00 " << fixed_pt::fixed_pt(1.00) << std::endl;
	std::cout << "Expect 1.02 " << fixed_pt::fixed_pt(1.02) << std::endl;
	std::cout << "Expect 1.20 " << fixed_pt::fixed_pt(1.20) << std::endl;

	fixed_pt::fixed_pt f3 = 1.23;
	std::cout << "Expect 1.23 " << f3 << std::endl;

	fixed_pt::fixed_pt f1(1.23 + 0.005);
	fixed_pt::fixed_pt f2(4.56 + 0.005);

	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;


	return 0;
}
