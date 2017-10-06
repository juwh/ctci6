//
// Created by William Ju on 10/3/17.
//
#include <bitset>
#include <iostream>
#include <string>

bool isPermutationOfPalindrome(string phrase) {
    // palindrome has even letters for all but one, can set up static array for ASCII and check
    // even for all
}

bool checkMaxOneOdd(int* table) {

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

int* buildCharFrequencyTable(string phrase) {

}

bool isPermutationOfPalindromeOpt(string phrase) {

}

bool isPermutationOfPalindromeBit(string phrase) {

}

int createBitVector(string phrase) {
    int bitVector = 0;
    for (char c : phrase) {
        int x = getCharNumber(c);
        bitVector = toggle(bitVector, x);
    }
    return bitVector;
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

bool checkExactlyOneBitSet(int bitVector) {

}

int main() {
    string pali = "Ratzs live on no evil starz";
    std::cout << isPermutationOfPalindrome(pali) << std::endl;
    string pali2 = "Zeus was deified, saw Suez";
    std::cout << isPermutationOfPalindrome(pali2) << std::endl;
}