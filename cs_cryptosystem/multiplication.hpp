#pragma once

#include "defines.hpp"

// TODO: Сделать для других разрядностей
// Вся эта штука работает только для n = 256
/**
* Тот кто делает эту функцию, напиши здесь коммент (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* multiplication(byte* first, const byte* second) {
	uint64_t* result = new uint64_t[4];
	uint64_t* num1 = (uint64_t*)first;
	uint64_t* num2 = (uint64_t*)second;

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;

	uint64_t bit = 0x8000000000000000;
	for (int j = 0; j < 64; ++j, bit >>= 1)
	{
		bool overflow = false;
		if (result[3] & 0x8000000000000000)
			overflow = true;

		result[3] <<= 1;
		if (result[2] & 0x8000000000000000)
			result[3] |= 1;
		result[2] <<= 1;
		if (result[1] & 0x8000000000000000)
			result[2] |= 1;
		result[1] <<= 1;
		if (result[0] & 0x8000000000000000)
			result[1] |= 1;
		result[0] <<= 1;

		if (overflow)
			result[0] ^= 0x425; //неприводимый GF(2^256)

		if (bit & num2[3])
		{
			result[0] ^= num1[0];
			result[1] ^= num1[1];
			result[2] ^= num1[2];
			result[3] ^= num1[3];
		}
	}

	bit = 0x8000000000000000;
	for (int j = 0; j < 64; ++j, bit >>= 1)
	{
		bool overflow = false;
		if (result[3] & 0x8000000000000000)
			overflow = true;

		result[3] <<= 1;
		if (result[2] & 0x8000000000000000)
			result[3] |= 1;
		result[2] <<= 1;
		if (result[1] & 0x8000000000000000)
			result[2] |= 1;
		result[1] <<= 1;
		if (result[0] & 0x8000000000000000)
			result[1] |= 1;
		result[0] <<= 1;

		if (overflow)
			result[0] ^= 0x425; //неприводимый GF(2^256)

		if (bit & num2[2])
		{
			result[0] ^= num1[0];
			result[1] ^= num1[1];
			result[2] ^= num1[2];
			result[3] ^= num1[3];
		}
	}

	bit = 0x8000000000000000;
	for (int j = 0; j < 64; ++j, bit >>= 1)
	{
		bool overflow = false;
		if (result[3] & 0x8000000000000000)
			overflow = true;

		result[3] <<= 1;
		if (result[2] & 0x8000000000000000)
			result[3] |= 1;
		result[2] <<= 1;
		if (result[1] & 0x8000000000000000)
			result[2] |= 1;
		result[1] <<= 1;
		if (result[0] & 0x8000000000000000)
			result[1] |= 1;
		result[0] <<= 1;

		if (overflow)
			result[0] ^= 0x425; //неприводимый GF(2^256)

		if (bit & num2[1])
		{
			result[0] ^= num1[0];
			result[1] ^= num1[1];
			result[2] ^= num1[2];
			result[3] ^= num1[3];
		}
	}

	bit = 0x8000000000000000;
	for (int j = 0; j < 64; ++j, bit >>= 1)
	{
		bool overflow = false;
		if (result[3] & 0x8000000000000000)
			overflow = true;

		result[3] <<= 1;
		if (result[2] & 0x8000000000000000)
			result[3] |= 1;
		result[2] <<= 1;
		if (result[1] & 0x8000000000000000)
			result[2] |= 1;
		result[1] <<= 1;
		if (result[0] & 0x8000000000000000)
			result[1] |= 1;
		result[0] <<= 1;

		if (overflow)
			result[0] ^= 0x425; //неприводимый GF(2^256)

		if (bit & num2[0])
		{
			result[0] ^= num1[0];
			result[1] ^= num1[1];
			result[2] ^= num1[2];
			result[3] ^= num1[3];
		}
	}

	return (byte*)result;
}
