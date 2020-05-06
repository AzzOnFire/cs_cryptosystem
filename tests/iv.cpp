#include "pch.h"
#include "../cs_cryptosystem/defines.hpp"
#include "../cs_cryptosystem/iv.hpp"
#include "utils.hpp"

TEST(IV, Init_64) {
    constexpr size_t n = 64;

    IV<n> iv;
    init_IV<n>(iv);

    // print_byte_array((byte*)&iv, sizeof(iv));
}


TEST(IV, Init_128) {
    constexpr size_t n = 128;

    IV<n> iv;
    init_IV<n>(iv);

    // print_byte_array((byte*)&iv, sizeof(iv));
}


TEST(IV, Init_256) {
    constexpr size_t n = 256;

    IV<n> iv;
    init_IV<n>(iv);

    // print_byte_array((byte*)&iv, sizeof(iv));
}


TEST(IV, Init_512) {
    constexpr size_t n = 512;

    IV<n> iv;
    init_IV<n>(iv);

    // print_byte_array((byte*)&iv, sizeof(iv));
}