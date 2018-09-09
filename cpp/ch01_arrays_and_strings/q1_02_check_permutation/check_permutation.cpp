#pragma region Interview Question
/*
1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation 
of the other.
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#1. Describe what it means for two strings to be permutations of each other. Now, look at
that definition you provided. Can you check the strings against that definition?

#84. There is one solution that is O(N log N) time. Another solution uses some space, but
is O(N) time.

#122. Could a hash table be useful?

#131. Two strings that are permutations should have the same characters, but in different
orders. Can you make the orders the same?
*/
#pragma endregion

#include <algorithm>
#include <iostream>
#include <string>

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

int main() {
    std::string pairs[3][2] {{"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}};
    for (auto &pair : pairs) {
        std::string word1 = pair[0];
        std::string word2 = pair[1];
        //bool anagram = Permutation(word1, word2);
        bool anagram = PermutationAscii(word1, word2);
        std::cout << word1 << ", " << word2 << ": " << anagram << std::endl;
    }
    return 0;
}