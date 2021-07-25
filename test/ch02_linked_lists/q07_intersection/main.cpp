#pragma region Interview Question
/*
2.7 Intersection: Given two (singly) linked lists, determine if the two lists intersect.
Return the intersecting node. Note that the intersection is defined based on reference,
not value. That is, if the kth node of the first linked list is the exact same node (by
reference) as the jth node of the second linked list, then they are intersecting.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#20. You can do this in O(A+B) time and O(1) additional space. That is, you do not need
a hash table (although you could do it with one).

#45. Examples will help you. Draw a picture of intersecting linked lists and two
equivalent linked lists (by value) that do not intersect.

#55. Focus first on just identifying if there's an intersection.

#65. Observe that two intersecting linked lists will always have the same last node.
Once they intersect, all the nodes after that will be equal.

#76. You can determine if two linked lists intersect by traversing to the end of each
and comparing their tails.

#93. Now, you need to find where the linked lists intersect. Suppose the linked lists
were the same length. How could you do this?

#111. If the two linked lists were the same length, you could traverse forward in each
until you found an element in common. Now, how do you adjust this for lists of different
lengths?

#120. Try using the difference between the lengths of the two linked lists.

#129. If you move a pointer in the longer linked list forward by the difference in
lengths, you can then apply a similar approach to the scenario when the linked lists are
equal.
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/LinkedListNode.h>

#include <cstdlib>
#include <iostream>
#include <vector>

struct Result {
    const ctcilib::LinkedListNode<int>* tail_;
    size_t size_;
    Result(const ctcilib::LinkedListNode<int>* tail, size_t size) : tail_{tail}, size_{size} {}
};

Result GetTailAndSize(const ctcilib::LinkedListNode<int>& list) {
    size_t size{1};
    auto cur_node{&list};
    while (cur_node->next_) {
        cur_node = cur_node->next_;
        size++;
    }
    return Result(cur_node, size);
}

const ctcilib::LinkedListNode<int>* FindIntersection(const ctcilib::LinkedListNode<int>& list1, const ctcilib::LinkedListNode<int>& list2) {
    /* Get tail and sizes. */
    auto res_list1{GetTailAndSize(list1)};
    auto res_list2{GetTailAndSize(list2)};

    /* If different tail nodes, then there's no intersection. */
    if (res_list1.tail_ != res_list2.tail_) {
        return nullptr;
    }

    /* Set pointers to the start of each linked list. */
    int offset{abs(res_list1.size_ - res_list2.size_)};
    auto shorter{res_list1.size_ > res_list2.size_ ? &list2 : &list1};
    auto longer{res_list1.size_ > res_list2.size_ ? &list1 : &list2};

    /* Advance the pointer for the longer linked list by the difference in lengths. */
    for (int i{0}; i < offset; i++) {
        longer = longer->next_;
    }

    /* Move both pointers until you have a collision. */
    while (shorter != longer) {
        shorter = shorter->next_;
        longer = longer->next_;
    }
    return longer;
}

int main() {
    /* Create linked list */
    std::vector<int> vals{-1, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto list1{ctcilib::create_linked_list_from_array(vals)};
    
    std::vector<int> vals2 = {12, 14, 15};
    auto list2{ctcilib::create_linked_list_from_array(vals2)};
    
    list2.next_->next_ = list1.next_->next_->next_->next_;
    
    std::cout << list1.print_forward() << std::endl;
    std::cout << list2.print_forward() << std::endl;
    
    auto intersection{FindIntersection(list1, list2)};
    
    std::cout << intersection->print_forward() << std::endl;

    // reset to avoid double deletion
    list2.next_->next_ = nullptr;
}