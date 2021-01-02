#pragma region Interview Question
/*
10.9 Sorted Matrix Search: Given an M x N matrix in which each row and each column is sorted in
ascending order, write a method to find an element. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#193. Start with a naive solution. (But hopefully not too naive. You should be able to use the
fact that the matrix is sorted.) 

#211. We can do a binary search in each row. How long will this take? How can we do better? 

#229. If you're considering a particular column, is there a way to quickly eliminate it (in some
cases at least)? 

#251. Since each column is sorted, you know that the value can't be in this column if it's
smaller than the min value in this column. What else does this tell you? 

#266. If the value x is smaller than the start of the column, then it also can't be in any columns
to the right. 

#279. Think about the previous hint in the context of rows. 

#288. What would happen if we tried to keep track of this using an array? What are the pros
and cons of this? 

#291. Can we use the previous hints to move up, down, left, and right around the rows and
columns? 

#303. Another way to think about this is that if you drew a rectangle around a cell extending
to the bottom, right coordinate of the matrix, the cell would be bigger than all the items
in this square. 

#317. A cell will be larger than all the items below it and to the right. It will be smaller than all
cells above it and to the left. If we wanted to eliminate the most elements first, which
element should we compare the value x to? 

#330. If we compare x to the center element in the matrix, we can eliminate roughly one
quarter of the elements in the matrix. 
*/
#pragma endregion