#pragma region Interview Question
/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns 
the node at the beginning of the loop.

DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to 
an earlier node, so as to make a loop in the linked list.

EXAMPLE
Input:	A -> B -> C -> D -> E -> C [the same C as earlier]
Output:	C
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#50. There are really two parts to this problem. First, detect if the linked list has a
loop. Second figure out where the loop starts.

#69. To identify if there's a cycle, try the "runner" approach described on page 93. 
Have one pointer move faster than the other.

#83. You can use two pointers, one moving twice as fast as the other. If there is a
cycle, the two pointers will collide. They will land at the same location at the same
time. Where do they land? Why there?

#90. If you haven't identified the pattern of where the two pointers start, try this: 
Use the linked list 1->2->3->4->5->6->7->8->9->?, where the ? links to another node. Try
making the ? the first node (that is, the 9 points to the 1 such that the entire linked
list is a loop). Then make the ? the node 2. Then the node 3. Then the node 4. What is
the pattern? Can you explain why this happens?
*/
#pragma endregion