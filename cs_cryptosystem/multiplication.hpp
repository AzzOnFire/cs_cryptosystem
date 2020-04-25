#pragma once

#include "defines.hpp"

/**
 * This code compiles only in c ++ 11 and higher
 * use flag g++ -std=c++17 or g++ -std=c++14
 */

constexpr unsigned long long Polynom(size_t n)
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
* @param a Binary vectors representing first factor
* @param b Binary vectors representing second factor
*
* @return Binary vector representing composition of elements
*/
template <size_t n>
byte* multiplication(byte* a, byte* b)
{
	unsigned long long poly = Polynom(n);
	constexpr int lenght = n / 64;

	unsigned long long* result = new unsigned long long[lenght];
	unsigned long long* num1 = (unsigned long long*)a;
	unsigned long long* num2 = (unsigned long long*)b;
	
	for (int i = 0; i < lenght; ++i)
		result[i] = 0;

	for (int i = lenght - 1; i >= 0; --i)
	{
		for (unsigned long long bit = 0x8000000000000000; bit > 0; bit >>= 1)
		{
			if (result[lenght - 1] & 0x8000000000000000)
			{
				for (int j = lenght - 1; j > 0; --j)
				{
					result[j] <<= 1;
					if (result[j - 1] & 0x8000000000000000)
						result[j] |= 1;
				}
				result[0] <<= 1;
				result[0] ^= poly;
			}
			else
			{
				for (int j = lenght - 1; j > 0; --j)
				{
					result[j] <<= 1;
					if (result[j - 1] & 0x8000000000000000)
						result[j] |= 1;
				}
				result[0] <<= 1;
			}

			if (bit & num2[i])
				for (int j = 0; j < lenght; ++j)
					result[j] ^= num1[j];
		}
	}

	return (byte*)result;
}
