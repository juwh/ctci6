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
#include <unordered_set>

void DeleteDups(ctcilib::LinkedListNode<int>& head) {
    std::unordered_set<int> list_set;
    ctcilib::LinkedListNode<int>* cur_ptr{&head};
    ctcilib::LinkedListNode<int>* prev_ptr{nullptr};
    while (cur_ptr) {
        if (list_set.count(cur_ptr->data_) == 0) {
            list_set.insert(cur_ptr->data_);
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->next_;
        } else {
            // maintain pointer to node marked for deletion
            ctcilib::LinkedListNode<int>* del_ptr{cur_ptr};
            cur_ptr = cur_ptr->next_;
            prev_ptr->set_next(cur_ptr);
            // attempt set_previous only if newly set ptr is not nullptr
            if (cur_ptr) {
                cur_ptr->set_previous(prev_ptr);
            }
            // set next_ to nullptr before deletion due to dtor impl
            del_ptr->set_next(nullptr);
            delete del_ptr;
        }
    }
}

void DeleteDupsPrimitive(ctcilib::LinkedListNode<int>& head) {
    ctcilib::LinkedListNode<int>* cur_ptr{&head};
    while (cur_ptr) {
        ctcilib::LinkedListNode<int>* run_ptr{cur_ptr};
        while (run_ptr->next_) {
            if (cur_ptr->data_ == run_ptr->next_->data_) {
                // maintain pointer to node marked for deletion
                ctcilib::LinkedListNode<int>* del_ptr{run_ptr->next_};
                run_ptr->set_next(run_ptr->next_->next_);
                // attempt set_previous only if newly set ptr is not nullptr
                if (run_ptr->next_) {
                    run_ptr->next_->set_previous(run_ptr);
                }
                // set next_ to nullptr before deletion due to dtor impl
                del_ptr->set_next(nullptr);
                delete del_ptr;
            } else {
                run_ptr = run_ptr->next_;
            }
        }
        cur_ptr = cur_ptr->next_;
    }
}

void DeleteDupsBackwards(LinkedListNode<int>& head) {
    /*
    if (head == null) return;
    LinkedListNode previous = head;
    LinkedListNode current = previous.next;
    while (current != null) {
        // Look backwards for dups, and remove any that you see.
        LinkedListNode runner = head;
        while (runner != current) { 
            if (runner.data == current.data) {
                LinkedListNode tmp = current.next;
                previous.next = tmp;
                current = tmp;
                // We know we can't have more than one dup preceding
                // our element since it would have been removed 
                // earlier.
                break;
            }
            runner = runner.next;
        }
        
        // If runner == current, then we didn't find any duplicate 
        // elements in the previous for loop.  We then need to 
        // increment current.  
        // If runner != current, then we must have hit the �break� 
        // condition, in which case we found a dup and current has
        // already been incremented.
        if (runner == current) {
            previous = current;
            current = current.next;
        }
    }
    */
};

int main() {
    ctcilib::LinkedListNode<int> head(0);
    //LinkedListNode<int>* first = &head; //AssortedMethods.randomLinkedList(1000, 0, 2);
    //LinkedListNode<int>* second = first;
    for (int i = 1; i < 8; i++) {
        /*
        second = new LinkedListNode<int>(i % 2, nullptr, nullptr);
        first->set_next(second);
        second->set_previous(first);
        first = second;
        */
       head.push_back(i % 2);
    }
    std::cout << head.print_forward() << std::endl;

    ctcilib::LinkedListNode cloneA(head);
    ctcilib::LinkedListNode cloneB(head);
    ctcilib::LinkedListNode cloneC(head);
    DeleteDupsPrimitive(cloneA);
    DeleteDups(cloneB);
    //DeleteDupsBackwards(cloneC);
    
    std::cout << cloneA.print_forward() << std::endl;
    std::cout << cloneB.print_forward() << std::endl;
    std::cout << cloneC.print_forward() << std::endl;
}