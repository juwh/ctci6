#pragma region Interview Question
/*
9.2 Social Network: How would you design the data structures for a very large social network like Face-
book or Linkedln? Describe how you would design an algorithm to show the shortest path between
two people (e.g., Me -> Bob -> Susan -> Jason -> You). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#270. To find the connection between two nodes, would it be better to do a breadth-first
search or depth-first search? Why? 

#285. A breadth-first search is probably better. A depth-first search can wind up going on a
long path, even though the shortest path is actually very short. Is there a modification
to a breadth-first search that might be even faster? 

#304. Is there any way to search from both the source and destination? For what reason or in
what case might this be faster? 

#321. Discuss how you might implement these algorithms and this system in the real world.
What sort of optimizations might you make? 
*/
#pragma endregion