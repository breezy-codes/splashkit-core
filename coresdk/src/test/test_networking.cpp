#include "window_manager.h"
#include "networking.h"

#include "assert.h"
#include <iostream>
#include <sstream>  // For hex conversions
#include <string>   // For using std::string

#define TEST_IP "127.0.0.1"
#define TEST_IP_HEX "0x7F000001"
#define TEST_DEC 10
#define TEST_BIN "1010"
#define TEST_HEX "FF"

using namespace splashkit_lib;

void dec_to_bin()
{
    assert(dec_to_bin(0) == "0");                // Zero
    assert(dec_to_bin(1) == "1");                // Single bit
    assert(dec_to_bin(2) == "10");               // Simple two-bit binary
    assert(dec_to_bin(10) == "1010");            // Example given in TEST_BIN

    // Larger numbers
    assert(dec_to_bin(255) == "11111111");       // Maximum 8-bit value
    assert(dec_to_bin(256) == "100000000");      // Edge of 9 bits
    assert(dec_to_bin(1023) == "1111111111");    // Maximum 10-bit value
    assert(dec_to_bin(4096) == "1000000000000"); // Larger power of 2

    // Powers of 2
    assert(dec_to_bin(4) == "100");              // 2^2
    assert(dec_to_bin(8) == "1000");             // 2^3
    assert(dec_to_bin(16) == "10000");           // 2^4
    assert(dec_to_bin(1024) == "10000000000");   // 2^10

    // High values (32-bit boundaries)
    assert(dec_to_bin(4294967295) == "11111111111111111111111111111111"); // Max 32-bit unsigned int
    assert(dec_to_bin(2147483648) == "10000000000000000000000000000000"); // 2^31

    // Mixed bits
    assert(dec_to_bin(123) == "1111011");        // Arbitrary number
    assert(dec_to_bin(1025) == "10000000001");   // Mixed power of 2 with additional bit

    std::cout << "All decimal to binary tests passed!" << std::endl;
}

void bin_to_dec()
{
    // Basic cases
    assert(bin_to_dec("0") == 0);               // Single '0'
    assert(bin_to_dec("1") == 1);               // Single '1'
    assert(bin_to_dec("10") == 2);              // Simple binary for decimal 2
    assert(bin_to_dec("1010") == 10);           // Example given in TEST_BIN

    // Larger numbers
    assert(bin_to_dec("11111111") == 255);      // Maximum 8-bit binary
    assert(bin_to_dec("100000000") == 256);     // Edge of 9 bits
    assert(bin_to_dec("1111111111") == 1023);   // Maximum 10-bit binary
    assert(bin_to_dec("1000000000000") == 4096); // Larger power of 2

    // Powers of 2
    assert(bin_to_dec("100") == 4);             // 2^2
    assert(bin_to_dec("1000") == 8);            // 2^3
    assert(bin_to_dec("10000") == 16);          // 2^4
    assert(bin_to_dec("10000000000") == 1024);  // 2^10

    // High values (32-bit boundaries)
    assert(bin_to_dec("11111111111111111111111111111111") == 4294967295); // Max 32-bit unsigned int
    assert(bin_to_dec("10000000000000000000000000000000") == 2147483648); // 2^31

    // Mixed bits
    assert(bin_to_dec("1111011") == 123);       // Arbitrary number
    assert(bin_to_dec("10000000001") == 1025);  // Mixed power of 2 with additional bit

    std::cout << "All binary to decimal tests passed!" << std::endl;
}

void run_networking_test()
{
    dec_to_bin();
    bin_to_dec();
}
