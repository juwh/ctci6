#pragma region Interview Question
/*
17.8 Circus Tower: A circus is designing a tower routine consisting of people standing atop one anoth-
er's shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter
than the person below him or her. Given the heights and weights of each person in the circus, write
a method to compute the largest possible number of people in such a tower.

EXAMPLE
Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
Output: The longest tower is length 6 and includes from top to bottom:
    (56, 90) (60, 95) (65, 100) (68, l10) (70, 150) (75, 190) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#638. This problem asks us to find the longest sequence of pairs you can build such that both
sides of the pair are constantly increasing. What if you needed only one side of the pair
to increase?

#657. If you needed only one side of the pair to increase, then you would just sort all the
values on that side. Your longest sequence would in fact be all of the pairs (other than
any duplicates, since the longest sequence needs to strictly increase). What does this tell
you about the original problem?

#666. If you sort the values based on height, then this will tell you the ordering of the final pairs.
The longest sequence must be in this relative order (but not necessarily containing all
of the pairs). You now just need to find the longest increasing subsequence on weight
while keeping the items in the same relative order. This is essentially the same problem
as having an array of integers and trying to find the longest sequence you can build
(without reordering those items).

#682. Try a recursive approach that just evaluates all possibilities.

#699. Another way to think about the problem is this: if you had the longest sequence ending
at each element A[0] through A[n-1], could you use that to find the longest sequence
ending at element A[n-1]?
*/
#pragma endregion