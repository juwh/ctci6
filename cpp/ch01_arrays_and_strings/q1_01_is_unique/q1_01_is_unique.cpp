//
// Created by William Ju on 9/26/17.
//
#include <string>
#include <vector>
#include <iostream>
#include <bitset>

bool isUniqueChars(const std::string &str) {
    if (str.length() > 128) {
        return false;
    }
    std::vector<bool> char_set(128);
    for (char c : str) {
        int val = c;
        if (char_set[val]) {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main () {
    std::string words [] = {"abcde", "hello", "apple", "kite", "padle"};
    for (const std::string &word : words) {
        std::cout << word << ": " << isUniqueChars(word) << std::endl;
    }
    return 0;
}