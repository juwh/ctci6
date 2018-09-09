/*
1.6 String Compression: Implement a method to perform basic string compression using the
counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than the original string, your method
should return the original string. You can assume the string has only uppercase and
lowercase letters (a-z).

Hints: #23, #97, #130
*/
#include <iostream>
#include <sstream>
#include <string>

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
    int count_consecutive = 0;
    for (int i = 0; i < str.length(); i++) {
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
    int count_consecutive = 0;
    for (int i = 0; i < str.length(); i++) {
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
    int compressed_length = 0;
    int count_consecutive = 0;
    for (int i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
			compressed_length += 1 + std::to_string(count_consecutive).length();
        }
    }
    return compressed_length;
}

std::string CompressAdvanced(std::string str) {
    int final_length = CountCompression(str);
    if (final_length >= str.length()) {
        return str;
    }

    std::stringstream compressed;
    int count_consecutive = 0;
    for (int i = 0; i < str.length(); i++) {
		count_consecutive++;

        if (i + 1 >= str.length() || str[i] != str[i + 1]) {
            compressed << str[i];
            compressed << count_consecutive;
			count_consecutive = 0;
        }
    }
    return compressed.str();
}

int main() {
    std::string str = "aaaaabbbbaaaabbddc";
    std::cout << str << std::endl;
    std::cout << CompressBad(str) << std::endl;
    std::cout << Compress(str) << std::endl;
    std::cout << CompressAdvanced(str) << std::endl;
	return 0;
}