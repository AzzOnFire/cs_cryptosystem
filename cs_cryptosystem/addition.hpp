#pragma once

#include "defines.hpp"


/**
 * Perform XOR operation with two arguments with size 2^n bit
 *
 * @param first     First argument, result
 * @param second    Second argument
 * @return first    Result of XOR operation, accumulated in first argument
 */
template <size_t n>
inline byte* addition(byte* first, const byte* second) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
    }

    return first;
}


/**
 * Perform XOR operation with three arguments with size 2^n bit
 *
 * @param first     First argument, result
 * @param second    Second argument
 * @param third     Third argument
 * @return first    Result of XOR operation, accumulated in first argument
 */
template <size_t n>
inline byte* addition(byte* first, const byte* second, const byte* third) {
    for (size_t i = 0; i < bits_to_qword(n); ++i) {
        *((uint64_t*)first) ^= *((uint64_t*)second);
        *((uint64_t*)first) ^= *((uint64_t*)third);
    }

    return first;
}
