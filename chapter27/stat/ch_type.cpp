/*************************************************
 * char_type -- character type class
 * member function
 *   type -- return (simple) character type
 *   is(ch, char_type) -- check character match char_type
 *************************************************/
#include <iostream>
#include <assert.h>
#include <cstdio>

#include "ch_type.h"

char_type::CHAR_TYPE char_type::type_info[256];

/*************************************************
 * fill_range -- fill character type
 * arguments
 *   start, end -- range
 *   type -- character type
 *************************************************/
void char_type::fill_range(int start, int end, CHAR_TYPE type) {
	int cur_ch;
	for (cur_ch = start; cur_ch <= end; ++cur_ch) {
		assert(cur_ch >= 0);
		assert(cur_ch < static_cast<int>(sizeof(type_info)/sizeof(type_info[0])));
		type_info[cur_ch] = type;
	}
}

/*************************************************
 * char_type::char_type
 *   -- initialize (simple) type_info table
 *************************************************/
char_type::char_type() {
	fill_range(0, 255, C_WHITE);

	fill_range('A', 'Z', C_ALPHA);
	fill_range('a', 'z', C_ALPHA);
	type_info['_'] = C_ALPHA;

	fill_range('0', '9', C_DIGIT);

	type_info['!'] = C_OPERATOR;
	type_info['#'] = C_OPERATOR;
	type_info['$'] = C_OPERATOR;
	type_info['%'] = C_OPERATOR;
	type_info['^'] = C_OPERATOR;
	type_info['&'] = C_OPERATOR;
	type_info['*'] = C_OPERATOR;
	type_info['-'] = C_OPERATOR;
	type_info['+'] = C_OPERATOR;
	type_info['='] = C_OPERATOR;
	type_info['|'] = C_OPERATOR;
	type_info['~'] = C_OPERATOR;
	type_info[','] = C_OPERATOR;
	type_info[':'] = C_OPERATOR;
	type_info['?'] = C_OPERATOR;
	type_info['.'] = C_OPERATOR;
	type_info['<'] = C_OPERATOR;
	type_info['>'] = C_OPERATOR;

	type_info['/'] = C_SLASH;
	type_info['\n'] = C_NEWLINE;

	type_info['('] = C_L_PAREN;
	type_info[')'] = C_R_PAREN;

	type_info['{'] = C_L_CURLY;
	type_info['}'] = C_R_CURLY;

	type_info['"'] = C_DOUBLE;
	type_info['\''] = C_SINGLE;
}

int char_type::is(int ch, CHAR_TYPE kind) {
	if (ch == EOF) {
		return (kind == C_EOF);
	}

	switch (kind) {
		case C_HEX_DIGIT:
			assert(ch >= 0);
			assert(ch < static_cast<int>(sizeof(type_info)/sizeof(type_info[0])));
			if (type_info[ch] == C_DIGIT) {
				return 1;
			}
			if ((ch >= 'A') && (ch <= 'F')) {
				return 1;
			}
			if ((ch >= 'a') && (ch <= 'f')) {
				return 1;
			}
			return 0;

		case C_ALPHA_NUMERIC:
			assert(ch >= 0);
			assert(ch < static_cast<int>(sizeof(type_info)/sizeof(type_info[0])));
			return ((type_info[ch] == C_ALPHA) ||
					(type_info[ch] == C_DIGIT));

		default:
			assert(ch >= 0);
			assert(ch < static_cast<int>(sizeof(type_info)/sizeof(type_info[0])));
			return (type_info[ch] == kind);
	}
}

char_type::CHAR_TYPE char_type::type(int ch) {
	if (ch == EOF) {
		return C_EOF;
	}

	assert(ch >= 0);
	assert(ch < static_cast<int>(sizeof(type_info)/sizeof(type_info[0])));

	return (type_info[ch]);
}
