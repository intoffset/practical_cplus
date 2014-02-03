class linked_list {
	public:
		class linked_list_element {
			public:
				std::string data;
			private:
				linked_list_element *next_ptr;
			friend class linked_list;
		};
	public:
		linked_list_element *first_ptr;
		linked_list() {
			first_ptr = NULL;
		}
		bool find(const std::string& data);
};
