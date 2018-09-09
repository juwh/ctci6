//
// Created by William Ju on 9/28/17.
//
#include <algorithm>
#include <iostream>
#include <string>

bool permutation(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return (s == t);
}

bool permutation_ascii(std::string s, std::string t) {
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

int main() {
    std::string pairs[3][2] {{"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}};
    for (auto &pair : pairs) {
        std::string word1 = pair[0];
        std::string word2 = pair[1];
        //bool anagram = permutation(word1, word2);
        bool anagram = permutation_ascii(word1, word2);
        std::cout << word1 << ", " << word2 << ": " << anagram << std::endl;
    }
    return 0;
}