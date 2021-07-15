#pragma region Interview Question
/*
1.9 String Rotation: Assume you have a method IsSubstring which checks if one word is a
substring of another. Given two strings, s1 and s2, write code to check if s2 is a
rotation of s1 using only one call to IsSubstring (e.g., "waterbottle" is a rotation of
"erbottlewat").
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#34. If a string is a rotation of another, then it's a rotation at a particular point.
For example, a rotation of waterbottle at character 3 means cutting waterbottle at 
character 3 and putting the right half (erbottle) before the left half (wat).

#88. We are essentially asking if there's a way of splitting the first string into two
parts, x and y, such that the first string is xy and the second string is yx. For
example, x = wat and y = erbottle. The first string is xy = waterbottle. The second
string is yx = erbottlewat.

#104. Think about the earlier hint. Then think about what happens when you concatenate
erbottlewat to itself. You get erbottlewaterbottlewat.
*/
#pragma endregion

#include <iostream>
#include <string>
#include <vector>

bool IsSubstring(std::string big, std::string small) {
    return big.find(small) != std::string::npos;
}

bool IsRotation(std::string s1, std::string s2) {
    if (s1.length() == s2.length() && s1.length() != 0) {
        std::string combined{s2 + s2};
        return IsSubstring(combined, s1);
    }
    return false;
}

int main() {
    std::vector<std::vector<std::string>> pairs = {{"apple", "pleap"}, {"waterbottle", "erbottlewat"}, {"camera", "macera"}};
    for (std::vector<std::string> pair : pairs) {
        std::string word1 = pair[0];
        std::string word2 = pair[1];
        bool is_rotation = IsRotation(word1, word2);
        std::cout << word1 + ", " + word2 + ": " << is_rotation << std::endl;
    }
}