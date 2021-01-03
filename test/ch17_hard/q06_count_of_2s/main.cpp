#pragma region Interview Question
/*
17.6 Count of 25: Write a method to count the number of 2s that appear in all the numbers between 0
and n (inclusive).

EXAMPLE
Input: 25
Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25. Note that 22 counts for two 2s.) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#573. Start with a brute force solution.

#612. Rather than counting the number of twos in each number, think about digit by digit.
That is, count the number of twos in the first digit (for each number), then the number
of twos in the second digit (for each number), then the number of twos in the third digit
(for each number), and so on.

#641. Is there a faster way of calculating how many twos are in a particular digit across a range
of numbers? Observe that roughly 1/10th of any digit should be a 2-but only roughly.
How do you make that more exact?
*/
#pragma endregion