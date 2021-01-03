#pragma region Interview Question
/*
17.1 Add Without Plus: Write a function that adds two numbers. You should not use + or any arithmetic
operators. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#467. Walk through binary addition by hand (slowly!) and try to really understand what is
happening.

#544. You can think about binary addition as iterating through the number, bit by bit, adding
two bits, and then carrying over the one if necessary. You could also think about it as
grouping the operations. What if you first added each of the bits (without carrying any
overflow)? After that, you can handle the overflow.

#601. Focus on just one of the steps above. If you "forgot" to carry the ones, what would the
add operation look like?

#628. The adding step alone would convert 1 + 1 -> 0, 1 + 0 -> 1, 0 + 1 -> 1, 0 + 0 -> 0. How do
you do this without the + sign?

#642. You can do the add step with an XOR.

#664. Now focus on the carrying. In what cases will values carry? How do you apply the carry
to the number?

#692. The carry will happen when you are doing 1 + 1. How do you apply the carry to the
number?

#712. You can use an AND operation to compute the carry. What do you do with it?

#724. You might need to do the add/carry operation more than once. Adding carry to sum
might cause new values to carry.
*/
#pragma endregion