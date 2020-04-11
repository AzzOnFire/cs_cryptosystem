#pragma once

#include "defines.hpp"
#include "multiplication.hpp"
#include "addition.hpp"

/**
 * Функция g, осуществляющая генерацию производного ключа на основе ключа зашифрования и вектора инициализации
 *
 * @param key           Ключ зашифрования
 * @param init_vector   Вектор инициализации
 * @return derived_key  Производный ключ, сгенерированный по общему ключу и вектору инициализации
 */
template <size_t n>
byte* g_function(const byte* key, const byte* init_vector) {

}

/**
* Тот кто делает эту функцию, напиши здесь коммент (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* f_function(const byte* d_key, const byte* w) {

}

/**
* Тот кто делает эту функцию, напиши здесь коммент (͡° ͜ʖ ͡°)
*/
template <size_t n>
byte* phi_function(const byte* w_tau) {

}

/**
 * Функция, осуществляющая зашифрование открытого текста на основе ключа
 *
 * @param key       Ключ зашифрования
 * @param plain     Открытый текст
 * @param length    Длина открытого текста
 * @return cypher   Зашифрованный текст
 */
template <size_t n>
byte* cs_encrypt(const byte* key, const byte* plain, const size_t length) {
    byte* cypher = new byte[length + bits_to_bytes(n)];

    byte* init_vector;
    byte* derived_key = g_function<n>(key, init_vector);
    byte* w_array = nullptr;
    byte* w_tau_array = nullptr;
    byte* phi_w_tau_array = nullptr;

    const byte* a_key = derived_key;
    const byte* b_key = derived_key + bits_to_bytes(n);

    const size_t block_index;

    byte* delta = new byte[bits_to_bytes(n)]{ 0 };

    for (size_t i = 0; i < length; i += bits_to_bytes(n)) {
        encrypt_block(cypher[i], a_key, b_key, w_tau_array[i], phi_w_tau_array[i]);
        delta = addition<n>(delta, cypher[i]);
        delta = multiplication<n>(delta, b_key);
    }

    cypher[length] = addition<n>(delta, a_key);

    return cypher;
}

/**
 * Функция, осуществляющая зашифрование одного блока открытого текста
 *
 * @param block             Блок открытого текста
 * @param a_key             Ключ зашифрования a
 * @param b_key             Ключ зашифрования b
 * @param w_tau             Пока что не знаю как это назвать                TODO
 * @param phi_w_tau         Пока что не знаю как это назвать                TODO
 */
template <size_t n>
void encrypt_block(byte* block, const byte* a_key, const byte* b_key, const byte* w_tau, const byte* phi_w_tau) {
    const byte* A_block = multiplication<n>(a_key, w_tau);
    const byte* B_block = multiplication<n>(b_key, phi_w_tau);

    addition<n>(block, A_block, B_block);
}
