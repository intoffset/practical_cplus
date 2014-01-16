#include <iostream>

int  result;
char oper_char;
int  value;

int main(void)
{
	result = 0;

	while (true) {
		std::cout << "Result: " << result << '\n';

		std::cout << "Enter operator and number: ";
		std::cin >> oper_char >> value;

		if ((oper_char == 'q') || (oper_char == 'Q')) {
			break;
		}

		if (oper_char == '+') {
			result += value;
		} else if (oper_char == '-') {
			result -= value;
		} else if (oper_char == '*') {
			result *= value;
		} else if (oper_char == '/') {
			if (value == 0) {
				std::cout << "Error: Divide by zero\n";
				std::cout << "  operation ignored\n";
			} else {
				result /= value;
			}
		} else {
			std::cout << "Unknown operator " << oper_char << '\n';
		}
	}
	return 0;
}
