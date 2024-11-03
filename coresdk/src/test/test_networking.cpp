#include "window_manager.h"
#include "networking.h"

#include "assert.h"
#include <iostream>
#include <sstream>  // For hex conversions
#include <string>   // For using std::string

#define TEST_IP "127.0.0.1"
#define TEST_IP_HEX "0x7F000001"
#define TEST_DEC 255
#define TEST_BIN "11111111"
#define TEST_HEX "FF"
#define TEST_BIN_DOTTED "00000000.11111111"

using namespace splashkit_lib;

void run_encoding_decoding_tests()
{

    // New function tests
    // Decimal to binary and back
    assert(dec_to_bin(TEST_DEC) == TEST_BIN);
    assert(bin_to_dec(TEST_BIN) == TEST_DEC);

    // Hexadecimal to binary and back
    assert(hex_to_bin(TEST_HEX) == TEST_BIN);
    assert(bin_to_hex(TEST_BIN) == std::string("0x") + TEST_HEX);

    // Optional dotted binary format check
    assert(dec_to_bin(TEST_DEC) == TEST_BIN_DOTTED);

    std::cout << "All encoding/decoding tests passed!" << std::endl;
}

void run_networking_test()
{
    run_encoding_decoding_tests();
}
