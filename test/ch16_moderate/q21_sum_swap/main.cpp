#pragma region Interview Question
/*
16.21 Sum Swap: Given two arrays of integers, find a pair of values (one value from each array) that you
can swap to give the two arrays the same sum.

EXAMPLE
Input: {4, 1,2, 1, 1, 2} and {3, 6, 3, 3}
Output: {1, 3} 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#545. Do some math here or play around with some examples. What does this pair need to
look like? What can you say about their values?

#557. When you move a value a from array A to array B, then A's sum decreases by a and B's
sum increases by a. What happens when you swap two values? What would be needed
to swap two values and get the same sum?

#564. If you swap two values, a and b, then the sum of A becomes sumA - a + b and the
sum of B becomes sumB - b + a. These sums need to be equal.

#571. You are looking for values a and b where sumA - a + b = sumB - b + a. Do the
math to work out what this means for a and b's values.

#583. If we do the math, we are looking for a pair of values such that a - b = (sumA -
sumB) / 2. The problem then reduces to looking for a pair of values with a particular
difference.

#592. A brute force solution is to just look through all pairs of values to find one with the
right difference. This will probably look like an outer loop through A with an inner loop
through B. For each value, compute the difference and compare it to what we're looking
for. Can we be more specific here, though? Given a value in A and a target difference, do
we know the exact value of the element within B we're looking for?

#602. What the brute force really does is look for a value within B which equals a - target.
How can you more quickly find this element? What approaches help us quickly find out
if an element exists within an array?

#606. We can use a hash table here. We can also try sorting. Both help us locate elements more
quickly.

#635. What if the sum of A is 11 and the sum of B is 8? Can there be a pair with the right differ-
ence? Check that your solution handles this situation appropriately.
*/
#pragma endregion