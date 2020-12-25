#include "arrays_and_strings/urlify.h"

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