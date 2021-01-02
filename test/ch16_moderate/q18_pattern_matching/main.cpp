#pragma region Interview Question
/*
16.18 Pattern Matching: You are given two strings, pattern and value. The pattern string consists of
just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo
matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b.
Write a method to determine if value matches pattern. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#631. Start with a brute force approach. Can you try all possibilities for a and b?

#643. Observe that one of the substrings, either a or b, must start at the beginning of the
string. That cuts down the number of possibilities.

#653. Don't forget to handle the possibility that the first character in the pattern is b.

#663. Be careful with how you analyze the runtime. If you iterate through O(n^(2)) substrings
and each one does an O(n) string comparison, then the total runtime is O(n^(3)).

#685. Suppose you decide on a specific value for the "a" part of a pattern. How many possibili-
ties are there for b?

#718. Since the value of a determines the value of b (and vice versa) and either a or b must
start at the beginning of the value, you should have only O(n) possibilities for how to
split up the pattern.

#727. You should be able to have an O(n^(2)) algorithm.
*/
#pragma endregion