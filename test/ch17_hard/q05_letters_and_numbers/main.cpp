#pragma region Interview Question
/*
17.5 Letters and Numbers: Given an array filled with letters and numbers, find the longest subarray with
an equal number of letters and numbers. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#485. It doesn't really matter which letter or number it is. You can simplify this problem to just
having an array of As and Bs. You would then be looking for the longest subarray with
an equal number of As and Bs.

#515. Start with a brute force solution.

#619. What if you just started from the beginning, counting the number of As and the number
of Bs you've seen so far? (Try making a table of the array and the number of As and Bs
thus far.)

#671. When the above tables have equal values for the number of As and Bs, the entire
subarray (starting from index 0) has an equal number of As and Bs. How could you use
this table to find qualifying subarrays that don't start at index 0?

#713. Suppose, in this table, index i has count(A, 0->i) = 3 and count(B, 0->i) =
7. This means that there are four more Bs than As. If you find a later spot j with the same
difference (count(B, 0->j) - count(A, 0->j)), then this indicates a subarray
with an equal number of As and Bs.
*/
#pragma endregion