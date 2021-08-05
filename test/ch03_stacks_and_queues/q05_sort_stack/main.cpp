#pragma region Interview Question
/*
3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the
top. You can use an additional temporary stack, but you may not copy the elements into
any other data structure (such as an array). The stack supports operations: push, pop,
peek, and isEmpty.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#15. One way of sorting an array is to iterate through the array and insert each element
into a new array in sorted order. Can you do this with a stack?

#32. Imagine your secondary stack is sorted. Can you insert elements into it in sorted 
order? You might need some extra storage. What could you use for extra storage?

#43. Keep the secondary stack in sorted order, with the biggest elements on the top. Use
the primary stack for additional storage.
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>

#include <iostream>
#include <stack>

void sort(std::stack<int>& s) {
    std::stack<int> r;
    while (!s.empty()) {
        auto tmp{s.top()};
        s.pop();
        while (!r.empty() && tmp < r.top()) {
            s.push(r.top());
            r.pop();
        }
        r.push(tmp);
    }

    while (!r.empty()) {
        s.push(r.top());
        r.pop();
    }
}

int main() {
    std::stack<int> s;
    for (int i = 0; i < 10; i++) {
        int r = ctcilib::random_int_in_range(0,  1000);
        s.push(r);
    }
    
    sort(s);
    
    while(!s.empty()) {
        std::cout << std::to_string(s.top()) << std::endl;
        s.pop();
    }
}