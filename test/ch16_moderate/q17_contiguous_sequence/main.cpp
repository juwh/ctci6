#pragma region Interview Question
/*
16.17 Contiguous Sequence: You are given an array of integers (both positive and negative). Find the
contiguous sequence with the largest sum. Return the sum.

EXAMPLE
Input 2, -8, 3, -2, 4, -10
Output 5 (i.e., {3, -2, 4}) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#531. Picture the array as alternating sequences of positive and negative numbers. Observe
that we would never include just part of a positive sequence or part of a negative
sequence.

#551. Observe that if you have a sequence of values which have a negative sum, those will
never start or end a sequence. (They could be present in a sequence if they connected
two other sequences.)

#567. Start from the beginning of the array. As that subsequence gets larger, it stays as the
best subsequence. Once it becomes negative, though, it's useless. 

#594. If we tracked the running sum, we should reset it as soon as the subsequence becomes
negative. We would never add a negative sequence to the beginning or end of another
subsequence.

#614. You can solve this in O(N) time and O(1) space.
*/
#pragma endregion