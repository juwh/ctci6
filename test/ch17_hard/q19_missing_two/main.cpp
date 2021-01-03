#pragma region Interview Question
/*
17.19 Missing Two: You are given an array with all the numbers from 1 to N appearing exactly once,
except for one number that is missing. How can you find the missing number in O(N) time and
O(1) space? What if there were two numbers missing? 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#503. Start with the first part: Finding the missing number if only one number is missing.

#590. Part 1: If you have to find the missing number in O(1) space and O(N) time, then you
can do a only constant number of passes through the array and can store only a few
variables.

#609. Part 1: What if you added up all the values in the array? Could you then figure out the
missing number?

#626. Part 2: We're now looking for two missing numbers, which we will call a and b. The
approach from part 1 will tell us the sum of a and b, but it won't actually tell us a and b.
What other calculations could we do?

#649. Part 2: There are a lot of different calculations we could try. For example, we could
multiply all the numbers, but that will only lead us to the product of a and b.

#672. Part 2: Adding the numbers together will tell us the result of a + b. Multiplying the
numbers together will tell us the result of a * b. How can we get the exact values for a
and b?

#689. Part 2: We could do both. If we know that a + b = 87 and a * b = 962, then we
can solve for a and b: a = 13 and b = 74. But this will also result in having to multiply
really large numbers. The product of all the numbers could be larger than 10^(157). Is there
a simpler calculation you can make?

#696. Part 2: Almost any "equation" we can come up with will work here (as long as it's not
equivalent to a linear sum). It's just a matter of keeping this sum small.

#702. Part 2: Try a sum of squares of the values.

#717. Part 2: You might need the quadratic formula. It's not a big deal if you don't remember
it. Most people won't. Remember that there is such a thing as good enough.
*/
#pragma endregion