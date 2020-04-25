#pragma once
#include "stdafx.h"
#include "defines.hpp"

/**
* �������������� �������� V8 x V8 --> V8. ��������� ��� ����� � ���������� �������� * ����� ���� � ���� 2^8.
* 
* @param first ������������ ������� �� ���� 2^8
* @param second ������������ ������� �� ���� 2^8
*
* @return result ��������� �������������� ��������
*/
template <size_t n>
inline byte QuazigroupOperation(byte first, byte second)
{
	//� ������ ������� �������� ��������(throw exception)
	uint16_t firstConverted = (uint16_t)first;
	uint16_t secondConverted = (uint16_t)second;

	//!!! Nado dobavit coeff + multiplication / addition field or integer?
	byte result = (byte)((firstConverted + secondConverted + 2 * firstConverted * secondConverted) % 256);

	return result;
}

/**
* �������� ����� x*y ��� ���������� ���� 2^n.
* ���� � ���, ��� 2^n ����������� �� ����� �� ������ � ���������� �������������� �������� ��� ����.
*
* @param first ������� �� ���� 2^n
* @param second ������� �� ���� 2^n
*
* @return result ��������� �������������� ��������
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