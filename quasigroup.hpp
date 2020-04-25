#pragma once
#include "stdafx.h"
#include "defines.hpp"

/**
* Квазигрупповая операция V8 x V8 --> V8. Принимает два байта и производит операцию * между ними в поле 2^8.
* 
* @param first однобайтовый элемент из поля 2^8
* @param second однобайтовый элемент из поля 2^8
*
* @return result результат квазигрупповой операции
*/
template <size_t n>
inline byte QuazigroupOperation(byte first, byte second)
{
	//в идеале сделать проверку размеров(throw exception)
	uint16_t firstConverted = (uint16_t)first;
	uint16_t secondConverted = (uint16_t)second;

	//!!! Nado dobavit coeff + multiplication / addition field or integer?
	byte result = (byte)((firstConverted + secondConverted + 2 * firstConverted * secondConverted) % 256);

	return result;
}

/**
* Байтовый метод x*y над элементами поля 2^n.
* Суть в том, что 2^n разбивается на блоки по байтам и выполяются квазигрупповые операции над ними.
*
* @param first элемент из поля 2^n
* @param second элемент из поля 2^n
*
* @return result результат квазигрупповой операции
*/
template <size_t n>
inline byte* ByteMethod(byte* first, byte* second)
{
	for (size_t i = 0; i < bits_to_bytes(n); ++i) 
	{
		first[i] = QuazigroupOperation(first[i], second[i]);
	}

	return first;
}