#include "integer.h"
#include "square.h"

template integer square<integer>(const integer);

template<typename T> T square(const T i) {
	return(i.value * i.value);
}

