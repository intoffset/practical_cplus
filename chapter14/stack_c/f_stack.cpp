class stack {
	private:
		int count;
		int data[STACK_SIZE];
	public:
		void init();
		void push(const int item);
		int pop();

		friend int stack_equal(const stack& s1, const stack& s2);
};
