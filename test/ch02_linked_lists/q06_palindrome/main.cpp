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
#include <stack>
#include <tuple>
#include <vector>

bool IsEqual(const ctcilib::LinkedListNode<int>& one, const ctcilib::LinkedListNode<int>& two) {
    for (auto [cur_one, cur_two] = std::make_tuple(&one, &two); cur_one; cur_one = cur_one->next_, cur_two = cur_two->next_) {
        if (cur_one->data_ != cur_two->data_) {
            return false;
        }
    }
    return true;
}

ctcilib::LinkedListNode<int> ReverseAndClone(const ctcilib::LinkedListNode<int>& head) {
    ctcilib::LinkedListNode<int> out(head.data_);
    auto cur_node{head.next_};
    while (cur_node) {
        out.push_front(cur_node->data_);
        cur_node = cur_node->next_;
    }
    return out;
}

bool IsPalindromeReverse(const ctcilib::LinkedListNode<int>& head) {
    auto reverse{ReverseAndClone(head)};
    return IsEqual(head, reverse);
}

bool IsPalindromeRunnerStack(const ctcilib::LinkedListNode<int>* head) {
    auto slow{head};
    auto runner{head};
    std::stack<const ctcilib::LinkedListNode<int>*> reverse;
    while (runner && runner->next_) {
        reverse.push(slow);
        slow = slow->next_;
        runner = runner->next_->next_;
    }

    if (runner) {
        slow = slow->next_;
    }

    while (reverse.size() && slow) {
        if (slow->data_ != reverse.top()->data_) {
            return false;
        }
        reverse.pop();
        slow = slow->next_;
    }
    return true;
}

struct Result {
    ctcilib::LinkedListNode<int>* node_;
    bool result_;
};

Result IsPalindromeRecursiveHelper(ctcilib::LinkedListNode<int>* slow, ctcilib::LinkedListNode<int>* fast) {
    if (!fast) {
        return Result{slow, true};
    }

    if (!fast->next_) {
        return Result{slow->next_, true};
    }

    auto res = IsPalindromeRecursiveHelper(slow->next_, fast->next_->next_);
    if (!res.result_) {
        return res;
    }

    if (slow->data_ != res.node_->data_) {
        res.result_ = false;
    }
    res.node_ = res.node_->next_;
    return res;
}

bool IsPalindromeRecursive(ctcilib::LinkedListNode<int>* head) {
    auto res{IsPalindromeRecursiveHelper(head, head)};
    return res.result_;
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
            bool result_a = IsPalindromeReverse(head);
            bool result_b = IsPalindromeRunnerStack(&head);
            bool result_c = IsPalindromeRecursive(&head);
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

        for (int i = nodes.size() - 1; i > 0; i--) {
            nodes.pop_back();
            nodes[i-1].set_next(nullptr);
        }
    }
}