#pragma region Interview Question
/*
2.3 Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., 
any node but the first and last node, not necessarily the exact middle) of a singly
linked list, given only access to that node.

EXAMPLE
Input: the node c from the linked list a->b->c->d->e->f
Result: nothing is returned, but the new linked list looks like a->b->d->e->f
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#72. Picture the list 1->5->9->12. Removing 9 would make it look like 1->5->12. You only
have access to the 9 node. Can you make it look like the correct answer?
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/LinkedListNode.h>

#include <iostream>

void DeleteNode(ctcilib::LinkedListNode<int>* node) {
    if (node && node->next_) {
        node->data_ = node->next_->data_;
        auto del_node = node->next_;
        node->set_next(del_node->next_);
        if (node->next_) {
            node->next_->set_previous(node);
        }
        del_node->next_ = nullptr;
        delete del_node;
    }
    
}

int main() {
    ctcilib::LinkedListNode<int> head = ctcilib::random_linked_list(10, 0, 10);
    std::cout << head.print_forward() << std::endl;
	DeleteNode(head.next_->next_->next_->next_); // delete node 4 (index 0)
	std::cout << head.print_forward() << std::endl;
}