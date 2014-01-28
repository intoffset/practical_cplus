#include <iostream>
#include <fstream>
#include <cstdlib>

int main(void)
{
	int cur_char;
	std::ofstream out_file;

	out_file.open("test.out", std::ios::out|std::ios::binary);

	if (out_file.bad()) {
		std::cerr << "Can not open output file\n";
		exit(8);
	}
	for (cur_char = 0; cur_char < 128; cur_char++) {
		out_file.put(cur_char);
	}
	return 0;
}
