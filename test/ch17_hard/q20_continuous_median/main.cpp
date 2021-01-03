#pragma region Interview Question
/*
17.20 Continuous Median: Numbers are randomly generated and passed to a method. Write a program
to find and maintain the median value as new values are generated. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#519. Recall that the median means the number for which half the numbers are larger and half
the numbers are smaller.

#546. Note that you have to store all the elements you've seen. Even the smallest of the
first 100 elements could become the median. You can't just toss very low or very high
elements.

#575. Another way to think about this is: Can you maintain the bottom half of elements and
the top half of elements?

#709. What if you used a heap? Or two heaps?
*/
#pragma endregion