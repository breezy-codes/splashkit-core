//
//  basics.cpp
//  splashkit
//
//  Created by Andrew Cain on 3/6/17.
//  Copyright © 2017 Andrew Cain. All rights reserved.
//

#include "basics.h"

#include <algorithm>
#include <cstdlib>

#include <functional>
#include <cctype>
#include <locale>
using std::to_string;

namespace splashkit_lib
{
    const string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // trim see: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

    // trim from start
    string ltrim(const string &text)
    {
        string s = text;
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) { return !std::isspace(c);}));
        return s;
    }

    // trim from end
    string rtrim(const string &text)
    {
        string s = text;
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c);}).base(), s.end());
        return s;
    }

    // trim from both ends
    string trim(const string &text)
    {
        return ltrim(rtrim(text));
    }

    string to_lowercase(const string &text)
    {
        string data = text;
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        return data;
    }

    string to_uppercase(const string &text)
    {
        string data = text;
        std::transform(data.begin(), data.end(), data.begin(), ::toupper);
        return data;
    }

    int length_of(const string &text)
    {
        return text.length();
    }

    bool contains(const string &text, const string &subtext)
    {
        return index_of(text, subtext) != -1;
    }

    int index_of(const string &text, const string &subtext)
    {
        size_t pos = text.find(subtext);
        if (pos == string::npos)
            return -1;
        return static_cast<int>(pos);
    }

    string replace_all(const string &text, const string &substr, const string &replacement)
    {
        if (substr.empty())
            return text;
        
        string result = text;
        size_t pos = 0;
        while ((pos = result.find(substr, pos)) != string::npos)
        {
            result.replace(pos, substr.length(), replacement);
            pos += replacement.length();
        }
        return result;
    }

    vector<string> split(const string &text, char delimiter)
    {
        vector<string> result;
        string::size_type start = 0;
        string::size_type end = text.find(delimiter);
        while (end != string::npos)
        {
            result.push_back(text.substr(start, end - start));
            start = end + 1;
            end = text.find(delimiter, start);
        }
        result.push_back(text.substr(start));
        return result;
    }

    // integer check see: https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int#2845275

    bool is_integer(const string &text)
    {
        string s = trim(text);
        if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
        
        char * p;
        strtol(s.c_str(), &p, 10);
        
        return (*p == 0);
    }

    bool is_double(const string &text)
    {
        return is_number(text);
    }

    bool is_number(const string &text)
    {
        string s = trim(text);
        if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
        
        char * p;
        strtod(s.c_str(), &p);
        
        return (*p == 0);
    }

    int convert_to_integer(const string &text)
    {
        return std::stoi( text );
    }

    double convert_to_double(const string &text)
    {
        return std::stod( text );
    }


    // Convert decimal to binary string
    string dec_to_bin(unsigned int a_dec)
    {
        // Without this check, dec to bin will not work if dec is 0
        if (a_dec == 0)
            return "0";

        string bin_string;
        while (a_dec > 0)
        {
            bin_string = ((a_dec & 1) ? "1" : "0") + bin_string;
            a_dec >>= 1;
        }
        return bin_string;
    }

    // Convert binary string to decimal (unsigned integer)
    unsigned int bin_to_dec(const string &bin_str)
    {
        unsigned int result = 0;
        for (size_t i = 0; i < bin_str.size(); i++)
        {
            if (bin_str[i] == '1')
            {
                result += (1 << (bin_str.size() - i - 1));
            }
        }
        return result;
    }

    // Convert hexadecimal string to binary string
    string hex_to_bin(const string &hex_str)
    {

        string bin_string;
        for (char hex_char : hex_str)
        {
            int hex_val = 0;

            if (hex_char >= '0' && hex_char <= '9')
                hex_val = hex_char - '0';
            else if (hex_char >= 'A' && hex_char <= 'F')
                hex_val = hex_char - 'A' + 10;
            else if (hex_char >= 'a' && hex_char <= 'f')
                hex_val = hex_char - 'a' + 10;

            for (int i = 3; i >= 0; i--)
            {
                bin_string += ((hex_val >> i) & 1) ? '1' : '0';
            }
        }

        if (hex_str.length() == 1)
        {
            size_t first_one = bin_string.find_first_not_of('0');
            return (first_one == string::npos) ? "0" : bin_string.substr(first_one);
        }

        return bin_string;
    }

    // Convert binary string to hexadecimal string
    string bin_to_hex(const string &bin_str)
    {
        string hex_string;
        int length = bin_str.length();

        int padding = (4 - (length % 4)) % 4;
        string padded_bin_str = string(padding, '0') + bin_str;

        for (size_t i = 0; i < padded_bin_str.length(); i += 4)
        {
            int hex_val = 0;
            for (size_t j = 0; j < 4; j++)
            {
                hex_val <<= 1;
                if (padded_bin_str[i + j] == '1')
                    hex_val |= 1;
            }

            if (hex_val < 10)
                hex_string += '0' + hex_val;
            else
                hex_string += 'A' + (hex_val - 10);
        }
        return hex_string;
    }

    // Function to encode a string to Base64
    string base64_encode(const string &input)
    {
        string encoded;
        int val = 0, bits = -6;
        const unsigned int b63 = 0x3F;

        for (unsigned char c : input)
        {
            val = (val << 8) + c;
            bits += 8;

            while (bits >= 0)
            {
                encoded.push_back(BASE64_CHARS[(val >> bits) & b63]);
                bits -= 6;
            }
        }

        if (bits > -6)
        {
            encoded.push_back(BASE64_CHARS[((val << 8) >> (bits + 8)) & b63]);
        }

        while (encoded.size() % 4)
        {
            encoded.push_back('='); // Padding to make the length a multiple of 4
        }

        return encoded;
    }

    // Function to decode a Base64 encoded string
    string base64_decode(const string &input)
    {
        string decoded;
        int val = 0, bits = -8;
        for (unsigned char c : input)
        {
            if (BASE64_CHARS.find(c) == string::npos)
            {
                if (c == '=')
                    break; // Padding character, stop decoding
                continue;  // Ignore any characters not in Base64 alphabet
            }

            val = (val << 6) + BASE64_CHARS.find(c);
            bits += 6;

            if (bits >= 0)
            {
                decoded.push_back(char((val >> bits) & 0xFF));
                bits -= 8;
            }
        }
        return decoded;
    }

    // Convert decimal (unsigned integer) to octal string
    string dec_to_oct(unsigned int decimal_value)
    {
        if (decimal_value == 0)
            return "0";

        string octal_string;
        while (decimal_value > 0)
        {
            octal_string = to_string(decimal_value % 8) + octal_string;
            decimal_value /= 8;
        }
        return octal_string;
    }

    // Convert octal string to decimal (unsigned integer)
    unsigned int oct_to_dec(const string &octal_string)
    {
        unsigned int decimal_value = 0;
        for (size_t i = 0; i < octal_string.size(); i++)
        {
            decimal_value = decimal_value * 8 + (octal_string[i] - '0');
        }
        return decimal_value;
    }
}
