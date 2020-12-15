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

#include <iostream>
#include <string>

void ReplaceSpaces(char* str, int true_length) {
    int space_count = 0, index;
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
			space_count++;
        }
    }
    index = true_length + 2 * space_count - 1;
    for (int j = true_length - 1; j >= 0; j--) {
        if (str[j] == ' ') {
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
        } else {
            str[index--] = str[j];
        }
    }
}

int FindLastCharacter(std::string str) {
    for (int i = (int)str.length() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            return i;
        }
    }
    return -1;
}

int main() {
    char arr[] = "Mr John Smith    ";
    int true_length = FindLastCharacter(arr) + 1;
	ReplaceSpaces(arr, true_length);
    std::cout << "\"" << arr << "\"" << std::endl;
	return 0;
}