#pragma region Interview Question
/*
3.1 Three in One: Describe how you could use a single array to implement three stacks.
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#2. A stack is simply a data structure in which the most recently added elements are
removed first. Can you simulate a single stack using an array? Remember that there are
many possible solutions, and there are tradeoffs of each.

#12. We could simulate three stacks in an array by just allocating the first third of 
the array to the first stack, the second third to the second stack, and the final third 
to the third stack. One might actually be much bigger than the others, though. Can we be
more flexible with the divisions?

#38. If you want to allow for flexible divisions, you can shift stacks around. Can you
ensure that all available capacity is used?

#58. Try thinking about the array as circular, such that the end of the array "wraps
around" to the start of the array.
*/
#pragma endregion

#include "FixedMultiStack.h"
#include "MultiStack.h"

#include <iostream>

void print_fixed_stacks(FixedMultiStack<int> stacks) {
    std::cout << ctcilib::array_to_string(stacks.get_values()) << std::endl;
}

void print_stacks(MultiStack<int> stacks) {
    std::cout << ctcilib::array_to_string(stacks.get_values()) << std::endl;
}

int main() {
    FixedMultiStack<int> stacks(4);
    print_fixed_stacks(stacks);
    stacks.push(0, 10);
    print_fixed_stacks(stacks);
    stacks.push(1, 20);
    print_fixed_stacks(stacks);
    stacks.push(2, 30);
    print_fixed_stacks(stacks);
    
    stacks.push(1, 21);
    print_fixed_stacks(stacks);
    stacks.push(0, 11);
    print_fixed_stacks(stacks);
    stacks.push(0, 12);
    print_fixed_stacks(stacks);
    
    stacks.pop(0);
    print_fixed_stacks(stacks);
    
    stacks.push(2, 31);
    print_fixed_stacks(stacks);
    
    stacks.push(0, 13);
    print_fixed_stacks(stacks);
    stacks.push(1, 22);
    print_fixed_stacks(stacks);
    
    stacks.push(2, 31);
    print_fixed_stacks(stacks);
    stacks.push(2, 32);
    print_fixed_stacks(stacks);

    MultiStack<int> stacks2(3, 4);
    print_stacks(stacks2);
    stacks2.push(0, 10);
    print_stacks(stacks2);
    stacks2.push(1, 20);
    print_stacks(stacks2);
    stacks2.push(2, 30);
    print_stacks(stacks2);
    
    stacks2.push(1, 21);
    print_stacks(stacks2);
    stacks2.push(0, 11);
    print_stacks(stacks2);
    stacks2.push(0, 12);
    print_stacks(stacks2);
    
    stacks2.pop(0);
    print_stacks(stacks2);
    
    stacks2.push(2, 31);
    print_stacks(stacks2);
    
    stacks2.push(0, 13);
    print_stacks(stacks2);
    stacks2.push(1, 22);
    print_stacks(stacks2);
    
    stacks2.push(2, 31);
    print_stacks(stacks2);
    stacks2.push(2, 32);
    print_stacks(stacks2);
    stacks2.push(2, 33);
    print_stacks(stacks2);
    stacks2.push(2, 34);
    print_stacks(stacks2);
    
    stacks2.pop(1);
    print_stacks(stacks2);
    stacks2.push(2, 35);
    print_stacks(stacks2);
    
    std::cout << "Final Stack: " + ctcilib::array_to_string(stacks2.get_values()) << std::endl;
}