//
// Created by William Ju on 9/29/17.
//
#include <iostream>
#include <string>

void replaceSpaces(char* str, int trueLength) {
    int spaceCount = 0, index;
    for (int i = 0; i < trueLength; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    index = trueLength + 2 * spaceCount - 1;
    for (int j = trueLength - 1; j >= 0; j--) {
        if (str[j] == ' ') {
            str[index--] = '0';
            str[index--] = '2';
            str[index--] = '%';
        } else {
            str[index--] = str[j];
        }
    }
}

int findLastCharacter(std::string str) {
    for (int i = (int)str.length() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            return i;
        }
    }
    return -1;
}

int main() {
    char arr[] = "Mr John Smith    ";
    int trueLength = findLastCharacter(arr) + 1;
    replaceSpaces(arr, trueLength);
    std::cout << "\"" << arr << "\"" << std::endl;
}