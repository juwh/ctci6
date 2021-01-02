#pragma region Interview Question
/*
8.10 Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,
fill in the surrounding area until the color changes from the original color. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#364. Think about this as a graph. 

#382. You can implement this using depth-first search (or breadth-first search). Each adjacent
pixel of the "right" color is a connected edge. 
*/
#pragma endregion