#pragma region Interview Question
/*
10.11  Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal to
the adjacent integers and a "valley" is an element which is less than or equal to the adjacent inte-
gers. For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array
of integers, sort the array into an alternating sequence of peaks and valleys.

EXAMPLE
Input: {5, 3, 1, 2, 3}
Output: {5, 1, 3, 2, 3} 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#196. Imagine the array were sorted in ascending order. Is there any way you could "fix it" to
be sorted into alternating peaks and valleys? 

#219. Try walking through a sorted array. Can you just swap elements until you have fixed the
array? 

#231. Note that if you ensure the peaks are in place, the valleys will be, too. Therefore, your
iteration to fix the array can skip over every other element. 

#253. Do you necessarily need the arrays to be sorted? Can you do it with an unsorted array? 

#277. Suppose you had a sequence of three elements ({0, 1, 2}, in any order. Write out all
possible sequences for those elements and how you can fix them to make 1 the peak. 

#292. Revisit the set of sequences for {0, 1, 2} that you just wrote out. Imagine there are
elements before the leftmost element. Are you sure that the way you swap the elements
won't invalidate the previous part of the array? 

#316. You should be able to design an O(n) algorithm. 
*/
#pragma endregion