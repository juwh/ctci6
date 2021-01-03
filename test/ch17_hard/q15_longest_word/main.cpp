#pragma region Interview Question
/*
17.15 Longest Word: Given a list of words, write a program to find the longest word made of other words
in the list.

EXAMPLE
Input: cat, banana, dog, nana, walk, walker, dogwalker
Output: dogwalker 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#475. Try simplifying this problem: What if you just needed to know the longest word made
up of two other words in the list?

#499. If we wanted to know just the longest word made up of other words in the list, then we
could iterate over all words, from longest to shortest, checking if each could be made up
of other words. To check this, we split the string in all possible locations.

#543. Extend the earlier idea to multiple words. Can we just break each word up in all possible
ways?

#589. When you get recursive algorithms that are very inefficient, try looking for repeated
subproblems.
*/
#pragma endregion