#pragma region Interview Question
/*
5.3 Flip Bit to Win: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
find the length of the longest sequence of 1s you could create.

EXAMPLE
Input: 1775 (or: 1110111101111)
Output: 8 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#159. Start with a brute force solution. Can you try all possibilities? 

#226. Flipping a 0 to a 1 can merge two sequences of 1s-but only if the two sequences are
separated by only one 0. 

#314. Each sequence can be lengthened by merging it with an adjacent sequence (if any) or
just flipping the immediate neighboring zero. You just need to find the best choice. 

#352. Try to do it in linear time, a single pass, and O(1) space. 
*/
#pragma endregion