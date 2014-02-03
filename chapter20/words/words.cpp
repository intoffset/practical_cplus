/*************************************************
 * words -- scan file and print in ASCII-order
 *
 * usage
 *   words <file>
 *************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>

class tree {
	private:
		// basic node of tree
		class node {
			private:
				node *right;
				node *left;
			public:
				std::string word;

			friend class tree;
		};

		// root of tree
		node *root;

		// insert node in tree or sub-tree
		void enter_one(node *&node, const std::string& word);

		// print one of node
		void print_one(node *top);

	public:
		tree() {
			root = NULL;
		}

		// insert word in tree
		void enter(std::string& word) {
			enter_one(root, word);
		}

		// print tree
		void print() {
			print_one(root);
		}
};


static tree words;

/*************************************************
 * scan -- scan words in file
 *
 * arguments
 *   name -- file name
 *************************************************/
void scan(const char *const name) {
	std::string new_word;
	int ch;
	std::ifstream in_file;

	in_file.open(name, std::ios::in);
	if (in_file.bad()) {
		std::cerr << "Error: unable to open " << name << '\n';
		exit(8);
	}

	while (true) {
		while (true) {
			ch = in_file.get();
			if (std::isalpha(ch) || (ch == EOF)) {
				break;
			}
		}

		if (ch == EOF) {
			break;
		}

		new_word = ch;

		while (true) {
			ch = in_file.get();
			if (!std::isalpha(ch)) {
				break;
			}
			new_word += ch;
		}
		words.enter(new_word);
	}
}

int main(int argc, char const* argv[])
{
	if (argc != 2) {
		std::cerr << "Error: wrong number of parameters\n";
		std::cerr << "  on the command line\n";
		std::cerr << "Usage: words 'file'\n";
	}
	scan(argv[1]);
	words.print();
	return 0;
}

/*************************************************
 * tree::enter_one -- insert one word in tree
 *
 * arguments
 *   new_node -- current node
 *   word -- insert word
 *************************************************/
void tree::enter_one(node *&new_node, const std::string& word) {
	if (new_node == NULL) {
		new_node = new node;

		new_node->left  = NULL;
		new_node->right = NULL;
		new_node->word  = word;
	}

	if (new_node->word == word) {
		return;
	}

	if (new_node->word < word) {
		enter_one(new_node->right, word);
	} else {
		enter_one(new_node->left, word);
	}
}

/*************************************************
 * tree::print_one -- print one word in tree
 *
 * arguments
 *   top -- current node
 *************************************************/
void tree::print_one(node *top) {
	if (top == NULL) {
		return;
	}

	print_one(top->left);
	std::cout << top->word << '\n';
	print_one(top->right);
}
