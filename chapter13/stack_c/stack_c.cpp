#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;

class stack {
	private:
		int count;
		int data[STACK_SIZE];
	public:
		void init();
		void push(const int item);
		int pop();
};

inline void stack::init() {
	count = 0;
}

inline void stack::push(const int item) {
	assert((count >= 0) &&
			(count < static_cast<int>(sizeof(data)/sizeof(data[0]))));
	data[count] = item;
	++count;
}

inline int stack::pop() {
	--count;
	assert((count >= 0) &&
			(count < static_cast<int>(sizeof(data)/sizeof(data[0]))));
	return data[count];
}

int main(void)
{
	stack a_stack;

	a_stack.init();

	a_stack.push(1);
	a_stack.push(2);
	a_stack.push(3);

	std::cout << "Expect a 3 -> " << a_stack.pop() << '\n';
	std::cout << "Expect a 2 -> " << a_stack.pop() << '\n';
	std::cout << "Expect a 1 -> " << a_stack.pop() << '\n';
	return 0;
}

