#pragma region Interview Question
/*
17.18 Shortest Supersequence: You are given two arrays, one shorter (with all distinct elements) and one
longer. Find the shortest subarray in the longer array that contains all the elements in the shorter
array. The items can appear in any order.

EXAMPLE
Input: {1, 5, 9} | {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7}
Output: [7, 10] (the underlined portion above) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#645. Start with a brute force solution.

#652. One brute force solution is to take each starting position and move forward until you've
found a subsequence which contains all the target characters.

#669. Another way of thinking about the brute force is that we take each starting index and
find the next instance of each element in the target string. The maximum of all these
next instances marks the end of a subsequence which contains all the target characters.
What is the runtime of this? How can we make it faster?

#681. Consider the previously explained brute force solution. A bottleneck is repeatedly
asking for the next instance of a particular character. Is there a way you can optimize
this? You should be able to do this in O(1) time.

#691. Can you precompute the next instance of a particular character from each index? Try
using a multi-dimensional array.

#725. Once you have the precomputation solution figured out, think about how you can
reduce the space complexity. You should be able to get it down to O(SB) time and
O(B) space (where B is the size of the larger array and S is the size of the smaller array).

#731. Another way to think about it is this: Imagine you had a list of the indices where each
item appeared. Could you find the first possible subsequence with all the elements?
Could you find the second?

#741. Consider using a heap.
*/
#pragma endregion