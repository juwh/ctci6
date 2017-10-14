//
// Created by William Ju on 10/7/17.
//
#include <iostream>
#include <sstream>
#include <string>

std::string compressBad(std::string str) {
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

    std::string compressedString;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressedString += str[i];
            compressedString += std::to_string(countConsecutive);
            countConsecutive = 0;
        }
    }
    return compressedString.length() < str.length() ? compressedString : str;
}

// not necessarily better as C++ strings are mutable
std::string compress(std::string str) {
    std::stringstream compressed;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i];
            compressed << countConsecutive;
            countConsecutive = 0;
        }
    }
    return compressed.str().length() < str.length() ?
           compressed.str() : str;
}

int countCompression(std::string str) {
    int compressedLength = 0;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressedLength += 1 + std::to_string(countConsecutive).length();
        }
    }
    return compressedLength;
}

std::string compressAdvanced(std::string str) {
    int finalLength = countCompression(str);
    if (finalLength >= str.length()) {
        return str;
    }

    std::stringstream compressed;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++) {
        countConsecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i];
            compressed << countConsecutive;
            countConsecutive = 0;
        }
    }
    return compressed.str();
}

int main() {
    std::string str = "aaaaabbbbaaaabbddc";
    std::cout << str << std::endl;
    std::cout << compressBad(str) << std::endl;
    std::cout << compress(str) << std::endl;
    std::cout << compressAdvanced(str) << std::endl;

}