#pragma region Interview Question
/*
16.7 Number Max: Write a method that finds the maximum of two numbers. You should not use if-else
or any other comparison operator. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#473. Let k be 1 if a > b and 0 otherwise. If you were given k, could you return the max
(without a comparison or if-else logic)?

#513. If k were 1 when a > b and 0 otherwise, then you could return a*k + b*(not k).
But how do you create k?

#707. When a > b, then a - b > 0. Can you get the sign bit of a - b?

#728. Have you considered how to handle integer overflow in a - b?
*/
#pragma endregion