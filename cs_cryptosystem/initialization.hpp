#pragma once

#include "defines.hpp"
#include "sha256.hpp"

#define SIZE_HASH 64 //� ������

/**
 * �������, ������������ ���� k = (a,b),��� a,b �� GF(2^n) ���������� ��������� �������
 * !���������� ������!
 *
 * @return key  ���� ������������
 */
template <size_t n>
byte* generate_key()
{
    const size_t key_length = n / 4;
    auto key = new int[key_length];

    for (size_t index = 0; index < key_length; ++index)
        //�� �������������� �����, ���������� ����������� �������������� �����
        key[index] = rand();

    return (byte*)key;
};

/**
 * �������, �������������� ��������� ������������ ����� �� ������ ������ ����� (8),(9)
 *
 * @param key           ���� ������������
 * @param init_vector   ������ �������������
 * @return derived_key  ����������� ����, ��������������� �� ������ ����� � ������� �������������
 */
template <size_t n>
byte* create_derived_key(const byte* key, const byte* init_vector) {

}

/**
 * �������, �������������� ��������� ������������ ����� �� ������ ����������� ������ ����� (10)
 * !���� ��� �� ����������� ������������� ���� �����!
 *
 * @param key           ���� ������������
 * @param init_vector   ������ �������������
 * @return derived_key  ����������� ����, ��������������� �� ������ ����� � ������� �������������
 */
template <size_t n>
byte* create_complex_derived_key(const byte* key, const byte* init_vector) {

}

/**
 * ��������� ���������� ������ ������������� � ������ ��������� � ���
 * ���������� ������� : ������� ��������, ����� �������, �������� ������������� ���������
 * (���������, ����� �����������/����������, ���� ����������� � ��.)
 */
template <size_t n>
struct IV
{
    static int count_iv;
    std::string plain_text;

    IV(std::string text)
    {
        plain_text = text;
        count_iv++;
    };

    int get_count();
    byte* init_vector();
};

/**
 *  ������� �������� �������������
 */
template <size_t n>
int IV<n>::count_iv = 0;

/**
 * �������� ���������� ����� ������� �������������
 */
template <size_t n>
int IV<n>::get_count()
{
    return count_iv;
}

/**
 * ������� ��� "����������" ���� � ������, ����� ����� ������� ������������� ������ 512 ���,�������
 * �� �������� �� ������ sha256
 *
 * @param key       ������ �������������
 * @param length    ���-�� ����������� ���� � ������� �������������
 * @param deffir    ���-�� ����, ������� ���������� ��������� ������
 */
void expand_init_vector(byte* key, const size_t length, const size_t differ) {
    for (size_t index = length; index < length + differ; index += SIZE_HASH)
    {
        auto additional_hash = sha256(std::to_string(rand()));
        additional_hash.copy((char*)key + index, SIZE_HASH);
    }
}

/**
 * ����� ��� �������� ������� ������������� vi = (a,b), ��� a,b �� GF(2^n)
 * !���������� ������!
 *
 * @return iv   ������ �������������
 */
template<size_t n>
byte* IV<n>::init_vector() {
    const std::string text_for_hash = plain_text + std::to_string(count_iv);
    const std::string hash = sha256(text_for_hash);

    //����� ������� ������������� � ������
    const size_t iv_lenght = n / 4;
    byte* iv = new byte[iv_lenght + 1];
    const size_t length = hash.copy((char*)iv, iv_lenght);

    if (iv_lenght > SIZE_HASH)
    {
        const size_t differ = iv_lenght - SIZE_HASH;
        expand_init_vector(iv, length, differ);
    }

    return iv;
}
