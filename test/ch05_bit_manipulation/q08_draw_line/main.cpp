#pragma region Interview Question
/*
5.8 Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive
pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will
be split across rows). The height of the screen, of course, can be derived from the length of the array
and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).

The method signature should look something like:
drawLine(byte[] screen, int width, int xl, int x2, int y) 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#366. First try the naive approach. Can you set a particular "pixel"? 

#381. When you're drawing a long line, you'll have entire bytes that will become a sequence of
1s. Can you set this all at once? 

#384. What about the start and end of the line? Do you need to set those pixels individually,
or can you set them all at once? 

#391. Does your code handle the case when xl and x2 are in the same byte? 
*/
#pragma endregion