#pragma region Interview Question
/*
16.14 Best Line: Given a two-dimensional graph with points on it, find a line which passes the most
number of points. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#491. Sometimes, a brute force is a pretty good solution. Can you try all possible lines?

#520. You can't truly try all possible lines in the world-that's infinite. But you know that a
"best" line must intersect at least two points. Can you connect each pair of points? Can
you check if each line is indeed the best line?

#529. You should be able to get to an O(N^(2)) solution.

#563. Have you tried using a hash table?
*/
#pragma endregion