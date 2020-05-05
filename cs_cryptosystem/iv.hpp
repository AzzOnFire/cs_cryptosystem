#pragma once 

#include "defines.hpp"
#include <random>
#include <time.h>

#define iv_additional_size(n) (bits_to_bytes(2 * n) - 2 * sizeof(uint64_t))


/**
 * The structure defines the initialization vector
 * Must be stored: counter, timestamp, random payload
 */
template <size_t n>
struct IV {
    uint64_t counter;
    uint64_t time;
    
    byte additional[iv_additional_size(n)];
};

/**
 * Function for filling initialization vector. 
 *
 * @param iv       Initialization vector to fill
 */
template <size_t n>
void init_IV(IV<n> & iv) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int16_t> dis(0, INT16_MAX);

    iv.counter = 0x42;

    time_t ltime;
    time(&ltime);
    struct tm* timeinfo = gmtime(&ltime); // to UTC
    iv.time = mktime(timeinfo);

    for (size_t i = 0; i < iv_additional_size(n); ++i) {
        iv.additional[i] = dis(gen);
    }
}
