#include <iostream>
#include <string>
#include "linked.h"

/************************************************
 * find -- search data in linked_list
 *
 * arguments
 *   data -- search data
 *
 * return
 *   true  -- data found
 *   false -- data not found
 ************************************************/
bool linked_list::find(const std::string& data) {
	linked_list_element *current_ptr;
	current_ptr = first_ptr;
	while (current_ptr != NULL) {
		if (current_ptr->data == data) {
			break;
		}
		current_ptr = current_ptr->next_ptr;
	}
	return (current_ptr != NULL);
}
