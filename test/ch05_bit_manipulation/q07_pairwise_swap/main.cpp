#pragma region Interview Question
/*
5.7 Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).  
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#145. Swapping each pair means moving the even bits to the left and the odd bits to the right.
Can you break this problem into parts? 

#248. Can you create a number that represents just the even bits? Then can you shift the even
bits over by one? 

#328. The value 1010 in binary is 10 in decimal or 0xA in hex. What will a sequence of 101010...
be in hex? That is, how do you represent an alternating sequence of 1s and 0s with 1s in
the odd places? How do you do this for the reverse (1s in the even spots)? 

#355. Try masks 0xaaaaaaaa and 0x55555555 to select the even and odd bits. Then try
shifting the even and odd bits around to create the right number. 
*/
#pragma endregion