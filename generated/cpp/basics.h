//
// SplashKit Generated Basics C++ Code
// DO NOT MODIFY
//

#ifndef __basics_h
#define __basics_h

#include <string>
#include <vector>
#include <cstdint>
using std::string;
using std::vector;

string base64_decode(const string &input);
string base64_encode(const string &input);
unsigned int bin_to_dec(const string &bin);
string bin_to_hex(const string &bin_str);
bool contains(const string &text, const string &subtext);
double convert_to_double(const string &text);
int convert_to_integer(const string &text);
string dec_to_bin(unsigned int dec);
string dec_to_oct(unsigned int decimal_value);
string hex_to_bin(const string &hex_str);
int index_of(const string &text, const string &subtext);
bool is_double(const string &text);
bool is_integer(const string &text);
bool is_number(const string &text);
int length_of(const string &text);
unsigned int oct_to_dec(const string &octal_string);
string replace_all(const string &text, const string &substr, const string &newText);
vector<string> split(const string &text, char delimiter);
string to_lowercase(const string &text);
string to_uppercase(const string &text);
string trim(const string &text);

#endif /* __basics_h */
