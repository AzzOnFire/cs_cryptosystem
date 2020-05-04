#pragma once

typedef unsigned char byte;

#define bits_to_bytes(bits) bits/8
#define bits_to_word(bits)  bits/16
#define bits_to_dword(bits) bits/32
#define bits_to_qword(bits) bits/64


// Generative polynoms:
// GF(2^8)		x^8 + x^4 + x^3 + x^2 + 1
// GF(2^64)		x^64 + x^4 + x^3 + x + 1
// GF(2^128)	x^128 + x^7 + x^2 + x + 1
// GF(2^256)	x^256 + x^10 + x^5 + x^2 + 1
// GF(2^512)	x^512 + x^8 + x^5 + x^2 + 1