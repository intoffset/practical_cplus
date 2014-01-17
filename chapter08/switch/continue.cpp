#include <iostream>

int  result;
char oper_char;
int  value;

int main(void)
{
	result = 0;
	while (true) {
		std::cout << "Enter operator and number: ";

		std::cin >> oper_char >> value;

		if ((oper_char == 'q') || (oper_char == 'Q')) {
			break;
		}

		switch (oper_char) {
			case '+':
				result += value;
				break;
			case '-':
				result -= value;
				break;
			case '*':
				result *= value;
				break;
			case '/':
				if (value == 0) {
					std::cout << "Error: Divide by zero\n";
					std::cout << "  operation ignored\n";
				} else {
					result /= value;
				}
				break;
			case 'h':
			case 'H':
				std::cout << "Operator Meaning\n";
				std::cout << "-------- -------\n";
				std::cout << " +       Aadd\n";
				std::cout << " -       Substract\n";
				std::cout << " *       Multipy\n";
				std::cout << " /       Divide\n";
				continue;
			default:
				std::cout << "Unknown operator " << oper_char << '\n';
				continue;
		}
		std::cout << "Result: " << result << '\n';
	}
	return 0;
}
