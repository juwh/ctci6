#pragma region Interview Question
/*
2.4 Partition: Write code to partition a linked list around a value x, such that all 
nodes less than x come before all nodes greater than or equal to x. If x is contained 
within the list, the values of x only need to be after the elements less than x (see 
below). The partition element x can appear anywhere in the "right partition"; it does 
not need to appear between the left and right partitions.

EXAMPLE
Input:	3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output:	3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#3. There are many solutions to this problem, most of which are equally optimal in
runtime. Some have shorter, cleaner code than others. Can you brainstorm different
solutions?

#24. Consider that the elements don't have to stay in the same relative order. We only 
need to ensure that elements less than the pivot must be before elements greater than
the pivot. Does that help you come up with more solutions?
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/LinkedListNode.h>

#include <iostream>
#include <vector>

ctcilib::LinkedListNode<int> PartitionSwap(const ctcilib::LinkedListNode<int>& node, const int& x) {
    auto out(node);
    auto part_ptr{&out};
    auto cur_ptr{&out};

    while (cur_ptr) {
        if (cur_ptr->data_ < x) {
            std::swap(cur_ptr->data_, part_ptr->data_);
            part_ptr = part_ptr->next_;
        }
        cur_ptr = cur_ptr->next_;
    }
    return out;
}

ctcilib::LinkedListNode<int> Partition(const ctcilib::LinkedListNode<int>& node, const int& x) {
    // memory leak as nodes in copy have been reordered, but copy will only delete next nodes
    // on dtor
    auto copy(node);
    ctcilib::LinkedListNode<int>* cur_ptr{&copy};
    ctcilib::LinkedListNode<int>* before_start{nullptr};
    ctcilib::LinkedListNode<int>* before_end{nullptr};
	ctcilib::LinkedListNode<int>* after_start{nullptr};
    ctcilib::LinkedListNode<int>* after_end{nullptr};
    
    /* Partition list */
    while (cur_ptr != nullptr) {
        ctcilib::LinkedListNode<int>* next = cur_ptr->next_;
        cur_ptr->next_ = nullptr;
        if (cur_ptr->data_ < x) {
            if (before_start == nullptr) {
                before_start = cur_ptr;
                before_end = before_start;
            } else {
                before_end->next_ = cur_ptr;
                before_end = cur_ptr;
            }
        } else {
            if (after_start == nullptr) {
                after_start = cur_ptr;
                after_end = after_start;
            } else {
                after_end->next_ = cur_ptr;
                after_end = cur_ptr;
            }
        }	
        cur_ptr = next;
    }
    
    ctcilib::LinkedListNode<int> out;

    /* Merge before list and after list */
    if (before_start == nullptr) {
        out = *after_start;
        return out;
    }
    
    before_end->next_ = after_start;
    out = *before_start;
    return out;
}

int main() {
    /* Create linked list */
	std::vector<int> vals{{3, 5, 8, 5, 10, 2, 1}};
    auto linked_list = ctcilib::create_linked_list_from_array(vals);

    std::cout << linked_list.print_forward() << std::endl;
	
    /* Partition */
    auto hA = PartitionSwap(LinkedListNode<int>(linked_list), 5);
    auto hB = Partition(LinkedListNode<int>(linked_list), 5);
    auto hC = Partition(LinkedListNode<int>(linked_list), 5);
    
    /* Print Result */
    std::cout << hA.print_forward() << std::endl;
    std::cout << hB.print_forward() << std::endl;
    std::cout << hC.print_forward() << std::endl;
}