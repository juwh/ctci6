#pragma region Interview Question
/*
1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume 
that the string has sufficient space at the end to hold the additional characters, and
that you are given the "true" length of the string. (Note: If implementing in Java,
please use a character array so that you can perform this operation in place.)

EXAMPLE
Input:	"Mr John Smith    ", 13
Output:	"Mr%20John%20Smith"
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#53. It's often easiest to modify strings by going from the end of the string to the
beginning.

#118. You might find you need to know the number of spaces. Can you just count them?
*/
#pragma endregion

#include "arrays_and_strings/urlify.h"

#include <iostream>

int main() {
    char arr[] = "Mr John Smith    ";
    int true_length = FindLastCharacter(arr) + 1;
	ReplaceSpaces(arr, true_length);
    std::cout << "\"" << arr << "\"" << std::endl;
	return 0;
}