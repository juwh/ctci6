#pragma region Interview Question
/*
10.4 Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
method. It does, however, have an elementAt(i) method that returns the element at index i in
O(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
structure only supports positive integers.) Given a Listy which contains sorted, positive integers,
find the index at which an element x occurs. If x occurs multiple times, you may return any index. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#320. Think about how binary search works. What will be the issue with just implementing
binary search? 

#337. Binary search requires comparing an element to the midpoint. Getting the midpoint
requires knowing the length. We don't know the length. Can we find it? 

#348. We can find the length by using an exponential backoff. First check index 2, then 4, then
8, then 16, and so on. What will be the runtime of this algorithm? 
*/
#pragma endregion