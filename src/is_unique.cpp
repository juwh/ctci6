#include "is_unique.h"

bool IsUniqueChars(const std::string &str) {
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

bool IsUniqueCharsBit(const std::string &str) {
    //Reduce space usage by a factor of 8 using bitvector.
    //Each boolean otherwise occupies a size of 8 bits.
    std::bitset<256> checker(0);
    for (char c : str) {
        int val = c;
        if (checker.test((size_t)val) > 0) {
            return false;
        }
        checker.set((size_t)val);
    }
    return true;
}

bool IsUniqueCharsManual(const std::string &str) {
    for (int i = 0; i < str.length()-1; i++) {
        for (int j = i+1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

bool IsUniqueCharsSort(std::string str) {
    std::sort(str.begin(), str.end());
    for (int i = 0; i < str.length()-1; i++) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}