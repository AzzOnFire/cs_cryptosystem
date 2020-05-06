#include "pch.h"
#include "../cs_cryptosystem/defines.hpp"
#include "../cs_cryptosystem/constants.hpp"
#include "../cs_cryptosystem/iv.hpp"
#include "../cs_cryptosystem/keys.hpp"
#include "utils.hpp"

void print_w_constants(const byte* w_array, const size_t length, const size_t block_size_qword) {
    for (size_t i = 0; i < block_size_qword * length; i += block_size_qword) {
        printf("%d ", ((uint64_t*)w_array)[i + block_size_qword - 1]);
    }

    printf("\n");
}


TEST(W_constants, Create_64) {
    constexpr size_t n = 64;
    constexpr size_t length = 10;

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    // print_w_constants(w_array, length, bits_to_qword(n));
}


TEST(W_constants, Create_128) {
    constexpr size_t n = 128;
    constexpr size_t length = 10;

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    // print_w_constants(w_array, length, bits_to_qword(n));
}


TEST(W_constants, Create_256) {
    constexpr size_t n = 256;
    constexpr size_t length = 10;

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    // print_w_constants(w_array, length, bits_to_qword(n));
}


TEST(W_constants, Create_512) {
    constexpr size_t n = 128;
    constexpr size_t length = 10;

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    // print_w_constants(w_array, length, bits_to_qword(n));
}


TEST(W_tau_constants, Create_64) {
    constexpr size_t n = 64;
    constexpr size_t length = 10;

    IV<n>* iv = (IV<n> *)get_test_iv(n);
    byte* key = get_test_key(n);

    byte* derived_key = create_derived_key<n>(key, iv);

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    fill_w_tau_array<n>(w_array, length, derived_key);

    //print_byte_array(w_array, bits_to_bytes(n) * length);
}



TEST(W_tau_constants, Create_128) {
    constexpr size_t n = 128;
    constexpr size_t length = 10;

    IV<n>* iv = (IV<n>*)get_test_iv(n);
    byte* key = get_test_key(n);

    byte* derived_key = create_derived_key<n>(key, iv);

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    fill_w_tau_array<n>(w_array, length, derived_key);

    //print_byte_array(w_array, bits_to_bytes(n) * length);
}



TEST(W_tau_constants, Create_256) {
    constexpr size_t n = 256;
    constexpr size_t length = 10;

    IV<n>* iv = (IV<n>*)get_test_iv(n);
    byte* key = get_test_key(n);

    byte* derived_key = create_derived_key<n>(key, iv);

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    fill_w_tau_array<n>(w_array, length, derived_key);

    //print_byte_array(w_array, bits_to_bytes(n) * length);
}



TEST(W_tau_constants, Create_512) {
    constexpr size_t n = 512;
    constexpr size_t length = 10;

    IV<n>* iv = (IV<n>*)get_test_iv(n);
    byte* key = get_test_key(n);

    byte* derived_key = create_derived_key<n>(key, iv);

    byte* w_array = new byte[bits_to_bytes(n) * length];
    fill_w_array<n>(w_array, length, 0x42);
    fill_w_tau_array<n>(w_array, length, derived_key);

    //print_byte_array(w_array, bits_to_bytes(n) * length);
}
