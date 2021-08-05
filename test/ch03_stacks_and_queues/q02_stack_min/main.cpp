#pragma region Interview Question
/*
3.2 Stack Min: How would you design a stack which, in addition to push and pop, has a
function min which returns the minimum element? Push, pop, and min should all operate in
O(1) time.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#27. Observe that the minimum element doesn't change very often. It only changes when a 
smaller element is added, or when the smallest element is popped.

#59. What if we kept track of extra data at each stack node? What sort of data might 
make it easier to solve the problem?

#78. Consider having each node know the minimum of its "substack" (all the elements
beneath it, including itself).
*/
#pragma endregion

#include "StackWithNodeMin.h"
#include "StackWithStackMin.h"

#include <iostream>
#include <vector>

int main() {
    StackWithNodeMin<int> stack;
    StackWithStackMin<int> stack2;
    std::vector<int> array = {2, 1, 3, 1};
    for (int value : array) {
        stack.push(value);
        stack2.push(value);
        std::cout << std::to_string(value) + ", ";
    }
    std::cout << std::endl << std::endl;
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << "Popped " + std::to_string(stack.pop()) + ", " + std::to_string(stack2.pop()) << std::endl;
        std::cout << "New min is " + std::to_string(stack.min()) + ", " + std::to_string(stack2.min()) << std::endl;
    }
}