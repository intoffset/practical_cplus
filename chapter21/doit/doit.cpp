class simple {
	public:
		int do_it(int i, int j) {
			return i*j;
		}
		float do_it(float f) {
			return f*2;
		}
};

class derived : public simple {
	public:
		int do_it(int i, int j) {
			return i+j;
		}
};
