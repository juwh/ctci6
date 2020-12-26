#ifndef PALINDROME_PERMUTATION_H_
#define PALINDROME_PERMUTATION_H_

#include <string>
#include <vector>

bool CheckMaxOneOdd(std::vector<int> table);
int GetCharNumber(char c);
std::vector<int> BuildCharFrequencyTable(const std::string& phrase);
bool IsPermutationOfPalindrome(const std::string& phrase);
bool IsPermutationOfPalindromeOpt(const std::string& phrase);
int Toggle(int bit_vector, int index);
int CreateBitVector(const std::string& phrase);
bool CheckExactlyOneBitSet(int bit_vector);
bool IsPermutationOfPalindromeBit(const std::string& phrase);

#endif  // PALINDROME_PERMUTATION_H_