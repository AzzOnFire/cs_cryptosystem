#include "pch.h"
#include "../cs_cryptosystem/algorithm.hpp"
#include "../cs_cryptosystem/iv.hpp"
#include "utils.hpp"


TEST(Common, Test_64) {
    constexpr size_t n = 64;

    byte* key = get_test_key(n);
    IV<n> * iv = (IV<n> *)get_test_iv(n);
    
    byte phi_constast[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };

    byte text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec facilisis enim luctus congue ullamcorper. "
        "Fusce sit amet euismod turpis, in pellentesque libero. Donec cursus congue lobortis. In ex mauris,";

    size_t length = sizeof(text);
    print_byte_array(text, length);

    byte * encrypted = cs_encrypt<n>(key, iv, phi_constast, text, length);
    print_byte_array(encrypted, length);

    byte* decrypted = cs_encrypt<n>(key, iv, phi_constast, encrypted, length);
    print_byte_array(decrypted, length);
}