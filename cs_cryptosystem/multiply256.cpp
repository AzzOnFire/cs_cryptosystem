
#include "multiply256.h"

char* multiply256(char* arg1, char* arg2)
{
	unsigned long long* result = new unsigned long long[4];
	unsigned long long* num1 = (unsigned long long*)arg1;
	unsigned long long* num2 = (unsigned long long*)arg2;

	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;

	unsigned long long bit = 0x8000000000000000;
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
			result[0] ^= 0x425; //������������ GF(2^256)

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
			result[0] ^= 0x425; //������������ GF(2^256)

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
			result[0] ^= 0x425; //������������ GF(2^256)

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
			result[0] ^= 0x425; //������������ GF(2^256)

		if (bit & num2[0])
		{
			result[0] ^= num1[0];
			result[1] ^= num1[1];
			result[2] ^= num1[2];
			result[3] ^= num1[3];
		}
	}

	return (char*)result;
}