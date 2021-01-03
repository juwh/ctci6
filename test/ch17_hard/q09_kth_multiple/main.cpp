#pragma region Interview Question
/*
17.9 Kth Multiple: Design an algorithm to find the kth number such that the only prime factors are 3, 5,
and 7. Note that 3, 5, and 7 do not have to be factors, but it should not have any other prime factors.
For example, the first several multiples would be (in order) 1, 3, 5, 7, 9, 15, 21. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#488. Be clear about what this problem is asking for. It's asking for the kth smallest number in
the form 3^(a) * 5^(b) * 7^(c).

#508. What does a brute force solution to get the kth smallest value for 3^(a) * 5^(b) * 7^(c) look
like?

#550. In looking for the kth smallest value of 3^(a) * 5^(b) * 7^(c), we know that a, b, and c will be
less than or equal to k. Can you generate all such numbers?

#591. Look at the list of all values for 3^(a) * 5^(b) * 7^(c). Observe that each value in the list will be
3*(some previous value), 5*(some previous value), or 7*(some previous value).

#622. Since each number is 3, 5, or 7 times a previous value in the list, we could just check all
possible values and pick the next one that hasn't been seen yet. This will result in a lot of
duplicated work. How can we avoid this?

#660. Rather than checking all values in the list for the next value (by multiplying each by 3,
5, and 7), think about it this way: when you insert a value x into the list, you can "create"
the values 3x, 5x, and 7x to be used later.

#686. When you add x to the list of the first k values, you can add 3x, 5x, and 7x to some new
list. How do you make this as optimal as possible? Would it make sense to keep multiple
queues of values? Do you always need to insert 3x, 5x, and 7x? Or, perhaps sometimes
you need to insert only 7x? You want to avoid seeing the same number twice.
*/
#pragma endregion