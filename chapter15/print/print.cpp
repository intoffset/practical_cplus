#include <iostream>
#include <cstdlib>

int verbose = 0;
const char *out_file = "print.out";
char *program_name;
int line_max = 66;

void do_file(const char* const name) {
	std::cout << "Verbose " << verbose << " Lines " << line_max <<
		" Input " << name << " Output " << out_file << '\n';
}

void usage(void) {
	std::cerr << "Usage is " << program_name <<
		"[options] [file-list]\n";
	std::cerr << "Options\n";
	std::cerr << "-v         Verbose\n";
	std::cerr << "-l<number> Number of lines\n";
	std::cerr << "-o<name>   Set output filename\n";
	exit(8);
}

int main(int argc, char* argv[])
{
	program_name = argv[0];

	while ((argc > 1) && (argv[1][0] =='-')) {
		switch (argv[1][1]) {
			case 'v':
				verbose = 1;
				break;
			case 'o':
				out_file = &argv[1][2];
				break;
			case 'l':
				line_max = atoi(&argv[1][2]);
				break;
			default:
				std::cerr << "Bad option " << argv[1] << '\n';
				usage();
		}
		++argv;
		--argc;
	}

	if (argc == 1) {
		do_file("print.in");
	} else {
		while (argc > 1) {
			do_file(argv[1]);
			++argv;
			--argc;
		}
	}
	return 0;
}
