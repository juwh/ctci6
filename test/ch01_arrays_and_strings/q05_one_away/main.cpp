#pragma region Interview Question
/*
1.5 One Away: There are three types of edits that can be performed on strings: insert a
character, remove a character, or replace a character. Given two strings, write a function
to check if they are one edit (or zero edits) away.

EXAMPLE
pale, ple	-> true
pales, pale	-> true
pale, bale	-> true
pale, bake	-> false
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#23. Start with the easy thing. Can you check each of the conditions separately?

#97. What is the relationship between the "insert character" option and the "remove
character" option? Do these need to be two separate checks?

#130. Can you do all three checks in a single pass?
*/
#pragma endregion

#include "arrays_and_strings/one_away.h"

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

        Test(a, b, expected);
        Test(b, a, expected);
    }
	return 0;
}