/*************************************************
 * stack -- simple stack class
 *************************************************/

#include <cstdlib>
#include <iostream>
#include <assert.h>

const int STACK_SIZE = 100;

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
		stack();
		// ~stack(); -- use default destructor
		//              and use default copy constractor

		void push(const int item);

		int pop();
};

/*************************************************
 * stack::stack -- initialize stack
 *************************************************/
inline stack::stack() {
	count = 0;
}

/*************************************************
 * stack::push -- push element into stack
 * arguments:
 *   item -- element
 *************************************************/
inline void stack::push(const int item) {
	assert((count >= 0 &&
				(count < static_cast<int>(sizeof(data)/sizeof(data[0])))));

	data[count] = item;
	++count;
}

/*************************************************
 * stack::pop -- pop out element from stack
 * return:
 *   top element of stack
 *************************************************/
inline int stack::pop() {
	--count;
	assert((count >= 0 &&
				(count < static_cast<int>(sizeof(data)/sizeof(data[0])))));

	return data[count];
}

/*************************************************
 * m_stack class -- extended stack
 *
 * member function:
 *   push_three -- push three element into stack
 *************************************************/
class m_stack : public stack {
	public:
		// initialize stack
		// stack();  -- use default constructor
		// ~stack(); -- use default destructor
		//              and use default copy constractor

		// push elements into stack
		void push_three(const int item1,
				const int item2,
				const int item3);

		// sum elements
		int sum();
};

/*************************************************
 * m_stack::push_three -- push three element into stack
 * arguments:
 *   item1, item2, item3 -- pushed element
 *************************************************/
inline void m_stack::push_three(const int item1,
				const int item2, const int item3) {
	stack::push(item1);
	stack::push(item2);
	stack::push(item3);
}

/*************************************************
 * m_stack::sum -- sum elements
 * return:
 *   sum of elements in stack
 *************************************************/
inline int m_stack::sum() {
	int index;
	int total = 0;

	for (index = 0; index < count; ++index) {
		assert((index >= 0 &&
					(index < static_cast<int>(sizeof(data)/sizeof(data[0])))));
		total += data[index];
		
	}

	return total;
}
