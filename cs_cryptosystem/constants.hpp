#pragma once

#include "defines.hpp"
#include "quasi.hpp"
#include "dispersingtransform.hpp"
#include "addition.hpp"

/**
* Who write that function, don't forget to write comment (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* f_function(byte* w, const byte* derived_key) {
    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    return quasi<n>(disperse<n>(quasi<n>(w, a_key)), b_key);
}

/**
* Who write that function, don't forget to write comment (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* phi_function(byte* w_tau, const byte* a) {
    return addition<n>(w_tau, a);
}

template <size_t n>
byte* fill_w_array(byte* w_array, const size_t length, const size_t shift) {
    memset(w_array, 0x00, bits_to_bytes(n) * length);

    for (size_t i = 0, counter = 0; i < bits_to_qword(n) * length; i += bits_to_qword(n), ++counter) {
        ((uint64_t *)w_array)[i + bits_to_qword(n) - 1] = counter + shift;
    }

    return w_array;
}

template <size_t n>
byte* fill_w_tau_array(byte* w_array, const size_t length, const byte * derived_key) {
    const byte* a = new byte[bits_to_bytes(n)];

    for (size_t i = 0; i < bits_to_bytes(n) * length; i += bits_to_bytes(n)) {
        f_function<n>(w_array + i, derived_key);
    }

    return w_array;
}