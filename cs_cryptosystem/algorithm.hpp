#pragma once

#include "defines.hpp"
#include "multiplication.hpp"
#include "addition.hpp"
#include "disperse.hpp"
#include "quasi.hpp"
#include "iv.hpp"
#include "keys.hpp"
#include "constants.hpp"


/**
 * Encrypt one block of plain text
 *
 * @param block             Plain text block
 * @param a_key             Encryption key part a
 * @param b_key             Encryption key part b
 * @param w_tau             Array of w coefficients with applied function f
 * @param phi_w_tau         Array of w coefficients with applied functions f and phi
 */
template <size_t n>
void encrypt_block(byte* block, const byte* a_key, const byte* b_key, byte* w_tau, byte* phi_w_tau) {
    const byte* A_block = multiplication<n>(w_tau, a_key);
    const byte* B_block = multiplication<n>(phi_w_tau, b_key);

    addition<n>(block, A_block, B_block);
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
byte* cs_encrypt(const byte* key, IV<n> * iv, const byte* phi_constant, const byte* plain, const size_t length) {
    byte* cypher = new byte[length + bits_to_bytes(n)];

    byte* w_array = new byte[length * bits_to_bytes(n)];
    byte* w_tau_array = w_array;
    byte* phi_w_tau_array = new byte[length * bits_to_bytes(n)];

    byte* derived_key = create_derived_key<n>(key, iv);

    fill_w_array<n>(w_array, length, 0x42);
    fill_w_tau_array<n>(w_tau_array, length, derived_key);

    memcpy(phi_w_tau_array, w_tau_array, length * bits_to_bytes(n));
    fill_phi_w_tau_array<n>(phi_w_tau_array, length, phi_constant);

    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    const size_t block_index = 0;

    // Value, calculated on every iteration. Needs for authority check
    byte* delta = new byte[bits_to_bytes(n)]; 
    memset(delta, 0x00, bits_to_bytes(n));

    for (size_t i = 0; i < length; i += bits_to_bytes(n)) {
        encrypt_block<n>(cypher + i, a_key, b_key, w_tau_array + i, phi_w_tau_array + i);
        delta = addition<n>(delta, cypher + i);
        delta = multiplication<n>(delta, b_key);
    }

    delta = addition<n>(delta, a_key);
    memcpy(cypher + length, delta, bits_to_bytes(n));
    
    return cypher;
}