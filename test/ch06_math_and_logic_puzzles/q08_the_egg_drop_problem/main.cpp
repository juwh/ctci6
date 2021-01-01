#pragma region Interview Question
/*
6.8 The Egg Drop Problem: There is a building of 100 floors. If an egg drops from the Nth floor or
above, it will break. If it's dropped from any floor below, it will not break. You're given two eggs. Find
N, while minimizing the number of drops for the worst case. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#156. This is really an algorithm problem, and you should approach it as such. Come up with
a brute force, compute the worst-case number of drops, then try to optimize that. 

#233. As a first approach, you might try something like binary search. Drop it from the 50th
floor, then the 75th, then the 88th, and so on. The problem is that if the first egg drops
at the 50th floor, then you'll need to start dropping the second egg starting from the 1st
floor and going up. This could take, at worst, 50 drops (the 50th floor drop, the 1st floor
drop, the 2nd floor drop, and up through the 49th floor drop). Can you beat this? 

#294. It's actually better for the first drop to be a bit lower. For example, you could drop at the
10th floor, then the 20th floor, then the 30th floor, and so on. The worst case here will be
19 drops (10, 20, ..., 100, 91,92, ..., 99). Can you beat that? Try not randomly guessing at
different solutions. Rather, think deeper. How is the worst case defined? How does the
number of drops of each egg factor into that? 

#333. If we drop Egg 1 at fixed intervals (e.g., every 10 floors), then the worst case is the worst
case for Egg 1 + the worst case for Egg 2. The problem with our earlier solutions is that as
Egg 1 does more work, Egg 2 doesn't do any less work. Ideally, we'd like to balance this
a bit. As Egg 1 does more work (has survived more drops), Egg 2 should have less work
to do. What might this mean?  

#357. Try dropping Egg 1 at bigger intervals at the beginning and then at smaller and smaller
intervals. The idea is to keep the sum of Egg 1 and Egg 2's drops as constant as possible.
For each additional drop that Egg 1 takes, Egg 2 takes one fewer drop. What is the right
interval? 

#374. Let X be the first drop of Egg 1. This means that Egg 2 would do X - 1 drops if Egg 1
broke. We want to try to keep the sum of Egg 1 and Egg 2's drops as constant as possible. If
Egg 1 breaks on the second drop, then we want Egg 2 to do X - 2 drops. If Egg 1 breaks
on the third drop, then we want Egg 2 to do X - 3 drops. This keeps the sum of Egg 1 and
Egg 2 fairly constant. What is X? 

#395. I got 14 drops in the worst case. What did you get? 
*/
#pragma endregion