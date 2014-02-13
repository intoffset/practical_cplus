#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;

/*************************************************
 * stack class
 *
 * member function
 *   init
 *   push
 *   pop
 *************************************************/

 template<typename kind> class stack {
	 private:
		 int count;
		 kind data[STACK_SIZE];
	 public:
		 stack() {
			 count = 0;
		 }
		 void push(const kind item) {
			 assert(count >= 0);
			 assert(count < static_cast<int>(sizeof(data)/sizeof(data[0])));

			 data[count] = item;
			 ++count;
		 }

		 kind pop() {
			 --count;
			 assert(count >= 0);
			 assert(count < static_cast<int>(sizeof(data)/sizeof(data[0])));

			 return data[count];
		 }
 };

