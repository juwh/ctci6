#pragma region Interview Question
/*
8.9 Parens: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
of n pairs of parentheses.
EXAMPLE
Input: 3
Output: ((())), (()()), (())(), ()(()), ()()() 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#138. Try the Base Case and Build approach. 

#174. Suppose we had all valid ways of writing two pairs of parentheses. How could we use
this to get all valid ways of writing three pairs? 

#187. We could try generating the solution for three pairs by taking the list of two pairs of
parentheses and adding a third pair. We'd have to add the third paren before, around,
and after. That is: ()<SOLUTION>, (<SOLUTION>), <SOLUTION>(). Will this
work? 

#209. The problem with the solution suggested by the earlier hint is that it might have dupli-
cate values. We could eliminate this by using a hash table. 

#243. Alternatively, we could think about doing this by moving through the string and adding
left and right parens at each step. Will this eliminate duplicates? How do we know if we
can add a left or right paren? 

#265. Adding a left or right paren at each step will eliminate duplicates. Each substring will be
unique at each step. Therefore, the total string will be unique. 

#295. We can ensure that this string is valid by counting the number of left and right parens.
It is always valid to add a left paren, up until the total number of pairs of parens. We can
add a right paren as long as count(left parens) <= count(right parens). 
*/
#pragma endregion