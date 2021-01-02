#pragma region Interview Question
/*
16.19  Pond Sizes: You have an integer matrix representing a plot of land, where the value at that loca-
tion represents the height above sea level. A value of zero indicates water. A pond is a region of
water connected vertically, horizontally, or diagonally. The size of the pond is the total number of
connected water cells. Write a method to compute the sizes of all ponds in the matrix.

EXAMPLE
Input:
    0 2 1 0
    0 1 0 1
    1 1 0 1
    0 1 0 1
Output: 2, 4, 1 (in any order) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#674. If you were given the row and column of a water cell, how can you find all connected
spaces?

#687. Try recursion to count the number of water cells.

#706. How can you make sure that you're not revisiting the same cells? Think about how
breadth-first search or depth-first search on a graph works.

#723. You should have an algorithm that's O(N^(2)) on an NxN matrix. If your algorithm isn't,
consider if you've miscomputed the runtime or if your algorithm is suboptimal.
*/
#pragma endregion