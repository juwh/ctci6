#pragma region Interview Question
/*
17.23 Max Black Square: Imagine you have a square matrix, where each cell (pixel) is either black or white
Design an algorithm to find the maximum subsquare such that all four borders are filled with black
pixels. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#684. Start with a brute force solution. Can you try the biggest possible square first?

#695. The biggest possible square is NxN. So if you try that square first and it works, then
you know that you've found the best square. Otherwise, you can try the next smallest
square.

#705. Describe the runtime of the brute force solution.

#714. Can you do preprocessing to optimize this solution?

#721. You should be able to do this in O(N^(3)) time, where N is the length of one dimension of
the square.

#736. When you're checking to see if a particular square is valid (all black borders), you check
how many black pixels are above (or below) a coordinate and to the left (or right) of this
coordinate. Can you precompute the number of black pixels above and to the left of a
given cell?
*/
#pragma endregion