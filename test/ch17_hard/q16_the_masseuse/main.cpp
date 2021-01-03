#pragma region Interview Question
/*
17.16 The Masseuse: A popular masseuse receives a sequence of back-to-back appointment requests
and is debating which ones to accept. She needs a 15-minute break between appointments and
therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appoint-
ment requests (all multiples of 15 minutes, none overlap, and none can be moved), find the optimal
(highest total booked minutes) set the masseuse can honor. Return the number of minutes.

EXAMPLE
Input: {30, 15, 60, 75, 45, 15, 15, 45}
Output: 180 minutes ({30, 60, 45, 45}). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#495. There are recursive and iterative solutions to this problem, but it's probably easier to
start with the recursive solution.

#504. Recursive solution: You have two choices at each appointment (take the appointment
or reject the appointment). As a brute force approach, you can recurse through all possi-
bilities. Note, though, that if you take request i, your recursive algorithm should skip
request i + 1.

#516. Recursive solution: You can optimize this approach through memoization. What is the
runtime of this approach?

#526. Recursive solution: The runtime of your memoization approach should be O(N), with
O(N) space.

#542. Iterative solution: Take the recursive solution and investigate it more. Can you imple-
ment a similar strategy iteratively?

#554. Iterative solution: It's probably easiest to start with the end of the array and work back-
wards.

#562. Iterative solution: Observe that you would never skip three appointments in a row. Why
would you? You would always be able to take the middle booking.

#568. Iterative solution: If you take appointment i, you will never take appointment i + 1,
but you will always take appointment i + 2 or i + 3.

#578. Iterative solution: Use an example and work backwards. You can easily find the optimal
solution for the subarrays {r_(n)}, {r_(n-1), r_(n)}, {r_(n-2), ..., r_(n)}. How would you use
those to quickly find the optimal solution for {r_(n-3), ..., r_(n)}?

#587. Iterative solution: If you take an appointment, you can't take the next appointment, but
you can take anything after that. Therefore, optimal (r_(i), ..., r_(n)) = max(r_(i) +
optimal(r_(i+2), ..., r_(n)), optimal(r_(i+1), ..., r_(n))). You can solve this itera-
tively by working backwards.

#607. Iterative solution: If you're careful about what data you really need, you should be able
to solve this in O(n) time and O(1) additional space.
*/
#pragma endregion