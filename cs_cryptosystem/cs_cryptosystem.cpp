#include <iostream>

typedef unsigned char byte;

/**
 * Функция g, осуществляющая генерацию производного ключа на основе ключа зашифрования и вектора инициализации
 *
 * @param key           Ключ зашифрования
 * @param init_vector   Вектор инициализации
 * @return derived_key  Производный ключ, сгенерированный по общему ключу и вектору инициализации
 */
template <size_t n>
byte * g_function(const byte* key, const byte* init_vector) {
    
}

template <size_t n>
byte * init_vector() {

}

/**
 * Функция, осуществляющая зашифрование открытого текста на основе ключа
 *
 * @param key           Ключ зашифрования
 * @param plain         Открытый текст
 * @param length        Длина открытого текста
 * @return derived_key  Зашифрованный текст
 */
template <size_t n>
void cs_encrypt(const byte* key, const byte* plain, const size_t length) {
    byte* init_vector;
    byte* derived_key = g_function<n>(key, init_vector);

}

template <size_t n>
void cs_algorithm(const byte* derived_key) {

}

int main() {
    std::cout << "Hello World!\n";
}
