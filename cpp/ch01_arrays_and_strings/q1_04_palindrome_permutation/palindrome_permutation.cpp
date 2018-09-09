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

#include <iostream>
#include <string>
#include <vector>

bool CheckMaxOneOdd(std::vector<int> table) {
    bool found_odd = false;
    for (auto count : table) {
        if (count % 2 == 1) {
            if (found_odd) {
                return false;
            }
			found_odd = true;
        }
    }
    return true;
}

int GetCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = c;
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

std::vector<int> BuildCharFrequencyTable(const std::string& phrase) {
    std::vector<int> table((int)'z' - (int)'a' + 1);
    for (char c : phrase) {
        int x = GetCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

bool IsPermutationOfPalindrome(const std::string& phrase) {
    // palindrome has even letters for all but one, can set up static array for ASCII and 
	//check even for all
    std::vector<int> table = BuildCharFrequencyTable(phrase);
    return CheckMaxOneOdd(table);
}

bool IsPermutationOfPalindromeOpt(const std::string& phrase) {
    int count_odd = 0;
    std::vector<int> table((int)'z' - (int)'a' + 1);
    for (char c : phrase) {
        int x = GetCharNumber(c);
        if (x != -1) {
            table[x]++;
            if (table[x] % 2 == 1) {
				count_odd++;
            } else {
				count_odd--;
            }
        }
    }
    return count_odd <= 1;
}

int Toggle(int bit_vector, int index) {
    if (index < 0) {
        return bit_vector;
    }

    int mask = 1 << index;
    if ((bit_vector & mask) == 0) {
		bit_vector |= mask;
    } else {
		bit_vector &= ~mask;
    }
    return bit_vector;
}

int CreateBitVector(const std::string& phrase) {
    int bit_vector = 0;
    for (char c : phrase) {
        int x = GetCharNumber(c);
		bit_vector = Toggle(bit_vector, x);
    }
    return bit_vector;
}

bool CheckExactlyOneBitSet(int bit_vector) {
    return (bit_vector & (bit_vector - 1)) == 0;
}

bool IsPermutationOfPalindromeBit(const std::string& phrase) {
    int bit_vector = CreateBitVector(phrase);
    return bit_vector == 0 || CheckExactlyOneBitSet(bit_vector);
}

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