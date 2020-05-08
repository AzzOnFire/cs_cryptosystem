#pragma once

#include "defines.hpp"
#include "quasi.hpp"
#include "disperse.hpp"
#include "addition.hpp"

/**
* Function f, performing some operations with set of coefficients w
*
* @param w              Coefficient w
* @param derived_key    Derived key
*/
template <size_t n>
byte* f_function(byte* w, const byte* derived_key) {
    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    return quasi<n>(disperse<n>(quasi<n>(w, a_key)), b_key);
}

/**
* Function phi, performing addition operation with modified set of coefficients w
*
* @param w_tau          Modified coefficient w
* @param a              Constant
*/
template <size_t n>
byte* phi_function(byte* w_tau, const byte* a) {
    return addition<n>(w_tau, a);
}


/**
* Fill allocated array with w coefficients with initial shift
*
* @param w_array        Allocated array
* @param length         Length of allocated array in blocks
* @param shift          Initial shift
*/
template <size_t n>
byte* fill_w_array(byte* w_array, const size_t length, const size_t shift) {
    memset(w_array, 0x00, bits_to_bytes(n) * length);

    for (size_t i = 0, counter = 0; i < bits_to_qword(n) * length; i += bits_to_qword(n), ++counter) {
        ((uint64_t *)w_array)[i + bits_to_qword(n) - 1] = counter + shift;
    }

    return w_array;
}


/**
* Apply function f to array of w coefficients.
*
* @param w_tau_array    Array of w coefficients
* @param length         Length of allocated array in blocks
* @param derived_key    Derived key
*/
template <size_t n>
byte* fill_w_tau_array(byte* w_tau_array, const size_t length, const byte * derived_key) {
    for (size_t i = 0; i < bits_to_bytes(n) * length; i += bits_to_bytes(n)) {
        f_function<n>(w_tau_array + i, derived_key);
    }

    return w_tau_array;
}


/**
* Apply function phi to array of w coefficients with applied function f.
*
* @param w_tau_array    Array of w coefficients with applied function f
* @param length         Length of allocated array in blocks
* @param phi_constant   Constant for phi function
*/
template <size_t n>
byte* fill_phi_w_tau_array(byte* phi_w_tau_array, const size_t length, const byte* phi_constant) {
    for (size_t i = 0; i < bits_to_bytes(n) * length; i += bits_to_bytes(n)) {
        phi_function<n>(phi_w_tau_array + i, phi_constant);
    }

    return phi_w_tau_array;
}