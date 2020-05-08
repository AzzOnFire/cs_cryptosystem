#pragma once

#include "defines.hpp"

/**
 * This code compiles only in c ++ 11 and higher
 * use flag g++ -std=c++17 or g++ -std=c++14
 */

constexpr uint64_t Polynom(size_t n)
{
	switch (n)
	{
	case 64:
		return 0x1B;
	case 128:
		return 0x87;
	case 256:
		return 0x425;
	case 512:
		return 0x125;
	}

	return 0;
}

/**
* Multiplies Galois field elements
* Available field sizes: 2^64, 2^128, 2^256, 2^512
*
* @param a Binary vectors representing first factor, used to save the result
* @param b Binary vectors representing second factor
*
*/
template <size_t n>
byte* multiplication(byte* a, const byte* b) {
	constexpr uint64_t poly = Polynom(n);
	constexpr int length = bits_to_qword(n);

	uint64_t* result = (uint64_t*)a;
	const uint64_t* num2 = (uint64_t*)b;

	uint64_t num1[length];
	
	for (size_t i = 0; i < length; ++i) {
		num1[i] = result[i];
		result[i] = 0;
	}
	
	for (int i = length - 1; i >= 0; --i) {
		for (uint64_t bit = 0x8000000000000000; bit > 0; bit >>= 1) {
			if (result[length - 1] & 0x8000000000000000) {
				for (size_t j = length - 1; j > 0; --j) {
					result[j] <<= 1;
					if (result[j - 1] & 0x8000000000000000)
						result[j] |= 1;
				}
				result[0] <<= 1;
				result[0] ^= poly;
			}
			else {
				for (int j = length - 1; j > 0; --j) {
					result[j] <<= 1;
					if (result[j - 1] & 0x8000000000000000)
						result[j] |= 1;
				}
				result[0] <<= 1;
			}

			if (bit & num2[i])
				for (int j = 0; j < length; ++j)
					result[j] ^= num1[j];
		}
	}

	return (byte*)result;
}
