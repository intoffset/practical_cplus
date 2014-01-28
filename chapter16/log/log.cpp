#include <iostream>
#include <string>
#include <fstream>

void log_message(const std::string& msg) {
	std::ofstream out_file("data.log",
			std::ios::out|std::ios::app|std::ios::ate);
	if (out_file.fail()) {
		return;
	}
	out_file << msg << std::endl;
}
