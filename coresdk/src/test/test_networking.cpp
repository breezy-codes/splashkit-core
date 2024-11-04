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
    assert(dec_to_bin(123) == "1111011");        // Arbitrary number
    assert(dec_to_bin(1025) == "10000000001");   // Mixed power of 2 with additional bit

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
    assert(bin_to_dec("1111011") == 123);       // Arbitrary number
    assert(bin_to_dec("10000000001") == 1025);  // Mixed power of 2 with additional bit

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

void hex_to_bin(){
    // Basic hexadecimal conversions
    assert(hex_to_bin("0") == "0");                 // Single digit "0" in full 4-bit form
    assert(hex_to_bin("1") == "1");                 // Single hex "1" in 4-bit form
    assert(hex_to_bin("A") == "1010");                 // Single hex letter "A"
    assert(hex_to_bin("F") == "1111");                 // Maximum single hex digit "F"

    // Multi-digit hexadecimal conversions
    assert(hex_to_bin("10") == "00010000");            // "10" in hex to full 8-bit binary
    assert(hex_to_bin("FF") == "11111111");            // Max 8-bit binary from hex "FF"
    assert(hex_to_bin("100") == "000100000000");       // "100" in hex to full 12-bit binary
    assert(hex_to_bin("ABC") == "101010111100");       // Arbitrary 3-digit hex value "ABC"
    assert(hex_to_bin("1234") == "0001001000110100");  // Mixed 16-bit hex "1234"

    // Larger hexadecimal values
    assert(hex_to_bin("FFFF") == "1111111111111111");  // Max 16-bit binary from "FFFF"
    assert(hex_to_bin("FFFFFFFF") == "11111111111111111111111111111111"); // Max 32-bit from "FFFFFFFF"
    assert(hex_to_bin("1FFFFFF") == "0001111111111111111111111111");  // Full width for "1FFFFFF"
    assert(hex_to_bin("ABCDEF") == "101010111100110111101111");           // Arbitrary large hex "ABCDEF"

    std::cout << "All hexadecimal to binary tests passed!" << std::endl;
}

void bin_to_hex(){
    // Basic binary conversions
    assert(bin_to_hex("0") == "0");                     // Single digit zero
    assert(bin_to_hex("1") == "1");                     // Single digit one
    assert(bin_to_hex("1010") == "A");                  // Four-bit binary to single hex
    assert(bin_to_hex("1111") == "F");                  // Max four-bit binary

    // Multi-bit binary conversions
    assert(bin_to_hex("00010000") == "10");             // 8-bit binary with leading zeros for "10"
    assert(bin_to_hex("11111111") == "FF");             // 8-bit maximum value
    assert(bin_to_hex("000100000000") == "100");        // 12-bit binary with leading zeros for "100"
    assert(bin_to_hex("101010111100") == "ABC");        // Arbitrary binary sequence "ABC"
    assert(bin_to_hex("0001001000110100") == "1234");   // Full width for "1234"

    // Larger binary values
    assert(bin_to_hex("1111111111111111") == "FFFF");   // 16-bit maximum value
    assert(bin_to_hex("11111111111111111111111111111111") == "FFFFFFFF"); // 32-bit max value
    assert(bin_to_hex("0001111111111111111111111111") == "1FFFFFF"); // Full width for "1FFFFFF"
    assert(bin_to_hex("101010111100110111101111") == "ABCDEF");           // Arbitrary large binary "ABCDEF"

    std::cout << "All binary to hexadecimal tests passed!" << std::endl;
}

void run_networking_test()
{
    dec_to_bin();
    bin_to_dec();
    hex_to_bin();
    bin_to_hex();
}
