#pragma region Interview Question
/*
3.3 Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, 
it might topple. Therefore, in real life, we would likely start a new stack when the 
previous stack exceeds some threshold. Implement a data structure SetOfStacks that 
mimics this. SetOfStacks should be composed of several stacks and should create a new 
stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() 
should behave identically to a single stack (that is, pop() should return the same 
values as it would if there were just a single stack).

FOLLOW UP
Implement a function popAt (int index) which performs a pop operation on a specific sub-
stack.
*/
#pragma endregion
#pragma region Hints
/*
#64. You will need to keep track of the size of each substack. When one stack is full,
you may need to create a new stack.

#81. Popping an element at a specific substack will mean that some stacks aren't at full
capacity. Is this an issue? There's no right answer, but you should think about how to 
handle this.
*/
#pragma endregion