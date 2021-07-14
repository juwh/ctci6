#pragma region Interview Question
/*
2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list.

FOLLOW UP
How would you solve this if a temporary buffer is not allowed?
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#9. Have you tried a hash table? You should be able to do this in a single pass of the
linked list.

#40. Without extra space, you'll need O(N^2) time. Try using two pointers, where the
second one searches ahead of the first one.
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/LinkedListNode.h>

#include <iostream>

int main() {
    LinkedListNode<int> first(0, nullptr, nullptr); //AssortedMethods.randomLinkedList(1000, 0, 2);
    LinkedListNode<int> head = first;
    LinkedListNode<int> second = first;
    for (int i = 1; i < 8; i++) {
        second = LinkedListNode<int>(i % 2, nullptr, nullptr);
        first.set_next(&second);
        second.set_previous(&first);
        first = second;
    }
    std::cout << head.print_forward() << std::endl;

    LinkedListNode cloneA(head);
    LinkedListNode cloneB(head);
    LinkedListNode cloneC(head);
    //QuestionA.deleteDups(cloneA);
    //QuestionA.deleteDups(cloneB);
    //QuestionA.deleteDups(cloneC);
    
    std::cout << cloneA.print_forward() << std::endl;
    std::cout << cloneB.print_forward() << std::endl;
    std::cout << cloneC.print_forward() << std::endl;
}