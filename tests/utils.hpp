#pragma once

void print_byte_array(byte* array, size_t length);

bool cmp_byte_array(byte* first, byte* second, size_t length);

byte* get_test_iv(const size_t n);

byte* get_test_key(size_t n);