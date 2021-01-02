#pragma region Interview Question
/*
8.3 Magic Index: A magic index in an array A [0...n-1] is defined to be an index such that A[i] =
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
array A.

FOLLOW UP
What if the values are not distinct? 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#170. Start with a brute force algorithm.  

#204. Your brute force algorithm probably ran in O(N) time. If you're trying to beat that
runtime, what runtime do you think you will get to? What sorts of algorithms have that
runtime? 

#240. Can you solve the problem in O(log N)? 

#286. Binary search has a runtime of O(log N). Can you apply a form of binary search to the
problem?  

#340. Given a specific index and value, can you identify if the magic index would be before or
after it?
*/
#pragma endregion