#include <iostream>
#include <cstdlib>

class list {
	private:
		int item;

	public:
		virtual void clear() = 0;

		void next_item() {
			++item;
		}

		list() {
			item = 0;
		}

		virtual ~list() {
			clear();
		}
};

class list_of_integers : public list {
	public:
		int array[100];

		void clear() {
			int i;
			for (i = 0; i < 100; ++i) {
				array[i] = 0;
			}
		}
};

int main(void)
{
	list_of_integers *list_ptr = new list_of_integers;

	delete list_ptr;
	list_ptr = NULL;

	return 0;
}
