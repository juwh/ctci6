#include "arrays_and_strings/string_compression.h"

std::string CompressBad(std::string str) {
    /*
    char prev = str[0];
    std::string output;
    output += str[0];
    int count = 0;
    for (char c : str) {
        if (c != prev) {
            output += std::to_string(count);
            output += c;
            count = 1;
        } else {
            count++;
        }
        prev = c;
    }
    return output.length() < str.length() ? output : str;
     */

    std::string compressed_string;
    size_t count_consecutive = 0;
    for (size_t i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
			compressed_string += str[i];
			compressed_string += std::to_string(count_consecutive);
			count_consecutive = 0;
        }
    }
    return compressed_string.length() < str.length() ? compressed_string : str;
}

// not necessarily better as C++ strings are mutable
std::string Compress(std::string str) {
    std::stringstream compressed;
    size_t count_consecutive = 0;
    for (size_t i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i];
            compressed << count_consecutive;
			count_consecutive = 0;
        }
    }
    return compressed.str().length() < str.length() ?
           compressed.str() : str;
}

int CountCompression(std::string str) {
    size_t compressed_length = 0;
    size_t count_consecutive = 0;
    for (size_t i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
			compressed_length += 1 + std::to_string(count_consecutive).length();
        }
    }
    return compressed_length;
}

std::string CompressAdvanced(std::string str) {
    size_t final_length = CountCompression(str);
    if (final_length >= str.length()) {
        return str;
    }

    std::stringstream compressed;
    size_t count_consecutive = 0;
    for (size_t i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i];
            compressed << count_consecutive;
			count_consecutive = 0;
        }
    }
    return compressed.str();
}