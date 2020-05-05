#include "pch.h"
#include "../cs_cryptosystem/defines.hpp"
#include "../cs_cryptosystem/keys.hpp"
#include "utils.hpp"


TEST(Shared_Key, Create_64) {
    constexpr size_t n = 64;
    constexpr size_t key_part_size = bits_to_bytes(n);

    byte* key = create_key<n>();
    byte* key_a = key;
    byte* key_b = key + key_part_size;

    print_byte_array(key_a, key_part_size);
    print_byte_array(key_b, key_part_size);
}


TEST(Shared_Key, Create_128) {
    constexpr size_t n = 128;
    constexpr size_t key_part_size = bits_to_bytes(n);

    byte* key = create_key<n>();
    byte* key_a = key;
    byte* key_b = key + key_part_size;

    print_byte_array(key_a, key_part_size);
    print_byte_array(key_b, key_part_size);
}


TEST(Derived_Key, Create_64) {
    constexpr size_t n = 64;
    constexpr size_t d_key_length = bits_to_bytes(n) * 2;

    IV<n> * iv = new IV<n>;
    init_IV<n>(*iv);

    byte* key = create_key<n>();
    byte* derived_key = create_derived_key<n>(key, iv);

    print_byte_array(derived_key, d_key_length);
}


TEST(Derived_Key, Create_128) {
    constexpr size_t n = 128;
    constexpr size_t d_key_length = bits_to_bytes(n) * 2;

    IV<n>* iv = new IV<n>{};
    init_IV<n>(*iv);

    byte* key = create_key<n>();
    byte* derived_key = create_derived_key<n>(key, iv);

    print_byte_array(derived_key, d_key_length);
}