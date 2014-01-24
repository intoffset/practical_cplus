#include <assert.h>
#include <cstdlib>
#include <iostream>

const int STACK_SIZE = 100;

struct stack {
	int count;
	int data[STACK_SIZE];
};

inline void stack_init(struct stack& the_stack) {
	the_stack.count = 0;
}

inline void stack_push(struct stack& the_stack, const int item) {
	assert((the_stack.count >= 0) &&
			(the_stack.count <
			 static_cast<int>(sizeof(the_stack.data)/sizeof(the_stack.data[0]))));

	the_stack.data[the_stack.count] = item;

	++the_stack.count;
}

inline int stack_pop(struct stack& the_stack) {
	--the_stack.count;
	assert((the_stack.count >= 0) &&
			(the_stack.count <
			 static_cast<int>(sizeof(the_stack.data)/sizeof(the_stack.data[0]))));

	return the_stack.data[the_stack.count];
}

int main(void)
{
	struct stack a_stack;

	stack_init(a_stack);

	stack_push(a_stack, 1);
	stack_push(a_stack, 2);
	stack_push(a_stack, 3);

	std::cout << "Expect a 3 -> " << stack_pop(a_stack) << '\n';
	std::cout << "Expect a 2 -> " << stack_pop(a_stack) << '\n';
	std::cout << "Expect a 1 -> " << stack_pop(a_stack) << '\n';
	return 0;
}

