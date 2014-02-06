/*************************************************
 * stack -- simple stack class
 *************************************************/

#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;

/*************************************************
 * bound_err -- handle out-of-range error
 *************************************************/
class bound_err {
	public:
		const std::string what;
		bound_err(const std::string& i_what): what(i_what) {}
		// bound_err& operator = -- default
		// bound_err(bound_err)  -- default copy constructor
		// ~bound_err()          -- default destructor
};

/*************************************************
 * stack class
 *
 * member function:
 *   stack -- initialize stack
 *   push  -- push data into stack
 *   pop   -- pop out data from stack
 *************************************************/
class stack {
	protected:
		int count;
		int data[STACK_SIZE];
	public:
		// initialize stack
		stack(): count(0) {};
		// ~stack(); -- use default destructor
		//              and use default copy constractor

		void push(const int item) throw(bound_err);

		int pop() throw(bound_err);
};

/*************************************************
 * stack::push -- push element into stack
 * arguments:
 *   item -- element for push
 *************************************************/
inline void stack::push(const int item) throw(bound_err) {
	if ((count < 0 ||
				(count >= static_cast<int>(sizeof(data)/sizeof(data[0]))))) {
		throw bound_err("Push overflows stack");
	}
	data[count] = item;
	++count;
}

/*************************************************
 * stack::pop -- pop out element from stack
 * return:
 *   top element of stack
 *************************************************/
inline int stack::pop() throw(bound_err) {
	--count;
	if ((count < 0 ||
				(count >= static_cast<int>(sizeof(data)/sizeof(data[0]))))) {
		throw bound_err("Push underflows stack");
	}

	return data[count];
}

static stack test_stack;

/*************************************************
 * push_a_lot -- push a lot of elements
 *************************************************/
static void push_a_lot() {
	int i;
	for (i = 0; i < 5000; ++i) {
		test_stack.push(i);
	}
}

int main(void)
{
	try {
		push_a_lot();
	}
	catch (bound_err& err) {
		std::cerr << "Error: Bounds exceeded\n";
		std::cerr << "Reason: " << err.what << '\n';
		exit (8);
	}
	catch (...) {
		std::cerr << "Error: Unexpected exception occured\n";
		exit (8);
	}
	return 0;
}
