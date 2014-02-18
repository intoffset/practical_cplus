/*************************************************
 * stat -- make statistic data for source code
 * usage:
 *   stat [options] <file-list>
 *************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <assert.h>

#include "ch_type.h"
#include "token.h"

/*************************************************
 * stat -- general statistics
 * member function:
 *   take_token -- calculate statistics
 *   line_start --output statistics at head of line
 *   eof -- output statistics at end of file
 *************************************************/
class a_stat {
	public:
		virtual void take_token(TOKEN_TYPE token) = 0;
		virtual void line_start() {};
		virtual void eof() {};
		// use default constructor
		// use default destructor
		// use default copy-constructor
};

/*************************************************
 * line_counter
 *   -- process line-number and line count
 *
 * count T_NEWLINE token
 * and output line-number at head of line
 *
 * output sum of line count at end of file
 *************************************************/
class line_counter : public a_stat {
	private:
		int cur_line; // current line
	public:
		line_counter() {
			cur_line = 0;
		}
		// use default destructor
		// use default copy-constructor

		// count newline
		void take_token(TOKEN_TYPE token) {
			if (token == T_NEWLINE) {
				++cur_line;
			}
		}

		// output current line number
		void line_start() {
			std::cout << std::setw(4) << cur_line << ' ' << std::setw(0);
		}

		// output sum of line count
		void eof() {
			std::cout << "Total number of lines: " << cur_line << '\n';
		}
};

/*************************************************
 * line_counter
 *   -- count () nest level
 *
 * count T_L_PAREN and T_R_PAREN token
 * and output nest level at head of line
 *
 * output max nest level at end of file
 *************************************************/
class paren_counter : public a_stat {
	private:
		int cur_level;
		int max_level;

	public:
		paren_counter() {
			cur_level = 0;
			max_level = 0;
		}
		// use default destructor
		// use default copy-constructor

		// count () nest level
		void take_token(TOKEN_TYPE token) {
			switch (token) {
				case T_L_PAREN:
					++cur_level;
					if (cur_level > max_level) {
						max_level = cur_level;
					}
					break;
				case T_R_PAREN:
					--cur_level;
					break;
				default:
					// none
					break;
			}
		}

		// output current nest level
		void line_start() {
			std::cout.setf(std::ios::left);
			std::cout.width(2);

			std::cout << '(' << cur_level << ' ';

			std::cout.unsetf(std::ios::left);
			std::cout.width();
		}

		// output max level at end of file
		void eof() {
			std::cout << "Maximum nesting of () : " << max_level << '\n';
		}
};

/*************************************************
 * brace_counter
 *   -- count {} nest level
 *
 * count T_L_CURLY and T_R_CURLY token
 * and output nest level at head of line
 *
 * output max nest level at end of file
 *************************************************/
class brace_counter : public a_stat {
	private:
		int cur_level;
		int max_level;

	public:
		brace_counter() {
			cur_level = 0;
			max_level = 0;
		}
		// use default destructor
		// use default copy-constructor

		// count {} nest level
		void take_token(TOKEN_TYPE token) {
			switch (token) {
				case T_L_CURLY:
					++cur_level;
					if (cur_level > max_level) {
						max_level = cur_level;
					}
					break;
				case T_R_CURLY:
					--cur_level;
					break;
				default:
					// none
					break;
			}
		}

		// output current nest level
		void line_start() {
			std::cout.setf(std::ios::left);
			std::cout.width(2);

			std::cout << '{' << cur_level << ' ';

			std::cout.unsetf(std::ios::left);
			std::cout.width();
		}

		// output max level at end of file
		void eof() {
			std::cout << "Maximum nesting of {} : " << max_level << '\n';
		}
};

/*************************************************
 * comment_counter
 *   -- count comment line
 *
 * output comment ratio at end of file
 *
 * *: this class use 2bit flag for statistics
 *   CF_COMMENT -- is comment
 *   CF_CODE    -- is code
 *************************************************/
static const int CF_COMMENT = (1<<0);
static const int CF_CODE    = (1<<1);
// 0                  -- [0] blank line
// CF_COMMENT         -- [1] line only comment
// CF_CODE            -- [2] line only code
// CF_COMMENT|CF_CODE -- [3] line with comment and code

class comment_counter : public a_stat {
	private:
		int counters[4];
		int flags;

	public:
		// initialize counter
		comment_counter() {
			memset(counters, '\0', sizeof(counters));
			flags = 0;
		}
		// use default destructor
		// use default copy-constructor

		// count comment
		void take_token(TOKEN_TYPE token) {
			switch (token) {
				case T_COMMENT:
					flags |= CF_COMMENT;
					break;
				default:
					flags |= CF_CODE;
					break;
				case T_NEWLINE:
					assert(flags >= 0);
					assert(flags < static_cast<int>(sizeof(counters)/sizeof(counters[0])));
					++counters[flags];
					flags = 0;
					break;
			}
		}

		// void line_start(void) -- default of base class

		// output statistics of comment
		void eof() {
			std::cout << "Number of blank lines .................. "
				<< counters[0] << '\n';
			std::cout << "Number of comment only lines ........... "
				<< counters[1] << '\n';
			std::cout << "Number of code only lines .............. "
				<< counters[2] << '\n';
			std::cout << "Number of lines with code and comment .. "
				<< counters[3] << '\n';
			std::cout.setf(std::ios::fixed);
			std::cout.precision(1);
			std::cout << "Comment to code ratio " <<
				float(counters[1] + counters[3]) /
				float(counters[2] + counters[3]) * 100.0 << "%\n";
		}
};

static line_counter    line_count;
static paren_counter   paren_count;
static brace_counter   brace_count;
static comment_counter comment_count;

static a_stat *stat_list[] = {
	&line_count,
	&paren_count,
	&brace_count,
	&comment_count,
	NULL
};

/*************************************************
 * do_file
 *   -- process one file
 *
 * arguments:
 *   name -- file name
 *************************************************/
static void do_file(const char *const name) {
	input_file in_file(name);
	token token;
	TOKEN_TYPE cur_token;
	class a_stat **cur_stat;

	if (in_file.bad()) {
		std::cerr << "Error: Could not open file " <<
			name << " for reading\n";
		return;
	}

	while (true) {
		cur_token = token.next_token(in_file);
		for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat) {
			(*cur_stat)->take_token(cur_token);
		}
#ifdef DEBUG
		assert(cur_token >= 0);
		assert(cur_token < static_cast<int>(sizeof(TOKEN_NAMES)/sizeof(TOKEN_NAMES[0])));
		std::cout << "  " << TOKEN_NAMES[cur_token] << '\n';
#endif /* #ifdef DEBUG */
		switch (cur_token) {
			case T_NEWLINE:
				for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat) {
					(*cur_stat)->line_start();
				}
				in_file.flush_line();
				break;
			case T_EOF:
				for (cur_stat = stat_list; *cur_stat != NULL; ++cur_stat) {
					(*cur_stat)->eof();
				}
				return;
			default:
				// none
				break;
		}
	}
}

int main(int argc, char *argv[])
{
	char *prog_name = argv[0];

	if (argc == 1) {
		std::cerr << "Usage is " << prog_name << "[options] <file-list>\n";
		exit(8);
	}

	for (/*argc set */; argc > 1; --argc) {
		do_file(argv[1]);
		++argv;
	}
	return 0;
}
