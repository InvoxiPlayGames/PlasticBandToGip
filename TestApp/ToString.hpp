#include <guiddef.h>
#include <iostream>
#include <string>

namespace ToString
{
    // Turns the given data into a binary string.
    std::string Binary(const long long number);
    std::string Binary(const long number);
    std::string Binary(const int number);
    std::string Binary(const short number);
    std::string Binary(const signed char number);
    std::string Binary(const unsigned long long number);
    std::string Binary(const unsigned long number);
    std::string Binary(const unsigned int number);
    std::string Binary(const unsigned short number);
    std::string Binary(const unsigned char number);
    std::string Binary(const unsigned char data[], const int length);

    // Turns the given data into a hexadecimal string.
    std::string Hex(const long long number);
    std::string Hex(const long number);
    std::string Hex(const int number);
    std::string Hex(const short number);
    std::string Hex(const char number);
    std::string Hex(const unsigned long long number);
    std::string Hex(const unsigned long number);
    std::string Hex(const unsigned int number);
    std::string Hex(const unsigned short number);
    std::string Hex(const unsigned char number);
    std::string Hex(const unsigned char data[], const int length);

    // Retrieves the message for a given error code.
    std::string Error(const int errorCode);

    // Turns the given GUID into a standard-format string.
    std::string Guid(const GUID& guid);
}
