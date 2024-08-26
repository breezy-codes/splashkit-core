#include "window_manager.h"
#include "networking.h"

#include "assert.h"

#include <iostream>

#define TEST_IP "127.0.0.1"
#define TEST_IP_HEX "0x7F000001"
#define TEST_IP_BIN "01111111.00000000.00000000.00000001"

using namespace splashkit_lib;

void run_encoding_decoding_tests()
{
    // Incomplete ip address tests
    assert(ipv4_to_hex("127.0.0") == "0x7F000000");
    assert(ipv4_to_str(ipv4_to_dec("127.0.0")) == "127.0.0.0");
    assert(ipv4_to_str(ipv4_to_dec("127,0.0")) == "127.0.0.0");
    assert(ipv4_to_str(ipv4_to_dec("")) == "0.0.0.0");
    assert(ipv4_to_bin("127.0.0") == "01111111.00000000.00000000.00000000");

    int too_small_int = 4000;
    assert(ipv4_to_str(too_small_int) == "0.0.15.160");

    // Complete ip address tests
    assert(ipv4_to_str(ipv4_to_dec(TEST_IP)) == TEST_IP);
    assert(dec_to_hex(ipv4_to_dec(TEST_IP)) == TEST_IP_HEX);
    assert(ipv4_to_hex(TEST_IP) == TEST_IP_HEX);
    assert(hex_str_to_ipv4(TEST_IP_HEX) == TEST_IP);
    assert(my_ip() == "127.0.0.1");

    // Binary encoding/decoding tests
    assert(ipv4_to_bin(TEST_IP) == TEST_IP_BIN);
    assert(bin_to_ipv4(TEST_IP_BIN) == TEST_IP);
}

void run_networking_test()
{
    run_encoding_decoding_tests();
    std::cout << "Starting" << std::endl;


        std::string binary_ip = ipv4_to_bin("192.168.55.1");
    std::cout << "Binary of 192.168.55.1: " << binary_ip << std::endl;

    std::string original_ip = bin_to_ipv4(binary_ip);
    std::cout << "Converted back to IP: " << original_ip << std::endl;
}
