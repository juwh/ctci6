#pragma region Interview Question
/*
17.14 Smallest K: Design an algorithm to find the smallest K numbers in an array. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#470. There are actually several approaches. Brainstorm these. It's okay to start off with a naive
approach.

#530. Consider thinking about reorganizing the data in some way or using additional data
structures.

#552. Can you sort the numbers?

#593. What about using a heap or tree of some sort?

#625. If you picked an arbitrary element, how long would it take you to figure out the rank of
this element (the number of elements bigger or smaller than it)?

#647. If you picked an arbitrary element, you would, on average, wind up with an element
around the 50th percentile mark (half the elements above it and half the elements
below). What if you did this repeatedly?

#661. Think about the previous hint some more, particularly in the context of quicksort.

#678. What if, when you picked an element, you swapped elements around (as you do in
quicksort) so that the elements below it would be located before the elements above
it? If you did this repeatedly, could you find the smallest one million numbers?
*/
#pragma endregion