#pragma region Interview Question
/*
8.5 Recursive Multiply: Write a recursive function to multiply two positive integers without using the
* operator. You can use addition, subtraction, and bit shifting, but you should minimize the number
of those operations. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#166. Think about multiplying 8 by 9 as counting the number of cells in a matrix with width 8
and height 9. 

#203. If you wanted to count the cells in an 8x9 matrix, you could count the cells in a 4x9
matrix and then double it. 

#227. Think about how you might handle this for odd numbers. 

#234. If there's duplicated work across different recursive calls, can you cache it? 

#246. If you're doing 9*7 (both odd numbers), then you could do 4*7 and 5*7. 

#280. Alternatively, if you're doing 9 * 7, you could do 4*7, double that, and then add 7. 
*/
#pragma endregion