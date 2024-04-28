#include "ToString.hpp"
#include "Windows.h"

namespace ToString
{
    std::string Error(const int errorCode)
    {
        constexpr int bufferSize = 512;
        CHAR messageBuffer[bufferSize];
        int charsReturned;

        // Try to get the message from the system errors
        charsReturned = FormatMessageA(
            FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr,
            errorCode,
            0,
            messageBuffer,
            bufferSize,
            nullptr
        );

        if (charsReturned == 0)
        {
            // The error code did not exist in the system errors, try Ntdsbmsg.dll
            HINSTANCE hNtdsbmsg = LoadLibraryA("Ntdsbmsg.dll");
            if (hNtdsbmsg)
            {
                charsReturned = FormatMessageA(
                    FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS,
                    hNtdsbmsg,
                    errorCode,
                    0,
                    messageBuffer,
                    bufferSize,
                    nullptr
                );

                FreeLibrary(hNtdsbmsg);

                if (charsReturned == 0)
                {
                    return "Could not retrieve error message.";
                }
            }
        }

        return std::string(messageBuffer, charsReturned);
    }

    static const CHAR s_NumberToCharacter[16]
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    constexpr int BIT_FACTOR = 8;
    constexpr int BIT_SIZE = 1;
    constexpr int NIBBLE_FACTOR = 2;
    constexpr int NIBBLE_SIZE = 4;
    constexpr int HYPHEN_SIZE = 1;

    static constexpr int GetNumberMask(int bitSize)
    {
        int mask = 0;
        for (int i = 0; i < bitSize; i++)
        {
            mask <<= 1;
            mask |= 1;
        }
        return mask;
    }

    static inline void WriteNumToBuffer(LPSTR buffer, int bufferSize, long long number, const int bitSize)
    {
        int mask = GetNumberMask(bitSize);
        for (int i = bufferSize; i > 0;)
        {
            int value = number & mask;
            buffer[--i] = s_NumberToCharacter[value];
            number >>= bitSize;
        }
    }

    template<unsigned int bitSize, int charFactor>
    static inline std::string NumberToString(const long long number, const int size)
    {
        constexpr int maxSize = sizeof(number) * charFactor;
        CHAR buffer[maxSize]{ };
        int bufferSize = size <= sizeof(number) ? size * charFactor : maxSize;

        WriteNumToBuffer(buffer, bufferSize, number, bitSize);

        return std::string(buffer, bufferSize);
    }

    template<unsigned int bitSize, int charFactor>
    static inline std::string ArrayToString(const unsigned char data[], const int length)
    {
        if (!data || length == 0)
        {
            return "";
        }

        const int bufferLength = length * (charFactor + HYPHEN_SIZE);
        const LPSTR buffer = (LPSTR)malloc(bufferLength);

        int bufferIndex = 0;
        for (int dataIndex = 0; dataIndex < length; dataIndex++)
        {
            WriteNumToBuffer(buffer + bufferIndex, (sizeof(data[0]) * charFactor), data[dataIndex], bitSize);
            bufferIndex += charFactor;
            buffer[bufferIndex] = '-';
            bufferIndex += HYPHEN_SIZE;
        }

        std::string string(buffer, bufferLength - HYPHEN_SIZE);
        free(buffer);
        return string;
    }

    static inline std::string Binary(const long long number, const int size)
    {
        return NumberToString<BIT_SIZE, BIT_FACTOR>(number, size);
    }

    std::string Binary(const long long number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const long number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const int number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const short number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const signed char number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned long long number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned long number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned int number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned short number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned char number)
    {
        return Binary(number, sizeof(number));
    }

    std::string Binary(const unsigned char data[], const int length)
    {
        return ArrayToString<BIT_SIZE, BIT_FACTOR>(data, length);
    }

    static std::string Hex(const long long number, const int length)
    {
        return NumberToString<NIBBLE_SIZE, NIBBLE_FACTOR>(number, length);
    }

    std::string Hex(const long long number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const long number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const int number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const short number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const char number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned long long number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned long number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned int number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned short number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned char number)
    {
        return Hex(number, sizeof(number));
    }

    std::string Hex(const unsigned char data[], const int length)
    {
        return ArrayToString<NIBBLE_SIZE, NIBBLE_FACTOR>(data, length);
    }

    std::string Guid(const GUID& guid)
    {
        constexpr int bufferSize =
            (sizeof(guid.Data1) * NIBBLE_FACTOR) + HYPHEN_SIZE +
            (sizeof(guid.Data2) * NIBBLE_FACTOR) + HYPHEN_SIZE +
            (sizeof(guid.Data3) * NIBBLE_FACTOR) + HYPHEN_SIZE +
            (sizeof(guid.Data4) * NIBBLE_FACTOR) + HYPHEN_SIZE;
        CHAR buffer[bufferSize]{ };
        int bufferIndex = 0;

        // Data1
        WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data1) * NIBBLE_FACTOR, guid.Data1, NIBBLE_SIZE);
        bufferIndex += NIBBLE_FACTOR;
        buffer[bufferIndex] = '-';
        bufferIndex += HYPHEN_SIZE;

        // Data2
        WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data2) * NIBBLE_FACTOR, guid.Data2, NIBBLE_SIZE);
        bufferIndex += NIBBLE_FACTOR;
        buffer[bufferIndex] = '-';
        bufferIndex += HYPHEN_SIZE;

        // Data3
        WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data3) * NIBBLE_FACTOR, guid.Data3, NIBBLE_SIZE);
        bufferIndex += NIBBLE_FACTOR;
        buffer[bufferIndex] = '-';
        bufferIndex += HYPHEN_SIZE;

        // Data4[0..1]
        WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data4[0]) * NIBBLE_FACTOR, guid.Data4[0], NIBBLE_SIZE);
        bufferIndex += NIBBLE_FACTOR;
        WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data4[1]) * NIBBLE_FACTOR, guid.Data4[1], NIBBLE_SIZE);
        bufferIndex += NIBBLE_FACTOR;
        buffer[bufferIndex] = '-';
        bufferIndex += HYPHEN_SIZE;

        // Data4[2..7]
        for (int i = 2; i < sizeof(guid.Data4); i++)
        {
            WriteNumToBuffer(buffer + bufferIndex, sizeof(guid.Data4[i]) * NIBBLE_FACTOR, guid.Data4[i], NIBBLE_SIZE);
            bufferIndex += NIBBLE_FACTOR;
        }

        return std::string(buffer, bufferSize);
    }
}