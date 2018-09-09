//
// Created by William Ju on 10/6/17.
//
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool oneEditReplace(std::string s1, std::string s2) {
    bool foundDifference = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditInsert(std::string s1, std::string s2) {
    int index1 = 0;
    int index2 = 0;
    while (index2 < s2.length() && index1 < s1.length()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(std::string first, std::string second) {
    if (first.length() == second.length()) {
        return oneEditReplace(first, second);
    } else {
        if (first.length() + 1 == second.length()) {
            return oneEditInsert(first, second);
        } else {
            if (first.length() == second.length() +1) {
                return oneEditInsert(second, first);
            }
        }
    }
    return false;
}

bool oneEditAwayMerged(std::string first, std::string second) {
    if (std::fabs((int)first.length() - (int)second.length()) > 1) {
        return false;
    }

    std::string s1 = first.length() < second.length() ? first : second;
    std::string s2 = first.length() < second.length() ? second : first;

    int index1 = 0;
    int index2 = 0;
    bool foundDifference = false;
    while (index2 < s2.length() && index1 < s1.length()) {
        if (s1[index1] != s2[index2]) {
            if (foundDifference) {
                return false;
            }
            foundDifference = true;

            if (s1.length() == s2.length()) {
                index1++;
            }
        } else {
            index1++;
        }
        index2++;
    }
    return true;
}

void test(const std::string& a, const std::string& b, bool expected) {
    bool resultA = oneEditAwayMerged(a, b);
    bool resultB = oneEditAwayMerged(a, b);

    if (resultA == expected && resultB == expected) {
        std::cout << a << ", " << b << ": success" << std::endl;
    } else {
        std::cout << a << ", " << b << ": error" << std::endl;
    }
}

int main() {
    std::vector< std::vector<std::string> > tests = {
                        {"a", "b", "true"},
                        {"", "d", "true"},
                        {"d", "de", "true"},
                        {"pale", "pse", "false"},
                        {"acdsfdsfadsf", "acdsgdsfadsf", "true"},
                        {"acdsfdsfadsf", "acdsfdfadsf", "true"},
                        {"acdsfdsfadsf", "acdsfdsfads", "true"},
                        {"acdsfdsfadsf", "cdsfdsfadsf", "true"},
                        {"adfdsfadsf", "acdfdsfdsf", "false"},
                        {"adfdsfadsf", "bdfdsfadsg", "false"},
                        {"adfdsfadsf", "affdsfads", "false"},
                        {"pale", "pkle", "true"},
                        {"pkle", "pable", "false"} };
    for (int i = 0; i < tests.size(); i++) {
        std::vector<std::string> single_test = tests[i];
        std::string a = single_test[0];
        std::string b = single_test[1];
        bool expected = single_test[2] == "true";

        test(a, b, expected);
        test(b, a, expected);
    }
}