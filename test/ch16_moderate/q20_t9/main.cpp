#pragma region Interview Question
/*
16.20  T9: On old cell phones, users typed on a numeric keypad and the phone would provide a list of
words that matched these numbers. Each digit mapped to a set of 0 - 4 letters. Implement an algo-
rithm to return a list of matching words, given a sequence of digits. You are provided a list of valid
words (provided in whatever data structure you'd like). The mapping is shown in the diagram below:
    1       2       3
            abc     def
    4       5       6
    ghi     jkl     mno
    7       8       9
    pqrs    tuv     wxyz
            0

EXAMPLE
Input: 8733
Output: tree, used 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#471. Consider recursion.

#487. Can you recursively try all possibilities? 

#654. In the real world, we should know that some prefixes/substrings won't work. For
example, consider the number 33835676368. Although 3383 does correspond to
fftf, there are no words that start with fftf. Is there a way we can short-circuit in
cases like this?

#703. A trie might help us short-circuit. What if you stored the whole list of words in the trie?

#726. We're probably going to run this algorithm many times. If we did more preprocessing, is
there a way we could optimize this?

#744. With preprocessing, we can actually get the lookup time down to O(1).
*/
#pragma endregion