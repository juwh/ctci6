#pragma region Interview Question
/*
15.3 Dining Philosophers: In the famous dining philosophers problem, a bunch of philosophers are
sitting around a circular table with one chopstick between each of them. A philosopher needs
both chopsticks to eat. and always picks up the left chopstick before the right one. A deadlock
could potentially occur if all the philosophers reached for the left chopstick at the same time. Using
threads and locks, implement a simulation of the dining philosophers problem that prevents deadlocks. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#419. A deadlock can happen when there's a "cycle" in the order of who is waiting for whom.
How can we break or prevent this cycle? 

#437. One idea is to just not let a philosopher hold onto a chopstick if he can't get the other
one. 
*/
#pragma endregion