#pragma region Interview Question
/*
8.2 Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
The robot can only move in two directions, right and down, but certain cells are "off limits" such that
the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
the bottom right. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#331. For the robot to reach the last cell, it must find a path to the second-to-last cells. For it to
find a path to the second-to-last cells, it must find a path to the third-to-last cells. 

#360. Simplify this problem a bit by first figuring out if there's a path. Then, modify your algo-
rithm to track the path. 

#388. Think again about the efficiency of your algorithm. Can you optimize it?
*/
#pragma endregion