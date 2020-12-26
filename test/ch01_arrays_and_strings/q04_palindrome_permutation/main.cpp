#pragma region Interview Question
/*
1.4 Palindrome Permutation: Given a string, write a function to check if it is a
permutation of a palindrome. A palindrome is a word or phrase that is the same forwards
and backwards. A permutation is a rearrangement of letters. The palindrome does not need to
be limited to just dictionary words.

EXAMPLE
Input:	Tact Coa
Output:	True (permutations: "taco cat", "atco cta", etc.)
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#106. You might not have to-and should not-generate all permutations. This would be very
inefficient.

#121. What characteristics would a string that is a permutation of a palindrome have?

#134. Have you tried a hash table? You should be able to get this down to O(N) time.

#136. Can you reduce the space usage by using a bit vector?
*/
#pragma endregion

#include "arrays_and_strings/palindrome_permutation.h"

#include <iostream>

int main() {
    std::string strings[] {"Rats live on no evil star",
                        "A man, a plan, a canal, panama",
                        "Lleve",
                        "Tacotac",
                        "asda"};
    for (const std::string& s : strings) {
        bool a = IsPermutationOfPalindrome(s);
        bool b = IsPermutationOfPalindrome(s);
        bool c = IsPermutationOfPalindrome(s);
        std::cout << s << std::endl;
        if (a == b && b == c) {
            std::cout << "Agree: " << a << std::endl;
        } else {
            std::cout << "Disagree: " << a << ", " << b << ", " << c << std::endl;
        }
    }
	return 0;
}