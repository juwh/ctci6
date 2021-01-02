#pragma region Interview Question
/*
16.11 Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end.
There are two types of planks, one of length shorter and one of length longer. You must use
exactly K planks of wood. Write a method to generate all possible lengths for the diving board. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#690. Consider building a diving board. What are the choices you make?

#700. Consider a recursive solution.

#715. Once you have a recursive algorithm, think about the runtime. Can you make this faster?
How?

#722. Consider memoization to optimize the runtime. Think carefully about what exactly you
cache. What is the runtime? The runtime is closely related to the max size of the table.

#740. There's an alternate, clever (and very fast) solution. You can actually do this in linear time
without recursion. How?

#747. Think about it this way. You are picking K planks and there are two different types. All
choices with 10 of the first type and 4 of the second type will have the same sum. Can
you just iterate through all possible choices?
*/
#pragma endregion