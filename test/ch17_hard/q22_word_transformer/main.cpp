#pragma region Interview Question
/*
17.22 Word Transformer: Given two words of equal length that are in a dictionary, write a method to
transform one word into another word by changing only one letter at a time. The new word you get
in each step must be in the dictionary.

EXAMPLE
Input: DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#506. Start with a brute force, recursive solution. Just create all words that are one edit away,
check if they are in the dictionary, and then attempt that path.

#535. Once you have a brute force solution, try to find a faster way of getting all valid words
that are one edit away. You don't want to create all strings that are one edit away when
the vast majority of them are not valid dictionary words.

#556. To quickly get the valid words that are one edit away, try to group the words in the
dictionary in a useful way. Observe that all words in the form b_ll (such as bill, ball,
bell, and bull) will be one edit away. However, those aren't the only words that are
one edit away from bill.

#580. Create a mapping from a wildcard form (like b_ll) to all words in that form. Then, when
you want to find all words that are one edit away from bill, you can look up _ill,
b_ll, bi_l, and bil_ in the mapping.

#598 Your previous algorithm probably resembles a depth-first search. Can you make this
faster?

#618. A breadth-first search will often be faster than a depth-first search-not necessarily in
the worst case, but in many cases. Why? Can you do something even faster than this?

#738. What if you did a breadth-first search starting from both the source word and the desti-
nation word?
*/
#pragma endregion