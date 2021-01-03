#pragma region Interview Question
/*
17.21 Volume of Histogram: Imagine a histogram (bar graph). Design an algorithm to compute the
volume of water it could hold if someone poured water across the top. You can assume that each
histogram bar has width 1.

EXAMPLE (Black bars are the histogram. Gray is water.)
Input: {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0}
Output: 26 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#629. What role does the tallest bar in the histogram play?

#640. Picture the tallest bar, and then the next tallest bar on the left and the next tallest bar on
the right. The water will fill the area between those. Can you calculate that area? What
do you do about the rest?

#651. You can calculate the area between the tallest bar overall and the tallest bar on the left
by just iterating through the histogram and subtracting out any bars in between. You
can do the same thing with the right side. How do you handle the remainder of the
graph?

#658. You can handle the remainder of the graph by just repeating this process: find the tallest
bar and the second tallest bar, and subtract out the bars in between.

#662. How can you make the process of finding the next tallest bar on each side faster?

#676. Can you do precomputation to compute the next tallest bar on each side?

#693. As an alternative solution, think about it from the perspective of each bar. Each bar will
have water on top of it. How much water will be on top of each bar?

#734. Each bar will have water on top of it that matches the minimum of the tallest bar on the
left and the tallest bar on the right. That is, water_on_top[i] = min(tallest_
bar(0->i), tallest_bar(i, n)).

#742. You should be able to solve this in O(N) time and O(N) space.
*/
#pragma endregion