#pragma region Interview Question
/*
1.1 Is Unique: Implement an algorithm to determine if a string has all unique 
characters. What if you cannot use additional data structures?
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#44. Try a hash table

#117. Could a bit vector be useful?

#132. Can you solve it in O(N log N) time? What might a solution like that look like?
*/
#pragma endregion

#include "is_unique.h"
#include <iostream>
#include <string>

int main() {
    std::string words [] = {"abcde", "hello", "apple", "kite", "padle"};
    for (const std::string &word : words) {
        //std::cout << word << ": " << isUniqueCharsSort(word) << std::endl;
        //std::cout << word << ": " << isUniqueCharsManual(word) << std::endl;
        //std::cout << word << ": " << isUniqueChars(word) << std::endl;
        //std::cout << word << ": " << isUniqueCharsBit(word) << std::endl;
        bool wordA =  IsUniqueChars(word);
        bool wordB =  IsUniqueCharsBit(word);
        if (wordA == wordB) {
            std::cout << word << ": " << wordA << std::endl;
        } else {
            std::cout << word << ": " << wordA << " vs " << wordB << std::endl;
        }
    }
    return 0;
}