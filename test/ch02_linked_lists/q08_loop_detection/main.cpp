#pragma region Interview Question
/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns 
the node at the beginning of the loop.

DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to 
an earlier node, so as to make a loop in the linked list.

EXAMPLE
Input:	A -> B -> C -> D -> E -> C [the same C as earlier]
Output:	C
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#50. There are really two parts to this problem. First, detect if the linked list has a
loop. Second figure out where the loop starts.

#69. To identify if there's a cycle, try the "runner" approach described on page 93. 
Have one pointer move faster than the other.

#83. You can use two pointers, one moving twice as fast as the other. If there is a
cycle, the two pointers will collide. They will land at the same location at the same
time. Where do they land? Why there?

#90. If you haven't identified the pattern of where the two pointers start, try this: 
Use the linked list 1->2->3->4->5->6->7->8->9->?, where the ? links to another node. Try
making the ? the first node (that is, the 9 points to the 1 such that the entire linked
list is a loop). Then make the ? the node 2. Then the node 3. Then the node 4. What is
the pattern? Can you explain why this happens?
*/
#pragma endregion

#include <ctcilib/LinkedListNode.h>

#include <iostream>
#include <vector>

const ctcilib::LinkedListNode<int>* FindBeginning(const ctcilib::LinkedListNode<int>* head) {
    auto slow{head};
    auto runner{head};

    // Find meeting point
    while (runner && runner->next_) {
        slow = slow->next_;
        runner = runner->next_->next_;
        if (slow == runner) {
            break;
        }
    }

    // Error check - there is no meeting point, and therefore no loop
    if (!runner || !runner->next_) {
        return nullptr;
    }

    /* x is the distance from start to loop start. y is the distance
     * from loop start to meeting point. z is the distance back to
     * loop start. Both nodes are at point x + y in the node list 
     * when they meet. The runner has traveled x + y + z + y nodes
     * while the slower node has traveled x + y nodes. Knowing the
     * node speeds, we can set the distance equal to eachother.
     * x + 2y + z = 2(x + y) -> z = x. Knowing the distance from the
     * start and meeting point to the start of the loop are the same,
     * we can move from those points equally until a convergence
     * to determine the start of the loop. */
    slow = head;
    while (slow != runner) {
        slow = slow->next_;
        runner = runner->next_;
    }
    
    // Both now point to the start of the loop.
    return slow;
}

int main() {
    size_t list_length{100};
    size_t k{10};
    
    // Create linked list
    std::vector<ctcilib::LinkedListNode<int>*> nodes(list_length);
    for (size_t i = 0; i < list_length; i++) {
        nodes[i] = new ctcilib::LinkedListNode<int>(i, nullptr, i > 0 ? nodes[i - 1] : nullptr);
    }
    
    // Create loop;
    nodes[list_length - 1]->next_ = nodes[list_length - k];
    
    auto loop = FindBeginning(nodes[0]);
    if (loop == nullptr) {
        std::cout << "No Cycle." << std::endl;
    } else {
       std::cout << std::to_string(loop->data_) << std::endl;
    }
}