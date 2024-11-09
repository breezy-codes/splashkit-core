#include "window_manager.h"
#include "networking.h"

#include "assert.h"
#include <iostream>
#include <sstream>
#include <string>

#define TEST_IP "127.0.0.1"
#define TEST_IP_HEX "0x7F000001"
#define TEST_DEC 10
#define TEST_BIN "1010"
#define TEST_HEX "FF"
#define TEST_MAC "01:23:45:67:89:AB"
#define TEST_MAC_HEX "0x0123456789AB"

using namespace splashkit_lib;

void ipv4_to_dec_test()
{
    assert(ipv4_to_dec("0.0.0.0") == 0);                  // Zero case
    assert(ipv4_to_dec("1.1.1.1") == 16843009);           // Public DNS IP
    assert(ipv4_to_dec("8.8.8.8") == 134744072);          // Google DNS IP
    assert(ipv4_to_dec("10.0.0.1") == 167772161);         // Private IP
    assert(ipv4_to_dec("172.16.254.1") == 2886794753);    // Class B private IP
    assert(ipv4_to_dec("192.168.1.1") == 3232235777);     // Private IP
    assert(ipv4_to_dec("255.255.255.255") == 4294967295); // Max 32-bit value

    unsigned int result = ipv4_to_dec(TEST_IP);
    assert(result == 2130706433);

    std::cout << "All IPv4 to Decimal tests passed!\n"
              << TEST_IP << " in decimal: " << result << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ipv4_to_str_test()
{
    assert(ipv4_to_str(0) == "0.0.0.0");                  // Zero case
    assert(ipv4_to_str(16843009) == "1.1.1.1");           // Public DNS IP
    assert(ipv4_to_str(134744072) == "8.8.8.8");          // Google DNS IP
    assert(ipv4_to_str(167772161) == "10.0.0.1");         // Private IP
    assert(ipv4_to_str(3232235777) == "192.168.1.1");     // Private IP
    assert(ipv4_to_str(2886794753) == "172.16.254.1");    // Class B private IP
    assert(ipv4_to_str(4294967295) == "255.255.255.255"); // Max 32-bit value

    std::string result = ipv4_to_str(2130706433);
    assert(result == TEST_IP);

    std::cout << "All IPv4 to String tests passed!\n"
              << 2130706433 << " in IP format: " << result << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ipv4_to_hex_test()
{
    assert(ipv4_to_hex("0.0.0.0") == "0x00000000");         // Zero case
    assert(ipv4_to_hex("1.1.1.1") == "0x01010101");         // Additional public DNS IP
    assert(ipv4_to_hex("8.8.8.8") == "0x08080808");         // Google DNS IP
    assert(ipv4_to_hex("10.0.0.1") == "0x0A000001");        // Private IP
    assert(ipv4_to_hex("127.0.0.1") == "0x7F000001");       // Localhost
    assert(ipv4_to_hex("192.168.1.1") == "0xC0A80101");     // Private IP
    assert(ipv4_to_hex("255.255.255.255") == "0xFFFFFFFF"); // Max 32-bit value

    std::string result = ipv4_to_hex(TEST_IP);
    assert(result == TEST_IP_HEX);

    std::cout << "All IPv4 to Hexadecimal tests passed!\n"
              << TEST_IP << " in hex: " << result << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void hex_str_to_ipv4_test()
{
    assert(hex_str_to_ipv4("0x00000000") == "0.0.0.0");         // Zero case
    assert(hex_str_to_ipv4("0x0A000001") == "10.0.0.1");        // Private IP
    assert(hex_str_to_ipv4("0x08080808") == "8.8.8.8");         // Google DNS IP
    assert(hex_str_to_ipv4("0x7F000001") == "127.0.0.1");       // Localhost
    assert(hex_str_to_ipv4("0xC0A80101") == "192.168.1.1");     // Private IP
    assert(hex_str_to_ipv4("0xFFFFFFFF") == "255.255.255.255"); // Max 32-bit value

    std::string result = hex_str_to_ipv4(TEST_IP_HEX);
    assert(result == TEST_IP);

    std::cout << "All Hexadecimal to IPv4 tests passed!\n"
              << TEST_IP_HEX << " in IP format: " << result << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void mac_to_hex_test()
{
    assert(mac_to_hex("00:00:00:00:00:00") == "0x000000000000");
    assert(mac_to_hex("FF:FF:FF:FF:FF:FF") == "0xFFFFFFFFFFFF");
    assert(mac_to_hex("12:34:56:78:9A:BC") == "0x123456789ABC");
    assert(mac_to_hex(TEST_MAC) == TEST_MAC_HEX);

    std::string result = mac_to_hex("AB:CD:EF:12:34:56");
    assert(result == "0xABCDEF123456");

    std::cout << "All MAC to Hexadecimal tests passed!\n"
              << "AB:CD:EF:12:34:56" << " in hex: " << result << std::endl;
}

void hex_to_mac_test()
{
    assert(hex_to_mac("0x000000000000") == "00:00:00:00:00:00");
    assert(hex_to_mac("0xFFFFFFFFFFFF") == "FF:FF:FF:FF:FF:FF");
    assert(hex_to_mac("0x123456789ABC") == "12:34:56:78:9A:BC");

    std::string result = hex_to_mac(TEST_MAC_HEX);
    assert(result == TEST_MAC);

    std::cout << "All Hexadecimal to MAC tests passed!\n"
              << TEST_MAC_HEX << " in MAC format: " << result << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void is_valid_ip_test()
{
    // Valid IP addresses - should return true
    assert(is_valid_ipv4("192.168.1.1") == true);     // Common private IP
    assert(is_valid_ipv4("127.0.0.1") == true);       // Localhost
    assert(is_valid_ipv4("8.8.8.8") == true);         // Google DNS
    assert(is_valid_ipv4("255.255.255.255") == true); // Maximum values
    assert(is_valid_ipv4("0.0.0.0") == true);         // Minimum values
    assert(is_valid_ipv4("172.16.254.1") == true);    // Valid class B private IP
    assert(is_valid_ipv4("10.0.0.1") == true);        // Valid class A private IP

    // Invalid IP addresses - should return false
    assert(is_valid_ipv4("256.1.2.3") == false);       // First octet > 255
    assert(is_valid_ipv4("1.256.2.3") == false);       // Second octet > 255
    assert(is_valid_ipv4("1.2.256.3") == false);       // Third octet > 255
    assert(is_valid_ipv4("1.2.3.256") == false);       // Fourth octet > 255
    assert(is_valid_ipv4("192.168.1") == false);       // Missing octet
    assert(is_valid_ipv4("192.168.1.1.1") == false);   // Too many octets
    assert(is_valid_ipv4("192.168.1.") == false);      // Trailing dot
    assert(is_valid_ipv4(".192.168.1") == false);      // Leading dot
    assert(is_valid_ipv4("192.168..1") == false);      // Empty octet
    assert(is_valid_ipv4("192.168.1.1a") == false);    // Invalid character
    assert(is_valid_ipv4("") == false);                // Empty string
    assert(is_valid_ipv4("abc.def.ghi.jkl") == false); // Letters
    assert(is_valid_ipv4("192,168,1,1") == false);     // Wrong separator

    std::cout << "All IP validation tests passed!" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void run_networking_test()
{
    ipv4_to_dec_test();
    ipv4_to_str_test();
    ipv4_to_hex_test();
    hex_str_to_ipv4_test();
    mac_to_hex_test();
    hex_to_mac_test();
    is_valid_ip_test();
}
