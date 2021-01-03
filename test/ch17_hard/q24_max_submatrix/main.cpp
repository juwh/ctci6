#pragma region Interview Question
/*
17.24 Max Submatrix: Given an NxN matrix of positive and negative integers, write code to find the
submatrix with the largest possible sum. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#469. Start with a brute force solution.

#511. The brute force solution requires us to continuously compute the sums of each matrix.
Can we optimize this?

#525. Can you do any sort of precomputation to make computing the sum of a submatrix
O(1)?

#539. What if you precomputed the sum of the submatrix starting at the top left corner and
continuing to each cell? How long would it take you to compute this? If you did this,
could you then get the sum of an arbitrary sub matrix in O(1) time?

#565. If you can precompute the sum from the top left corner to each cell, you can use this to
compute the sum of an arbitrary submatrix in O(1) time. Picture a particular submatrix.
The full, precomputed sum will include this submatrix, an array immediately above it
(C), and array to the left (B), and an area to the top and left (A). How can you compute
the sum of just D?

#581. The sum of just D will be sum(A&B&C&D) - sum(A&B) - sum(A&C) + sum(A).

#595. With precomputation, you should be able to get a runtime of O(N^(4)). Can you make this
even faster?

#615. Suppose this was just a single array. How could we compute the subarray with the
largest sum? See 16.17 for a solution to this.

#621. Suppose I just wanted you to find the maximum submatrix starting at row r1 and
ending at row r2, how could you most efficiently do this? (See the prior hint.) If I now
wanted you find the maximum subarray from r1 to (r2+2), could you do this effici-
ently?
*/
#pragma endregion