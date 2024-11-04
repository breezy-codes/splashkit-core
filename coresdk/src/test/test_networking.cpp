#include "window_manager.h"
#include "networking.h"

#include "assert.h"
#include <iostream>
#include <sstream> // For hex conversions
#include <string>  // For using std::string

#define TEST_IP "127.0.0.1"
#define TEST_IP_HEX "0x7F000001"
#define TEST_DEC 10
#define TEST_BIN "1010"
#define TEST_HEX "FF"

using namespace splashkit_lib;

void dec_to_bin()
{
    assert(dec_to_bin(0) == "0");              // Zero
    assert(dec_to_bin(1) == "1");              // Single bit
    assert(dec_to_bin(2) == "10");             // Simple two-bit binary
    assert(dec_to_bin(10) == "1010");          // Example given in TEST_BIN
    assert(dec_to_bin(123) == "1111011");      // Arbitrary number
    assert(dec_to_bin(1025) == "10000000001"); // Mixed power of 2 with additional bit

    // Larger numbers
    assert(dec_to_bin(255) == "11111111");       // Maximum 8-bit value
    assert(dec_to_bin(256) == "100000000");      // Edge of 9 bits
    assert(dec_to_bin(1023) == "1111111111");    // Maximum 10-bit value
    assert(dec_to_bin(4096) == "1000000000000"); // Larger power of 2

    // Powers of 2
    assert(dec_to_bin(4) == "100");            // 2^2
    assert(dec_to_bin(8) == "1000");           // 2^3
    assert(dec_to_bin(16) == "10000");         // 2^4
    assert(dec_to_bin(1024) == "10000000000"); // 2^10

    // High values (32-bit boundaries)
    assert(dec_to_bin(4294967295) == "11111111111111111111111111111111"); // Max 32-bit unsigned int
    assert(dec_to_bin(2147483648) == "10000000000000000000000000000000"); // 2^31

    // Mixed bits
    assert(dec_to_bin(123) == "1111011");      // Arbitrary number
    assert(dec_to_bin(1025) == "10000000001"); // Mixed power of 2 with additional bit

    std::cout << "All decimal to binary tests passed!" << std::endl;
}

void bin_to_dec()
{
    // Basic cases
    assert(bin_to_dec("0") == 0);              // Single '0'
    assert(bin_to_dec("1") == 1);              // Single '1'
    assert(bin_to_dec("10") == 2);             // Simple binary for decimal 2
    assert(bin_to_dec("1010") == 10);          // Example given in TEST_BIN
    assert(bin_to_dec("1111011") == 123);      // Arbitrary number
    assert(bin_to_dec("10000000001") == 1025); // Mixed power of 2 with additional bit

    // Larger numbers
    assert(bin_to_dec("11111111") == 255);       // Maximum 8-bit binary
    assert(bin_to_dec("100000000") == 256);      // Edge of 9 bits
    assert(bin_to_dec("1111111111") == 1023);    // Maximum 10-bit binary
    assert(bin_to_dec("1000000000000") == 4096); // Larger power of 2

    // Powers of 2
    assert(bin_to_dec("100") == 4);            // 2^2
    assert(bin_to_dec("1000") == 8);           // 2^3
    assert(bin_to_dec("10000") == 16);         // 2^4
    assert(bin_to_dec("10000000000") == 1024); // 2^10

    // High values (32-bit boundaries)
    assert(bin_to_dec("11111111111111111111111111111111") == 4294967295); // Max 32-bit unsigned int
    assert(bin_to_dec("10000000000000000000000000000000") == 2147483648); // 2^31

    // Mixed bits
    assert(bin_to_dec("1111011") == 123);      // Arbitrary number
    assert(bin_to_dec("10000000001") == 1025); // Mixed power of 2 with additional bit

    std::cout << "All binary to decimal tests passed!" << std::endl;
}

void hex_to_bin()
{
    // Basic hexadecimal conversions
    assert(hex_to_bin("0") == "0");    // Single digit "0" in full 4-bit form
    assert(hex_to_bin("1") == "1");    // Single hex "1" in 4-bit form
    assert(hex_to_bin("A") == "1010"); // Single hex letter "A"
    assert(hex_to_bin("F") == "1111"); // Maximum single hex digit "F"

    // Multi-digit hexadecimal conversions
    assert(hex_to_bin("10") == "00010000");           // "10" in hex to full 8-bit binary
    assert(hex_to_bin("FF") == "11111111");           // Max 8-bit binary from hex "FF"
    assert(hex_to_bin("100") == "000100000000");      // "100" in hex to full 12-bit binary
    assert(hex_to_bin("ABC") == "101010111100");      // Arbitrary 3-digit hex value "ABC"
    assert(hex_to_bin("1234") == "0001001000110100"); // Mixed 16-bit hex "1234"

    // Larger hexadecimal values
    assert(hex_to_bin("FFFF") == "1111111111111111");                     // Max 16-bit binary from "FFFF"
    assert(hex_to_bin("FFFFFFFF") == "11111111111111111111111111111111"); // Max 32-bit from "FFFFFFFF"
    assert(hex_to_bin("1FFFFFF") == "0001111111111111111111111111");      // Full width for "1FFFFFF"
    assert(hex_to_bin("ABCDEF") == "101010111100110111101111");           // Arbitrary large hex "ABCDEF"

    std::cout << "All hexadecimal to binary tests passed!" << std::endl;
}

void bin_to_hex()
{
    // Basic binary conversions
    assert(bin_to_hex("0") == "0");    // Single digit zero
    assert(bin_to_hex("1") == "1");    // Single digit one
    assert(bin_to_hex("1010") == "A"); // Four-bit binary to single hex
    assert(bin_to_hex("1111") == "F"); // Max four-bit binary

    // Multi-bit binary conversions
    assert(bin_to_hex("00010000") == "10");           // 8-bit binary with leading zeros for "10"
    assert(bin_to_hex("11111111") == "FF");           // 8-bit maximum value
    assert(bin_to_hex("000100000000") == "100");      // 12-bit binary with leading zeros for "100"
    assert(bin_to_hex("101010111100") == "ABC");      // Arbitrary binary sequence "ABC"
    assert(bin_to_hex("0001001000110100") == "1234"); // Full width for "1234"

    // Larger binary values
    assert(bin_to_hex("1111111111111111") == "FFFF");                     // 16-bit maximum value
    assert(bin_to_hex("11111111111111111111111111111111") == "FFFFFFFF"); // 32-bit max value
    assert(bin_to_hex("0001111111111111111111111111") == "1FFFFFF");      // Full width for "1FFFFFF"
    assert(bin_to_hex("101010111100110111101111") == "ABCDEF");           // Arbitrary large binary "ABCDEF"

    std::cout << "All binary to hexadecimal tests passed!" << std::endl;
}

void test_base64_encode()
{
    // Basic encoding cases
    assert(base64_encode("Man") == "TWFu");                                          // Standard example
    assert(base64_encode("M") == "TQ==");                                            // Single character with padding
    assert(base64_encode("Ma") == "TWE=");                                           // Two characters with padding
    assert(base64_encode("any carnal pleasure.") == "YW55IGNhcm5hbCBwbGVhc3VyZS4="); // Sentence with punctuation

    // Edge cases
    assert(base64_encode("") == "");        // Empty string
    assert(base64_encode("A") == "QQ==");   // Single character
    assert(base64_encode("BC") == "QkM=");  // Two characters
    assert(base64_encode("yes") == "eWVz"); // Three characters, no padding needed

    // Larger strings
    assert(base64_encode("Hello, World!") == "SGVsbG8sIFdvcmxkIQ==");                                                                       // Common phrase
    assert(base64_encode("The quick brown fox jumps over the lazy dog") == "VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZw=="); // Long sentence

    std::cout << "All Base64 encoding tests passed!" << std::endl;
}

void test_base64_decode()
{
    // Basic decoding cases
    assert(base64_decode("TWFu") == "Man");                                          // Standard example
    assert(base64_decode("TQ==") == "M");                                            // Single character with padding
    assert(base64_decode("TWE=") == "Ma");                                           // Two characters with padding
    assert(base64_decode("YW55IGNhcm5hbCBwbGVhc3VyZS4=") == "any carnal pleasure."); // Sentence with punctuation

    // Edge cases
    assert(base64_decode("") == "");        // Empty string
    assert(base64_decode("QQ==") == "A");   // Single character
    assert(base64_decode("QkM=") == "BC");  // Two characters
    assert(base64_decode("eWVz") == "yes"); // Three characters, no padding

    // Larger strings
    assert(base64_decode("SGVsbG8sIFdvcmxkIQ==") == "Hello, World!");                                                                       // Common phrase
    assert(base64_decode("VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZw==") == "The quick brown fox jumps over the lazy dog"); // Long sentence

    std::cout << "All Base64 decoding tests passed!" << std::endl;
}

void test_dec_to_oct()
{
    // Basic decimal to octal cases
    assert(dec_to_oct(0) == "0");     // Zero case
    assert(dec_to_oct(8) == "10");    // Single-digit octal result
    assert(dec_to_oct(64) == "100");  // Powers of 8
    assert(dec_to_oct(123) == "173"); // Arbitrary decimal to octal
    assert(dec_to_oct(255) == "377"); // Max 8-bit value
    // Larger numbers
    assert(dec_to_oct(1023) == "1777"); // Larger decimal to octal
    assert(dec_to_oct(4095) == "7777"); // Edge of 12-bit value

    std::cout << "All decimal to octal tests passed!" << std::endl;
}
void test_oct_to_dec(){
    // Basic octal to decimal cases
    assert(oct_to_dec("0") == 0);     // Zero case
    assert(oct_to_dec("10") == 8);    // Single-digit decimal result
    assert(oct_to_dec("100") == 64);  // Powers of 8
    assert(oct_to_dec("173") == 123); // Arbitrary octal to decimal
    assert(oct_to_dec("377") == 255); // Max 8-bit value

    assert(oct_to_dec("1777") == 1023); // Larger octal to decimal
    assert(oct_to_dec("7777") == 4095); // Edge of 12-bit value

    std::cout << "All octal to decimal tests passed!" << std::endl;
}

void run_networking_test()
{
    dec_to_bin();
    bin_to_dec();
    hex_to_bin();
    bin_to_hex();
    test_base64_encode();
    test_base64_decode();
    test_dec_to_oct();
    test_oct_to_dec();
}
