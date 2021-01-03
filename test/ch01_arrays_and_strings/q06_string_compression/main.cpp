#pragma region Interview Question
/*
1.6 String Compression: Implement a method to perform basic string compression using the
counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than the original string, your method
should return the original string. You can assume the string has only uppercase and
lowercase letters (a-z).
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#92. Do the easy thing first. Compress the string, compare the lengths

#110. Be careful that you aren't repeatedly concatenating strings together. This can be
very inefficient.
*/
#pragma endregion

#include "arrays_and_strings/string_compression.h"

#include <iostream>

int main() {
    std::string str = "aaaaabbbbaaaabbddc";
    std::cout << str << std::endl;
    std::cout << CompressBad(str) << std::endl;
    std::cout << Compress(str) << std::endl;
    std::cout << CompressAdvanced(str) << std::endl;
	return 0;
}