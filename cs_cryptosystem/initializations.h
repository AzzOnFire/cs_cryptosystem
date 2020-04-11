#include "sha256.h"
#include "multiply256.h"

typedef unsigned char byte;
#define SIZE_HASH 64 //в байтах
using namespace std;

/**
 * Функция, генерирующая ключ k = (a,b),где a,b из GF(2^n) выбираются случайным образом
 * !Выделяется память!
 * 
 * @return key  Ключ зашифрования
 */
template <size_t n>
byte * generate_key() 
{
    const size_t key_length = n/4;
    auto key = new int[key_length];

    for(size_t index = 0; index < key_length; ++index)
        //не равновероятный выбор, необходимо реализовать равновероятный выбор
        key[index] = rand(); 
        
    return (byte *)key;
};

/**
 * Функция, осуществляющая генерацию производного ключа на основе формул Боуза (8),(9)
 *
 * @param key           Ключ зашифрования
 * @param init_vector   Вектор инициализации
 * @return derived_key  Производный ключ, сгенерированный по общему ключу и вектору инициализации
 */
template <size_t n>
byte * create_derived_key(const byte* key, const byte* init_vector) {
    
}

/**
 * Функция, осуществляющая генерацию производного ключа на основе усложненных формул Боуза (10)
 * !Пока что не обязательно реализовывать этот метод!
 *
 * @param key           Ключ зашифрования
 * @param init_vector   Вектор инициализации
 * @return derived_key  Производный ключ, сгенерированный по общему ключу и вектору инициализации
 */
template <size_t n>
byte * create_complex_derived_key(const byte* key, const byte* init_vector) {
    
}

/**
 * Структура определяет вектор инициализации и данные связанные с ним
 * Необходимо хранить : счетчик объектов, метку времени, атрибуты передаваемого сообщения
 * (Заголовок, адрес отправителя/получателя, гриф секретности и пр.)
 */
template <size_t n>
struct IV
{
    static int count_iv;
    string plain_text;

    IV(string text)
    {
        plain_text = text;
        count_iv++;
    };

    int get_count();
    byte* init_vector();
};

/**
 *  Счетчик векторов инициализации
 */
template <size_t n>
int IV<n>::count_iv = 0;

/**
 * Получить порядковый номер вектора инициализации 
 */
template <size_t n>
int IV<n>::get_count()
{
    return count_iv;
}

/**
 * Функция для "расширения" хэша в случае, когда длина вектора инициализации больше 512 бит,которые
 * мы получаем на выходе sha256
 * 
 * @param key       Вектор инициализации
 * @param length    Кол-во заполненных байт в векторе инициализации
 * @param deffir    Кол-во байт, которые необходимо заполнить хэшами     
 */
void expand_init_vector(byte* key, const size_t length, const size_t differ)
{
    for(size_t index = length; index < length + differ; index+=SIZE_HASH)
    {
        auto additional_hash =  sha256(to_string(rand()));
        additional_hash.copy((char*)key + index,SIZE_HASH);
    }
}

/**
 * Метод для создания вектора инициализации vi = (a,b), где a,b из GF(2^n)
 * !Выделяется память!
 * 
 * @return iv   Вектор инициализации
 */
template<size_t n>
byte* IV<n>::init_vector()
{
    const string text_for_hash = plain_text + to_string(count_iv);
    const string hash = sha256(text_for_hash);

    //длина вектора инициализации в байтах
    const size_t iv_lenght = n/4;
    byte* iv = new byte[iv_lenght + 1];
    const size_t length = hash.copy((char*)iv, iv_lenght);
    
    if(iv_lenght > SIZE_HASH)
    {
        const size_t differ = iv_lenght - SIZE_HASH;
        expand_init_vector(iv, length, differ);   
    }
    
    return iv;
}

/**
 * Функция - реализация XOR двух байтовых массивов
 * 
 * @param  left_arr   Указатель на начало первого числа(массива байт)
 * @param  right_arr  Указатель на начало второго числа
 * @return res        XOR из двух байтовых массивов left_arr right_arr
 */
template<size_t n>
byte* xor_arrays(byte* left_arr, byte* right_arr)
{
    size_t length = n/8;
	byte* res = new byte[length]; 
	
	for(size_t index = 0; index < length; ++index)
	{
        char xor_left_right = left_arr[index] ^ right_arr[index];
        res[index] = xor_left_right;
    }
    
    return res;
}

