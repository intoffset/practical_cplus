#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

/*************************************************
 * token -- token module
 * function
 *   next_token -- read next token from input
 *************************************************/

/* token list */
#define TOKEN_LIST \
	T(T_NUMBER),   \
	T(T_STRING),   \
	T(T_COMMENT),  \
	T(T_NEWLINE),  \
	T(T_OPERATOR), \
	T(T_L_PAREN),  \
	T(T_R_PAREN),  \
	T(T_L_CURLY),  \
	T(T_R_CURLY),  \
	T(T_ID),       \
	T(T_EOF)

/* token enum list */
#define T(x) x
enum TOKEN_TYPE {
	TOKEN_LIST
};
#undef T // delete temporary macro

extern const char *const TOKEN_NAMES[];

/*************************************************
* input_file -- data from input
*
* store 2 character in cur_char and next_char
*
* member function
*   read_char -- move to next character
*************************************************/

class input_file : public std::ifstream {
	private:
		std::string line;

	public:
		int cur_char;
		int next_char;

		input_file(const char *const name) : std::ifstream(name), line("")
		{
			if (bad()) {
				return;
			}
			cur_char = get();
			next_char = get();
		}

		/* output line for screen */
		void flush_line() {
			std::cout << line;
			std::cout.flush();
			line = "";
		}

		/* move to next character */
		void read_char() {
			line += cur_char;

			cur_char = next_char;
			next_char = get();
		}
};

/*************************************************
 * token class
 *   -- read next token and return type
 *************************************************/
class token {
	private:
		// comment flag (true -> comment)
		int in_comment;

		// need to read one character flag
		int need_to_read_one;

		TOKEN_TYPE read_comment(input_file& in_file);

	public:
		token() {
			in_comment = false;
			need_to_read_one = 0;
		}

		TOKEN_TYPE next_token(input_file& in_file);
};
