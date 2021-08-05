#pragma region Interview Question
/*
3.4 Queue via Stacks: Implement a MyQueue class which implements a queue using two 
stacks.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#98. The major difference between a queue and a stack is the order of elements. A queue
removes the oldest item and a stack removes the newest item. How could you remove the
oldest item from a stack if you only had access to the newest item?

#114. We can remove the oldest item from a stack by repeatedly removing the newest item
(iunserting those into the temporary stack) until we get down to one element. Then after
we've retrieved the newest item, putting all the elements back. The issue with this is
that doing several pops in a row will require O(N) work each time. Can we optimize for
scenarios where we might do several pops in a row?
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include "MyQueue.h"

#include <iostream>
#include <queue>

int main() {
    MyQueue<int> my_queue;	
		
    // Let's test our code against a "real" queue
    std::queue<int> test_queue;
    
    for (int i = 0; i < 100; i++) {
        int choice{ctcilib::random_int_in_range(0, 10)};
        if (choice <= 5) { // enqueue
            int element{ctcilib::random_int_in_range(1, 10)};
            test_queue.push(element);
            my_queue.add(element);
            std::cout << "Enqueued " + std::to_string(element) << std::endl;
        } else if (test_queue.size() > 0) {
            int top1{test_queue.front()};
            test_queue.pop();
            int top2{my_queue.remove()};
            if (top1 != top2) { // Check for error
                std::cout << "******* FAILURE - DIFFERENT TOPS: " + std::to_string(top1) + ", " + std::to_string(top2) << std::endl;
            } 
            std::cout << "Dequeued " + std::to_string(top1) << std::endl;
        }
        
        if (test_queue.size() == my_queue.size()) {
            if (test_queue.size() > 0 && test_queue.front() != my_queue.peek()) {
                std::cout << "******* FAILURE - DIFFERENT TOPS: " + std::to_string(test_queue.front()) + ", " + std::to_string(my_queue.peek()) + " ******" << std::endl;
            }
        } else {
            std::cout << "******* FAILURE - DIFFERENT SIZES ******" << std::endl;
        }
    }
}