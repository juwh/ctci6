#pragma region Interview Question
/*
10.7 Missing Int: Given an input file with four billion non-negative integers, provide an algorithm to
generate an integer that is not contained in the file. Assume you have 1 GB of memory available for
this task.

FOLLOW UP
What if you have only 10MB of memory? Assume that all the values are distinct and we now have
no more than one billion non-negative integers. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#235. Would a bit vector help? 

#254. To do it with less memory, can you try multiple passes? 

#281. Try using one pass to get it down to a range of values, and then a second pass to find a
specific value. 
*/
#pragma endregion