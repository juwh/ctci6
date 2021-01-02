#pragma region Interview Question
/*
8.7 Permutations without Dups: Write a method to compute all permutations of a string of unique
characters. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#150. Approach 1: Suppose you had all permutations of abc. How can you use that to get all
permutations of abcd? 

#185. Approach 1: The permutations of abc represent all ways of ordering abc. Now, we want
to create all orderings of abcd. Take a specific ordering of abcd, such as bdca. This
bdca string represents an ordering of abc, too: Remove the d and you get bca. Given
the string bca, can you create all the "related" orderings that include d, too? 

#200. Approach 1: Given a string such as bca, you can create all permutations of abcd that
have {a, b, c} in the order bca by inserting d into each possible location: dbca,
bdca, bcda, bcad. Given all permutations of abc, can you then create all permutations
of abcd? 

#267. Approach 1: You can create all permutations of abcd by computing all permutations of
abc and then inserting d into each possible location within those. 

#278. Approach 2: If you had all permutations of two-character substrings, could you generate
all permutations of three-character substrings? 

#309. Approach 2: To generate a permutation of abcd, you need to pick an initial character. It
can be a, b, c, or d. You can then permute the remaining characters. How can you use
this approach to generate all permutations of the full string? 

#335. Approach 2: To generate all permutations of abcd, pick each character (a, b, c, or d)
as a starting character. Permute the remaining characters and prepend the starting
character. How do you permute the remaining characters? With a recursive process that
follows the same logic. 

#356. Approach 2: You can implement this approach by having the recursive function pass
back the list of the strings, and then you prepend the starting character to it. Or, you can
push down a prefix to the recursive calls. 
*/
#pragma endregion