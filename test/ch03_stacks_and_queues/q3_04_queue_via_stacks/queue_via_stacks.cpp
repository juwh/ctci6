#pragma region Interview Question
/*
3.4 Queue via Stacks: Implement a MyQueue class which implements a queue using two 
stacks.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#98. The major difference between a queue and a stack is the order of elements. A queue
removes the oldest item and a stack removes the newest item. How could you remove the
oldest item from a stack if you only had access to the newest item?

#114. We can remove the oldest item from a stack by repeatedly removing the newest item
(iunserting those into the temporary stack) until we get down to one element. Then after
we've retrieved the newest item, putting all the elements back. The issue with this is
that doing several pops in a row will require O(N) work each time. Can we optimize for
scenarios where we might do several pops in a row?
*/
#pragma endregion