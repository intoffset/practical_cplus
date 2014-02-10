#include <cstring>

const unsigned int BLOCK_SIZE = 10;

class infinite_array {
	private:
		int data[BLOCK_SIZE];
		class infinite_array *next;

	public:
		infinite_array() {
			next = NULL;
			memset(data, '\0', sizeof(data));
		}
		~infinite_array();

		int& operator[] (const unsigned int index);
};
