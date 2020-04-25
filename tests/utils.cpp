#include "pch.h"

#include "utils.hpp"

void print_byte_array(byte* array, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        printf("%x ", array[i] & 0xff);
    }

    printf("\n");
}

bool cmp_byte_array(byte* first, byte* second, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (first[i] != second[i])
            return false;
    }

    return true;
}