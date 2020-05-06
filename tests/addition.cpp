#include "pch.h"
#include "../cs_cryptosystem/defines.hpp"
#include "../cs_cryptosystem/addition.hpp"
#include "utils.hpp"


TEST(Addition, Two_Numbers_64) {
    constexpr size_t n = 64;

    const size_t length = bits_to_bytes(n);

    byte* number_1 = new byte[length]{ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };
    byte* number_2 = new byte[length]{ 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };
    byte* expected = new byte[length]{ 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88 };

    //print_byte_array(number_1, length);
    //print_byte_array(number_2, length);
    
    addition<n>(number_1, number_2);
    //print_byte_array(number_1, length);
    
    EXPECT_TRUE(cmp_byte_array(number_1, expected, length));
}


TEST(Addition, Three_Numbers_64) {
    constexpr size_t n = 64;

    const size_t length = bits_to_bytes(n);

    byte* number_1 = new byte[length]{ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };
    byte* number_2 = new byte[length]{ 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };
    byte* number_3 = new byte[length]{ 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00 };

    byte* expected = new byte[length]{ 0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88 };

    //print_byte_array(number_1, length);
    //print_byte_array(number_2, length);

    addition<n>(number_1, number_2, number_3);
    //print_byte_array(number_1, length);

    EXPECT_TRUE(cmp_byte_array(number_1, expected, length));
}