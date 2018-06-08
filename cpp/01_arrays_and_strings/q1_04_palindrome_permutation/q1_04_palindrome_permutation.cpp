//
// Created by William Ju on 10/3/17.
//
#include <iostream>
#include <string>
#include <vector>

bool checkMaxOneOdd(std::vector<int> table) {
    bool foundOdd = false;
    for (auto count : table) {
        if (count % 2 == 1) {
            if (foundOdd) {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

int getCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = c;
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

std::vector<int> buildCharFrequencyTable(const std::string& phrase) {
    std::vector<int> table((int)'z' - (int)'a' + 1);
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

bool isPermutationOfPalindrome(const std::string& phrase) {
    // palindrome has even letters for all but one, can set up static array for ASCII and check
    // even for all
    std::vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

bool isPermutationOfPalindromeOpt(const std::string& phrase) {
    int countOdd = 0;
    std::vector<int> table((int)'z' - (int)'a' + 1);
    for (char c : phrase) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
            if (table[x] % 2 == 1) {
                countOdd++;
            } else {
                countOdd--;
            }
        }
    }
    return countOdd <= 1;
}

int toggle(int bitVector, int index) {
    if (index < 0) {
        return bitVector;
    }

    int mask = 1 << index;
    if ((bitVector & mask) == 0) {
        bitVector |= mask;
    } else {
        bitVector &= ~mask;
    }
    return bitVector;
}

int createBitVector(const std::string& phrase) {
    int bitVector = 0;
    for (char c : phrase) {
        int x = getCharNumber(c);
        bitVector = toggle(bitVector, x);
    }
    return bitVector;
}

bool checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 0;
}

bool isPermutationOfPalindromeBit(const std::string& phrase) {
    int bitVector = createBitVector(phrase);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}

int main() {
    std::string strings[] {"Rats live on no evil star",
                        "A man, a plan, a canal, panama",
                        "Lleve",
                        "Tacotac",
                        "asda"};
    for (const std::string& s : strings) {
        bool a = isPermutationOfPalindrome(s);
        bool b = isPermutationOfPalindrome(s);
        bool c = isPermutationOfPalindrome(s);
        std::cout << s << std::endl;
        if (a == b && b == c) {
            std::cout << "Agree: " << a << std::endl;
        } else {
            std::cout << "Disagree: " << a << ", " << b << ", " << c << std::endl;
        }
    }
}