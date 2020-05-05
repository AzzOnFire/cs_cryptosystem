#pragma once

#include "defines.hpp"
#include "multiplication.hpp"
#include "addition.hpp"
#include "dispersingtransform.hpp"
#include "quasi.hpp"


/**
* Who write that function, don't forget to write comment (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* f_function(byte* w, const byte* derived_key) {
    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    return quasi<n>(disperse<n>(quasi<n>(w, a_key), b_key));
}

/**
* Who write that function, don't forget to write comment (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* phi_function(byte* w_tau, const byte* a) {
    return addition<n>(w_tau, a);
}

template <size_t n>
byte* fill_w_array(const size_t length, const size_t shift) {
    byte* w_array = new byte[bits_to_bytes(n) * length];


    for (size_t i = 0; i < bits_to_bytes(n) * length; i += bits_to_bytes(n)) {
        w_array[i + bits_to_bytes(n) - 1] = i + shift;
    }

    return w_array;
}

template <size_t n>
byte* fill_w_tau_array(byte * w_array, const size_t length, const size_t derived_key) {
    const byte* a = new byte[bits_to_bytes(n)];

    for (size_t i = 0; i < bits_to_bytes(n) * length; i += bits_to_bytes(n)) {
        f_function<n>(w_array + i, derived_key);
    }

    return w_array;
}

/**
 * Encrypt plain text with encryption key
 *
 * @param key       Encryption key
 * @param plain     Plain text
 * @param length    Plain text length
 * @return cypher   Encrypted text
 */
template <size_t n>
byte* cs_encrypt(const byte* key, const byte* plain, const size_t length) {
    byte* cypher = new byte[length + bits_to_bytes(n)];

    byte* iv;
    byte* derived_key = nullptr;
    byte* w_array = fill_w_array<n>(length, 10);
    byte* w_tau_array = fill_w_tau_array<n>(w_array, length, derived_key);
    byte* phi_w_tau_array = nullptr;

    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    const size_t block_index;

    // Value, calculated on every iteration
    byte* delta = new byte[bits_to_bytes(n)]; 
    memset(delta, 0x00, bits_to_bytes(n));

    for (size_t i = 0; i < length; i += bits_to_bytes(n)) {
        encrypt_block(cypher[i], a_key, b_key, w_tau_array[i], phi_w_tau_array[i]);
        delta = addition<n>(delta, cypher[i]);
        delta = multiplication<n>(delta, b_key);
    }

    cypher[length] = addition<n>(delta, a_key);

    return cypher;
}

/**
 * Encrypt one block of plain text
 *
 * @param block             Plain text block
 * @param a_key             Encryption key a
 * @param b_key             Encryption key b
 * @param w_tau             TODO
 * @param phi_w_tau         TODO
 */
template <size_t n>
void encrypt_block(byte* block, const byte* a_key, const byte* b_key, const byte* w_tau, const byte* phi_w_tau) {
    const byte* A_block = multiplication<n>(a_key, w_tau);
    const byte* B_block = multiplication<n>(b_key, phi_w_tau);

    addition<n>(block, A_block, B_block);
}
