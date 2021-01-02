#pragma region Interview Question
/*
8.8 Permutations with Dups: Write a method to compute all permutations of a string whose charac-
ters are not necessarily unique. The list of permutations should not have duplicates. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#161. You could handle this by just checking to see if there are duplicates before printing
them (or adding them to a list). You can do this with a hash table. In what case might this
be okay? In what case might it not be a very good solution? 

#190. If you haven't solved 8.7 yet, do that one first.  

#222. Try getting the count of each character. For example, ABCAAC has 3 As, 2 Cs, and 1 B.

#255. To get all permutations with 3 As, 2 Cs, and 1 B, you need to first pick a starting char-
acter: A, B, or C. If it's an A, then you need all permutations with 2 As, 2 Cs, and 1 B. 
*/
#pragma endregion