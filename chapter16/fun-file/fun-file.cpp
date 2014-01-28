#include <cstdio>
#include <cstdlib>
#include <string.h>

int main(void)
{
	char name[100];
	std::FILE *in_file;

	std::printf("Name? ");
	std::fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	in_file = std::fopen(name, "r");
	if (in_file == NULL) {
		std::fprintf(stderr, "Error: Unable to open %s for input\n", name);
		exit(8);
	}
	std::printf("File found\n");
	std::fclose(in_file);
	return 0;
}
