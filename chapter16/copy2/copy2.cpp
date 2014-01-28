#include <iostream>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef __WIN32__
#include <io.h>
#else
#include <unistd.h>
#endif /* #ifdef __WIN32__ */

const int BUFFER_SIZE = (16 * 1024);
int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	int in_file;
	int out_file;
	int read_size;

	if (argc != 3) {
		std::cerr << "Error: Wrong number of arguments\n";
		std::cerr << "Usage is: copy <from> <to>\n";
		exit(8);
	}

	in_file = open(argv[1], O_RDONLY);
	if (in_file < 0) {
		std::cerr << "Error: Unable to open " << argv[1] << '\n';
	}
	out_file = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666);
	if (in_file < 0) {
		std::cerr << "Error: Unable to open " << argv[2] << '\n';
	}
	while (true) {
		read_size = read(in_file, buffer, sizeof(buffer));
		if (read_size == 0) {
			break;
		}
		if (read_size < 0) {
			std::cerr << "Error: Read error\n";
		}
		write(out_file, buffer, (unsigned int) read_size);
	}
	close(in_file);
	close(out_file);
	return 0;
}
