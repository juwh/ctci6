#pragma region Interview Question
/*
2.6 Palindrome: Implement a function to check if a linked list is a palindrome.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#5. A palindrome is something which is the same when written forwards and backwards.
What if you reversed the linked list?

#13. Try using a stack.

#29. Assume you have the length of the linked list. Can you implement this recursively?

#61. In the recursive approach (we have the length of the list), the middle is the base
case: IsPermutation(middle) is true. The node x to the immediate left of the middle:
What can that node do to check if x->middle->y forms a palindrome? Now suppose that
checks out. What about the previous node a? If x->middle->y is a palindrome, how can it
check that a->x->middle->y->b is a palindrome?

#101. Go back to the previous hint. Remember: There are ways to return multiple values.
You can do this with a new class.
*/
#pragma endregion

#include <ctcilib/LinkedListNode.h>

#include <iostream>
#include <vector>

bool IsPalindrome(const ctcilib::LinkedListNode<int>& head) {
    return true;
}

bool IsPalindromeRecursive(const ctcilib::LinkedListNode<int>& head) {
    return true;
}

int main() {
    int max = 11;
    for (int length = 1; length < max; length++) {
        std::vector<ctcilib::LinkedListNode<int>> nodes(length);
        for (int i = 0; i < length; i++) {
            nodes[i] = ctcilib::LinkedListNode<int>(i >= length / 2 ? length - i - 1 : i, nullptr, nullptr);
        }
        
        for (int i = 0; i < length; i++) {
            if (i < length - 1) {
                nodes[i].set_next(&nodes[i + 1]);
            }
            if (i > 0) {
                nodes[i].set_previous(&nodes[i - 1]);
            }
        }
        for (int i = -1; i < length; i++) {
            if (i >= 0) {
                nodes[i].data_++; // Ruin palindrome
            }
            
            ctcilib::LinkedListNode<int> head = nodes[0];
            std::cout << head.print_forward() << std::endl;
            bool result_a = IsPalindrome(head);
            bool result_b = IsPalindrome(head);
            bool result_c = IsPalindromeRecursive(head);
            std::cout << "A: " << result_a << std::endl;
            std::cout << "B: " << result_b << std::endl;
            std::cout << "C: " << result_c << std::endl;
            if (result_a != result_b || result_b != result_c) {
                std::cout << "ERROR" << std::endl;
                length = max;
                break;
            }
            if (i >= 0) {
                nodes[i].data_--;
            }
        }
        // clear node from end to head to avoid deleted node conflicts
        for (int i = length - 2; i >= 0; i--) {
            nodes.pop_back();
            nodes[i].set_next(nullptr);
        }
    }
}