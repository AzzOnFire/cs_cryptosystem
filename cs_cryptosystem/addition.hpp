#pragma once

#include "defines.hpp"


/**
 * �������, �������������� �������� XOR ��� ����� ������� ������� 2^n ���
 *
 * @param first     ������ ��������, ������ � ���� ���������
 * @param second    ������ ��������
 * @return first    ��������� �������� XOR, ����������� � ������ ���������
 */
template <size_t n>
inline byte* addition(byte* first, byte* second) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
    }

    return first;
}


/**
 * �������, �������������� �������� XOR ��� ����� ������� ������� 2^n ���
 *
 * @param first     ������ ��������, ������ � ���� ���������
 * @param second    ������ ��������
 * @param third     ������ ��������
 * @return first    ��������� �������� XOR, ����������� � ������ ���������
 */
template <size_t n>
inline byte* addition(byte* first, const byte* second, const byte* third) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
        *((uint64_t*)first) ^= *((uint64_t*)third);
    }

    return first;
}
