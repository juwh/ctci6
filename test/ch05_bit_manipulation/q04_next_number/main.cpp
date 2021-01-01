#pragma region Interview Question
/*
5.4 Next Number: Given a positive integer, print the next smallest and the next largest number that
have the same number of 1 bits in their binary representation. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#147. Get Next: Start with a brute force solution for each.

#175. Get Next: Picture a binary number-something with a bunch of 1s and 0s spread out
throughout the number. Suppose you flip a 1 to a 0 and a 0 to a 1. ln what case will the
number get bigger? In what case will it get smaller? 

#242. Get Next: If you flip a 1 to a 0 and a 0 to a 1, it will get bigger if the 0-> 1 bit is more signifi-
cant than the 1->0 bit. How can you use this to create the next biggest number (with the
same number of 1s)? 

#312. Get Next: Can you flip a 0 to a 1 to create the next biggest number? 

#339. Get Next: Flipping a 0 to a 1 will create a bigger number. The farther right the index is
the smaller the bigger number is. If we have a number like 1001, we want to flip the
rightmost 0 (to create 1011). But if we have a number like 1010, we should not flip the
rightmost 1. 

#358. Get Next: We should flip the rightmost non-trailing 0. The number 1010 would become
1110. Once we've done that, we need to flip a 1 to a 0 to make the number as small
as possible, but bigger than the original number (1010). What do we do? How can we
shrink the number? 

#375. Get Next: We can shrink the number by moving all the 1s to the right of the flipped bit
as far right as possible (removing a 1 in the process). 

#390. Get Previous: Once you've solved Get Next, try to invert the logic for Get Previous. 
*/
#pragma endregion