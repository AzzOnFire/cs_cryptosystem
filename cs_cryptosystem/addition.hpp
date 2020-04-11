#pragma once

#include "defines.hpp"


/**
 * ‘ункци€, осуществл€юща€ операцию XOR над двум€ блоками размера 2^n бит
 *
 * @param first     ѕервый аргумент, хранит в себе результат
 * @param second    ¬торой аргумент
 * @return first    –езультат операции XOR, накопленный в первом аргументе
 */
template <size_t n>
inline byte* addition(byte* first, byte* second) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
    }

    return first;
}


/**
 * ‘ункци€, осуществл€юща€ операцию XOR над трем€ блоками размера 2^n бит
 *
 * @param first     ѕервый аргумент, хранит в себе результат
 * @param second    ¬торой аргумент
 * @param third     “ретий аргумент
 * @return first    –езультат операции XOR, накопленный в первом аргументе
 */
template <size_t n>
inline byte* addition(byte* first, const byte* second, const byte* third) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
        *((uint64_t*)first) ^= *((uint64_t*)third);
    }

    return first;
}
