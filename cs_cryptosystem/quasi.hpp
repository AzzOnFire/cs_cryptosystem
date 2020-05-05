#pragma once

#include "defines.hpp"

/*
JUST STUPID XOR
*/
template<size_t n>
byte* quasi(byte* first, const byte* second) {
	for (size_t i = 0; i < bits_to_bytes(n); ++i) {
		first[i] ^= second[i];
	}

	return first;
}
