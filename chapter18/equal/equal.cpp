#include <iostream>

class trouble {
	public:
		int data;
		trouble();
		trouble(const trouble& old);
		trouble& operator = (const trouble& old_trouble);
};
trouble::trouble() {
	data = 0;
}
trouble::trouble(const trouble& old) {
	std::cout << "Copy constructor called\n";
	*this = old;
}
trouble& trouble::operator = (const trouble& old_trouble) {
	std::cout << "Operator = called\n";
	data = old_trouble.data;
	return *this;
}

int main(void)
{
	trouble trouble1;
	trouble trouble2(trouble1);
	return 0;
}
