#pragma region Interview Question
/*
5.5 Debugger: Explain what the following code does: ((n & (n-1)) == 0). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#151. Reverse engineer this, starting from the outermost layer to the innermost layer.  

#202. What does it mean if A & B == 0? 

#261. If A & B == 0, then it means that A and B never have a 1 at the same spot. Apply this
to the equation in the problem. 

#302. If (n & (n-1)) == 0, then this means that n and n - 1 never have a 1 in the same
spot. Why would that happen?  

#346. What is the relationship between how n looks and how n - 1 looks? Walk through a
binary subtraction. 

#372. When you do a binary subtraction, you flip the rightmost 0s to a 1, stopping when you
get to a 1 (which is also flipped). Everything (all the 1s and 0s) on the left will stay put. 

#383. Picture n and n-1. To subtract 1 from n, you flipped the rightmost 1 to a 0 and all the 0s
on its right to 1s. lf n & n-1 == 0, then there are no 1  to the left of the first 1. What
does that mean about n? 

#398. We know that n must have only one 1 if n & (n-1) == 0. What sorts of numbers have
only one 1? 
*/
#pragma endregion