#pragma region Interview Question
/*
2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#5. A palindrome is something which is the same when written forwards and backwards.
What if you reversed the linked list?

#13. Try using a stack.

#29. Assume you have the length of the linked list. Can you implement this recursively?

#61. In the recursive approach (we have the length of the list), the middle is the base
case: IsPermutation(middle) is true. The node x to the immediate left of the middle:
What can that node do to check if x->middle->y forms a palindrome? Now suppose that
checks out. What about the previous node a? If x->middle->y is a palindrome, how can it
check that a->x->middle->y->b is a palindrome?

#101. Go back to the previous hint. Remember: There are ways to return multiple values.
You can do this with a new class.
*/
#pragma endregion