#include <iostream>

class base_class {
	public:
		base_class() {
			std::cout << "base_class constructor called\n";
		}
		virtual ~base_class() {
			std::cout << "base_class destructor called\n";
		}
};

class derived_class : public base_class {
	public:
		derived_class() {
			std::cout << "derived_class constructor called\n";
		}
		~derived_class() {
			std::cout << "derived_class destructor called\n";
		}
};

int main(void)
{
	base_class *base_ptr = new derived_class;
	delete base_ptr;
	base_ptr = NULL;
	return 0;
}
