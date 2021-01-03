#pragma region Interview Question
/*
17.10 Majority Element: A majority element is an element that makes up more than half of the items in
an array. Given a positive integers array, find the majority element. If there is no majority element,
return -1. Do this in O(N) time and O(1) space.

EXAMPLE
Input:  1 2 5 9 5 9 5 5 5
Output: 5 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#522. Start with a brute force solution. Can you just check each value to see if it's the majority
element? 

#566. Consider the brute force solution. We pick an element and then validate if it's the
majority element by counting the number of matching and non-matching elements.
Suppose, for the first element, the first few checks reveal seven non-matching elements
and three matching elements. Is it necessary to keep checking this element?

#604. The majority element will not necessarily look like the majority element at first. It is
possible, for example, to have the majority element appear in the first element of the
array and then not appear again for the next eight elements. However, in those cases,
the majority element will appear later in the array (in fact, many times later on in the
array). It's not necessarily critical to continue checking a specific instance of an element
for majority status once it's already looking "unlikely."

#620. Note also that the majority element must be the majority element for some subarray
and that no subarray can have multiple majority elements.

#650. Try this: Given an element, start checking if this is the start of a subarray for which it's
the majority element. Once it's become "unlikely" (appears less than half the time), start
checking at the next element (the element after the subarray).
*/
#pragma endregion