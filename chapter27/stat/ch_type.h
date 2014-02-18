/*************************************************
 * char_type -- character type class
 * member function
 *   type -- return (simple) character type
 *   is(ch, char_type) -- check character match char_type
 *************************************************/
class char_type {
	public:
		enum CHAR_TYPE {
			C_EOF,
			C_WHITE,
			C_NEWLINE,
			C_ALPHA,
			C_DIGIT,
			C_OPERATOR,
			C_SLASH,
			C_L_PAREN,
			C_R_PAREN,
			C_L_CURLY,
			C_R_CURLY,
			C_SINGLE,
			C_DOUBLE,

			C_HEX_DIGIT,
			C_ALPHA_NUMERIC
		};

	private:
		static enum CHAR_TYPE type_info[256];
		void fill_range(int start, int end, CHAR_TYPE type);

	public:
		char_type(); // initialize data
		// ~char_type(); -- use default destructor

		int is(int ch, CHAR_TYPE kind);

		CHAR_TYPE type(int ch);

};

