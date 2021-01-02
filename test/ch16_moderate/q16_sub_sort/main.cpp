#pragma region Interview Question
/*
16.16 Sub Sort: Given an array of integers, write a method to find indices m and n such that if you sorted
elements m through n, the entire array would be sorted. Minimize n - m (that is, find the smallest
such sequence).

EXAMPLE
Input 1, 2, 4, 7, l0, 11, 7, 12, 6, 7, 16, 18, 19
Output: (3, 9) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#482. Would it help to know the longest sorted sequences at the beginning and end?

#553. We can think about the array as divided into three subarrays: LEFT, MIDDLE, RIGHT.
LEFT and RIGHT are both sorted. The MIDDLE elements are in an arbitrary order. We
need to expand MIDDLE until we could sort those elements and then have the entire
array sorted.

#667. Consider the three subarrays: LEFT, MIDDLE, RIGHT. Focus on just this question: Can
you sort middle such that the entire array becomes sorted? How would you check this?

#708. In order to be able to sort MIDDLE and have the whole array become sorted, you need
MAX(LEFT) <= MIN(MIDDLE and RIGHT) and MAX(LEFT and MIDDLE) <=
MIN(RIGHT).

#735. Can you expand the middle until the earlier condition is met?

#746. You should be able to solve this in O(N) time.
*/
#pragma endregion