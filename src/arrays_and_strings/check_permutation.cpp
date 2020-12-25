#include "arrays_and_strings/check_permutation.h"

bool Permutation(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return (s == t);
}

bool PermutationAscii(std::string s, std::string t) {
    // Permutations must be same length
    if (s.length() != t.length()) {
        return false;
    }
    int letters[128]={0};
    for (char letter : s) {
        letters[(int)letter]++;
    }
    for (char letter : t) {
        letters[(int)letter]--;
        if (letters[(int)letter] < 0) {
            return false;
        }
    }
    return true;
}

bool PermutationUnorderedSet(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::unordered_map< char, int > letters;
    for (char letter : s) {
        letters[letter]++;
    }
    for (char letter : t) {
        letters[letter]--;
        if (letters[letter] < 0) {
            return false;
        }
    }
    return true;
}