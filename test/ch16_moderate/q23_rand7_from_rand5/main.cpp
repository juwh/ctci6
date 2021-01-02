#pragma region Interview Question
/*
16.23 Rand7 from RandS: Implement a method rand7() given rand5(). That is, given a method that
generates a random number between 0 and 4 (inclusive), write a method that generates a random
number between 0 and 6 (inclusive). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#505. Be very careful that your solution actually returns each value from 0 through 6 with
equal probability.

#574. Start with a brute force solution. How many times does it call rand 5() in the worst
case?

#637. Make a table indicating how each possible sequence of calls to rand5() would map
to the result of rand7(). For example, if you were implementing rand3() with
(rand2() + rand2()) % 3, then the table would look like the below. Analyze this
table. What can it tell you?

    1st 2nd Result
    e   e   e
    e   1   1
    1   e   1
    1   1   2

#668. Looking at this table again, note that the number of rows will be 5^(k), where k is the max
number of calls to rand5(). In order to make each value between 0 and 6 have equal
probability, 1/7th of the rows must map to 0, 1/7th to 1, and so on. Is this possible?

#697. It is not possible to divide 5^(k) evenly by 7. Does this mean that you can't implement
rand7() with rand5()?

#720. You can implement rand7() with rand5(), you just can't do it deterministically (such
that you know it will definitely terminate after a certain number of calls). Given this,
write a solution that works.
*/
#pragma endregion