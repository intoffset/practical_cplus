class integer {
	public:
		int value;

		integer(int i_value): value(i_value) {};

		integer operator * (const integer i2) {
			integer result(value * i2.value);
			return result;
		}
};
