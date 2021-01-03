#include "arrays_and_strings/one_away.h"

bool OneEditReplace(std::string s1, std::string s2) {
    bool found_difference = false;
    for (size_t i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (found_difference) {
                return false;
            }
			found_difference = true;
        }
    }
    return true;
}

bool OneEditInsert(std::string s1, std::string s2) {
    size_t index_1 = 0;
    size_t index_2 = 0;
    while (index_2 < s2.length() && index_1 < s1.length()) {
        if (s1[index_1] != s2[index_2]) {
            if (index_1 != index_2) {
                return false;
            }
			index_2++;
        } else {
			index_1++;
			index_2++;
        }
    }
    return true;
}

bool OneEditAway(std::string first, std::string second) {
    if (first.length() == second.length()) {
        return OneEditReplace(first, second);
    } else {
        if (first.length() + 1 == second.length()) {
            return OneEditInsert(first, second);
        } else {
            if (first.length() == second.length() +1) {
                return OneEditInsert(second, first);
            }
        }
    }
    return false;
}

bool OneEditAwayMerged(std::string first, std::string second) {
    if (std::fabs((int)first.length() - (int)second.length()) > 1) {
        return false;
    }

    std::string s1 = first.length() < second.length() ? first : second;
    std::string s2 = first.length() < second.length() ? second : first;

    size_t index_1 = 0;
    size_t index_2 = 0;
    bool found_difference = false;
    while (index_2 < s2.length() && index_1 < s1.length()) {
        if (s1[index_1] != s2[index_2]) {
            if (found_difference) {
                return false;
            }
			found_difference = true;

            if (s1.length() == s2.length()) {
				index_1++;
            }
        } else {
			index_1++;
        }
		index_2++;
    }
    return true;
}

void Test(const std::string& a, const std::string& b, bool expected) {
    bool result_a = OneEditAwayMerged(a, b);
    bool result_b = OneEditAwayMerged(a, b);

    if (result_a == expected && result_b == expected) {
        std::cout << a << ", " << b << ": success" << std::endl;
    } else {
        std::cout << a << ", " << b << ": error" << std::endl;
    }
}