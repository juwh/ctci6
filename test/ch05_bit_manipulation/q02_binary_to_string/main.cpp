#pragma region Interview Question
/*
5.2 Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
the binary representation. If the number cannot be represented accurately in binary with at most 32
characters, print "ERROR." 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#143. To wrap your head around the problem, try thinking about how you'd do it for integers. 

#167. In a number like .893 (in base 10), what does each digit signify? What then does each
digit in .10010 signify in base 2? 

#173. A number such as .893 (in base 10) indicates 8 * 10_(-1) + 9 * 10_(-2) + 3 * 10_(-3).
Translate this system into base 2. 

#269. How would you get the first digit in .893? If you multiplied by 10, you'd shift the values
over to get 8.93. What happens if you multiply by 2? 

#297. Think about what happens for values that can't be represented accurately in binary. 
*/
#pragma endregion