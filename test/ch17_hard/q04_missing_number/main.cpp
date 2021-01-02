#pragma region Interview Question
/*
17.4 Missing Number: An array A contains all the integers from 0 to n, except for one number which
is missing. In this problem, we cannot access an entire integer in A with a single operation. The
elements of A are represented in binary, and the only operation we can use to access them is "fetch
the jth bit of A[i]," which takes constant time. Write code to find the missing integer. Can you do
it in O(n) time? 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#610. 17.4 How long would it take you to figure out the least significant bit of the missing number?

#659. 17.4 To find the least significant bit of the missing number, note that you know how many
0s and 1s to expect. For example, if you see three 0s and three 1s in the least significant
bit, then the missing number's least Significant bit must be a 1. Think about it: in any
sequence of 0s and 1s, you'd get a 0, then a 1, then a 0, then a 1, and so on.

#683. 17.4 Once you've identified that the least significant bit is a 0 (or a 1), you can rule out all the
numbers without 0 as the least significant bit. How is this problem different from the
earlier part?
*/
#pragma endregion