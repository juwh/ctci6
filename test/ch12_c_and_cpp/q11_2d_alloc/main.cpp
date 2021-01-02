#pragma region Interview Question
/*
12.11 2D Alloc: Write a function in C called my2DAlloc which allocates a two-dimensional array. Mini-
mize the number of calls to malloc and make sure that the memory is accessible by the notation
arr[i][j]. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#406. Recall that a two dimensional array is essentially an array of arrays. 

#418. One approach is to call malloc for each array. How would we free the memory here? 

#426. Can we allocate this instead as a contiguous block of memory? 
*/
#pragma endregion