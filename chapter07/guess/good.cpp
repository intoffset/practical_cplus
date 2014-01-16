/****************************************
 * guess -- simple guess game
 * usage: guess
 ****************************************/

#include <iostream>
#include <cstdlib>

int number_to_guess;
int low_limit;
int high_limit;
int guess_count;
int player_number;

int main(void)
{
	while (true) {
		number_to_guess = rand() % 100 + 1;

		low_limit   = 0;
		high_limit  = 100;
		guess_count = 0;

		while (true) {
			std::cout << "Bounds " << low_limit << " - " << high_limit << '\n';
			std::cout << "Value[" << guess_count << "]? ";

			++guess_count;

			std::cin >> player_number;

			if (player_number == number_to_guess) {
				break;
			}

			if (player_number < number_to_guess) {
				low_limit = player_number;
			} else {
				high_limit = player_number;
			}
		}
		std::cout << "Bingo\n";
	}
	return 0;
}
