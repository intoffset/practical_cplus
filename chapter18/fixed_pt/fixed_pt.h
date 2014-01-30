#ifndef __fixed_pt_h__
#define __fixed_pt_h__

#include <iostream>
#include <assert.h>
#include <stdlib.h>

namespace fixed_pt {

	const int fixed_exp = 100;

	const double fixed_fudge_factor = 0.0001;

	class fixed_pt {

		private:
			long int value;

			static long int double_to_fp(const double the_double) {
				return (
						static_cast<long int>(
							the_double * static_cast<double>(fixed_exp) +
							fixed_fudge_factor
							)
					   );
			}

		public:
			// constructors and destructor
			fixed_pt() : value(0) {}

			fixed_pt(const fixed_pt& other_fixed_pt) :
				value(other_fixed_pt.value) {}

			fixed_pt(const double init_real) :
				value(double_to_fp(init_real)) {}

			~fixed_pt() {}

			// set value
			void set(const double real) {
				value = double_to_fp(real);
			}

			// get value
			double get() {
				return static_cast<double>(value) / fixed_exp;
			}

			// operators
			fixed_pt operator = (const fixed_pt& oper2) {
				value = oper2.value;
				return *this;
			}

			fixed_pt operator += (const fixed_pt& oper2) {
				value += oper2.value;
				return *this;
			}

			fixed_pt operator += (double oper2) {
				value += double_to_fp(oper2);
				return *this;
			}


			fixed_pt operator -= (const fixed_pt& oper2) {
				value -= oper2.value;
				return *this;
			}

			fixed_pt operator -= (double oper2) {
				value -= double_to_fp(oper2);
				return *this;
			}

			fixed_pt operator *= (const fixed_pt& oper2) {
				value *= oper2.value;
				value /= fixed_exp;
				return *this;
			}

			fixed_pt operator *= (double oper2) {
				value *= double_to_fp(oper2);
				value /= fixed_exp;
				return *this;
			}

			fixed_pt operator /= (const fixed_pt& oper2) {
				assert(oper2.value != 0);
				value /= oper2.value;
				value *= fixed_exp;
				return *this;
			}

			fixed_pt operator /= (double oper2) {
				assert(double_to_fp(oper2) != 0.0);
				value /= double_to_fp(oper2);
				value *= fixed_exp;
				return *this;
			}

			// f++
			fixed_pt operator ++(int) {
				fixed_pt result(*this);
				value += fixed_exp;
				return result;
			}

			// ++f
			fixed_pt operator ++() {
				value += fixed_exp;
				return *this;
			}

			// f--
			fixed_pt operator --(int) {
				fixed_pt result(*this);
				value -= fixed_exp;
				return result;
			}

			// --f
			fixed_pt operator --() {
				value -= fixed_exp;
				return *this;
			}

		private:
			// used for internal convesion in friend method
			fixed_pt(const long int i_value) : value(i_value) {}

			friend fixed_pt operator + (const fixed_pt& oper1, const fixed_pt& oper2);
			friend fixed_pt operator + (const fixed_pt& oper1, const double    oper2);
			friend fixed_pt operator + (const double    oper1, const fixed_pt& oper2);

			friend fixed_pt operator - (const fixed_pt& oper1, const fixed_pt& oper2);
			friend fixed_pt operator - (const fixed_pt& oper1, const double    oper2);
			friend fixed_pt operator - (const double    oper1, const fixed_pt& oper2);

			friend fixed_pt operator * (const fixed_pt& oper1, const fixed_pt& oper2);
			friend fixed_pt operator * (const fixed_pt& oper1, const double    oper2);
			friend fixed_pt operator * (const double    oper1, const fixed_pt& oper2);

			friend fixed_pt operator / (const fixed_pt& oper1, const fixed_pt& oper2);
			friend fixed_pt operator / (const fixed_pt& oper1, const double    oper2);
			friend fixed_pt operator / (const double    oper1, const fixed_pt& oper2);

			friend bool operator == (const fixed_pt& oper1, const fixed_pt& oper2);
			friend bool operator != (const fixed_pt& oper1, const fixed_pt& oper2);

			friend fixed_pt operator + (const fixed_pt& oper1);
			friend fixed_pt operator - (const fixed_pt& oper1);

			friend std::ostream& operator << (std::ostream& out_file, const fixed_pt& number);
			friend std::istream& operator >> (std::istream& in_file,  fixed_pt& number);

	};

	inline fixed_pt operator + (const fixed_pt& oper1, const fixed_pt& oper2) {
		return fixed_pt(oper1.value + oper2.value);
	}
	inline fixed_pt operator + (const fixed_pt& oper1, const double oper2) {
		return fixed_pt(oper1.value + fixed_pt::double_to_fp(oper2));
	}
	inline fixed_pt operator + (const double oper1, const fixed_pt& oper2) {
		return fixed_pt(fixed_pt::double_to_fp(oper1) + oper2.value);
	}

	inline fixed_pt operator - (const fixed_pt& oper1, const fixed_pt& oper2) {
		return fixed_pt(oper1.value - oper2.value);
	}
	inline fixed_pt operator - (const fixed_pt& oper1, const double oper2) {
		return fixed_pt(oper1.value - fixed_pt::double_to_fp(oper2));
	}
	inline fixed_pt operator - (const double oper1, const fixed_pt& oper2) {
		return fixed_pt(fixed_pt::double_to_fp(oper1) - oper2.value);
	}

	inline fixed_pt operator * (const fixed_pt& oper1, const fixed_pt& oper2) {
		return fixed_pt(oper1.value * oper2.value / fixed_exp);
	}
	inline fixed_pt operator * (const fixed_pt& oper1, const double oper2) {
		return fixed_pt((oper1.value * fixed_pt::double_to_fp(oper2)) / fixed_exp);
	}
	inline fixed_pt operator * (const double oper1, const fixed_pt& oper2) {
		return fixed_pt(fixed_pt::double_to_fp(oper1) * oper2.value / fixed_exp);
	}

	inline fixed_pt operator / (const fixed_pt& oper1, const fixed_pt& oper2) {
		assert(oper2.value != 0);
		return fixed_pt((oper1.value * fixed_exp) / oper2.value);
	}
	inline fixed_pt operator / (const fixed_pt& oper1, const double oper2) {
		assert(oper2 != 0);
		return fixed_pt((oper1.value * fixed_exp) / fixed_pt::double_to_fp(oper2));
	}
	inline fixed_pt operator / (const double oper1, const fixed_pt& oper2) {
		assert(oper2.value != 0);
		return fixed_pt((fixed_pt::double_to_fp(oper1) * fixed_exp) / oper2.value);
	}

	inline bool operator == (const fixed_pt& oper1, const fixed_pt& oper2) {
		return (oper1.value == oper2.value);
	}
	inline bool operator != (const fixed_pt& oper1, const fixed_pt& oper2) {
		return !(oper1.value == oper2.value);
	}

	inline fixed_pt operator + (const fixed_pt& oper1) {
		return fixed_pt(oper1);
	}
	inline fixed_pt operator - (const fixed_pt& oper1) {
		return fixed_pt(-oper1.value);
	}

	inline std::ostream& operator << (std::ostream& out_file, const fixed_pt& number) {
		long int before_dp = number.value / fixed_exp;
		long int after_dp1 = abs(number.value % fixed_exp);
		long int after_dp2 = after_dp1 % 10;
		after_dp1 /= 10;
		out_file << before_dp << '.' << after_dp1 << after_dp2;
		return out_file;
	}

	extern std::istream& operator >> (std::istream& in_file, fixed_pt& number);

} /* namespace fixed_pt */


#endif
