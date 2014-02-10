#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "ia.h"

int& infinite_array::operator [] (const unsigned int index) {
	class infinite_array *current_ptr;
	unsigned int current_index;
	current_ptr = this;
	current_index = index;
	while (current_index >= BLOCK_SIZE) {
		if (current_ptr->next == NULL) {
			current_ptr->next  = new infinite_array;
			if (current_ptr->next == NULL) {
				std::cerr << "Error: Out of memory\n";
				exit(8);
			}
		}
		current_ptr = current_ptr->next;
		current_index -= BLOCK_SIZE;
	}
	assert(current_index >= 0);
	assert(current_index < static_cast<int>(sizeof(current_ptr->data)/sizeof(current_ptr->data[0])));
	return (current_ptr->data[current_index]);
}

infinite_array::~infinite_array() {
	if (next != NULL) {
		delete next;
		next = NULL;
	}
}
