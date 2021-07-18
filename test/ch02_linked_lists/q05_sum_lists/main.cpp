#pragma region Interview Question
/*
2.5 Sum Lists: You have two numbers represented by a linked list, where each node 
contains a single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds the two numbers and returns the 
sum as a linked list.

EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
*/
#pragma endregion
#pragma region Hints
/*
Hints:
#7. Of course, you could convert the linked lists to integers, compute the sum, and then
convert it back to a new linked list. If you did this in an interview, your interviewer
would likely accept the answer, and then see if you could do this without converting it
to a number and back.

#30. Try recursion. Suppose you have two lists, A = 1->5->9 (representing 951) and B =
2->3->6->7 (representing 7632), and a function that operates on the remainder of the
lists (5->9 and 3->6->7). Could you use this to create the sum method? What is the
relationship between sum(1->5->9, 2->3->6->7) and sum(5->9, 3->6->7)?

#71. Make sure you have considered linked lists that are not the same length.

#95. Does your algorithm work on linked lists like 9->7->8 and 6->8->5? Double check
that.

#109. For the folow-up question: The issue is that when the linked lists aren't the same
length, the head of one linked list might represent the 1000's place while the other
represents the 10's place. What if you made them the same length? Is there a way to
modify the linked list to do that, without changing the value it represents?
*/
#pragma endregion

#include <ctcilib/LinkedListNode.h>

#include <iostream>
#include <tuple>

ctcilib::LinkedListNode<int> SumLists(const ctcilib::LinkedListNode<int>& l1, const ctcilib::LinkedListNode<int>& l2) {
    const ctcilib::LinkedListNode<int>* cur_l1{&l1};
    const ctcilib::LinkedListNode<int>* cur_l2{&l2};
    ctcilib::LinkedListNode<int>* out = new ctcilib::LinkedListNode<int>(0);
    int carry{0};

    while (cur_l1 || cur_l2) {
        int val_l1{cur_l1 ? cur_l1->data_ : 0};
        int val_l2{cur_l2 ? cur_l2->data_ : 0};
        int sum = val_l1 + val_l2 + carry;
        int digit = sum%10;
        carry = sum/10;
        out->push_back(digit);

        cur_l1 = cur_l1 ? cur_l1->next_: nullptr;
        cur_l2 = cur_l2 ? cur_l2->next_: nullptr;
    }

    if (carry) {
        out->push_back(carry);
    }

    // remove dummy head
    if (out->next_) {
        auto del_node{out};
        out = out->next_;

        // prep node for deletion
        del_node->next_ = nullptr;
        delete del_node;
    }
    return *out;
}

ctcilib::LinkedListNode<int> SumListsTwoPass(const ctcilib::LinkedListNode<int>& l1, const ctcilib::LinkedListNode<int>& l2) {
    const ctcilib::LinkedListNode<int>* cur_l1{&l1};
    const ctcilib::LinkedListNode<int>* cur_l2{&l2};
    ctcilib::LinkedListNode<int>* out = new ctcilib::LinkedListNode<int>(0);

    while (cur_l1 || cur_l2) {
        int val_l1{cur_l1 ? cur_l1->data_ : 0};
        int val_l2{cur_l2 ? cur_l2->data_ : 0};
        int sum = val_l1 + val_l2;
        out->push_back(sum);

        cur_l1 = cur_l1 ? cur_l1->next_: nullptr;
        cur_l2 = cur_l2 ? cur_l2->next_: nullptr;
    }

    ctcilib::LinkedListNode<int>* sec_pass{out};
    int carry{0};
    while (sec_pass) {
        if (carry) {
            sec_pass->data_ += carry;
        }
        if (sec_pass->data_ >= 10) {
            carry = sec_pass->data_/10;
            sec_pass->data_ %= 10;
        }
        sec_pass = sec_pass->next_;
    }

    if (carry) {
        out->push_back(carry);
    }

    // remove dummy head
    if (out->next_) {
        auto del_node{out};
        out = out->next_;

        // prep node for deletion
        del_node->next_ = nullptr;
        delete del_node;
    }
    return *out;
}

ctcilib::LinkedListNode<int>* SumListsRecursive(const ctcilib::LinkedListNode<int>* l1, const ctcilib::LinkedListNode<int>* l2, int carry) {
    if (!l1 && !l2 && !carry) {
        return nullptr;
    }

    int val_l1{l1 ? l1->data_ : 0};
    int val_l2{l2 ? l2->data_ : 0};
    int sum = val_l1 + val_l2 + carry;
    int next_carry = sum/10;

    auto next_node = SumListsRecursive(l1 ? l1->next_: nullptr, l2 ? l2->next_: nullptr, next_carry);
    return new ctcilib::LinkedListNode<int>(sum%10, next_node, nullptr);
}

ctcilib::LinkedListNode<int>* InsertBefore(ctcilib::LinkedListNode<int>* l, int data) {
    return new ctcilib::LinkedListNode<int>(data, l, nullptr);
}

ctcilib::LinkedListNode<int>* PadList(ctcilib::LinkedListNode<int>* l, size_t padding) {
    auto head = l;
    for (size_t i = 0; i < padding; i++) {
        head = InsertBefore(head, 0);
    }
    return head;
}

struct PartialSum {
    ctcilib::LinkedListNode<int>* sum_{nullptr};
    int carry_{0};
};

PartialSum SumListsForwardHelper(const ctcilib::LinkedListNode<int>* l1, const ctcilib::LinkedListNode<int>* l2) {
    if (!l1 || !l2) {
        return PartialSum();
    }

    PartialSum part_sum = SumListsForwardHelper(l1->next_, l2->next_);
    int digit_sum = l1->data_ + l2->data_ + part_sum.carry_;
    part_sum.sum_ = InsertBefore(part_sum.sum_, digit_sum%10);
    part_sum.carry_ = digit_sum/10;
    return part_sum;
}

ctcilib::LinkedListNode<int>* SumListsForward(const ctcilib::LinkedListNode<int>* l1, const ctcilib::LinkedListNode<int>* l2) {
    ctcilib::LinkedListNode<int>* copy_l1 = new ctcilib::LinkedListNode<int>(*l1);
    ctcilib::LinkedListNode<int>* copy_l2 = new ctcilib::LinkedListNode<int>(*l2);
    size_t length_l1{0}, length_l2{0};

    for (auto cur_l1 = l1; cur_l1; cur_l1 = cur_l1->next_, length_l1++) {}
    for (auto cur_l2 = l2; cur_l2; cur_l2 = cur_l2->next_, length_l2++) {}
    auto shorter = length_l1 > length_l2 ? PadList(copy_l2, length_l2 - length_l1) : PadList(copy_l1, length_l1 - length_l2);
    auto longer = length_l1 > length_l2 ? l1 : l2;

    PartialSum sum = SumListsForwardHelper(l1, l2);
    auto out = sum.sum_;
    if (sum.carry_) {out = InsertBefore(sum.sum_, sum.carry_);}
    return out;
}

int LinkedListToInt(const ctcilib::LinkedListNode<int>& node) {
    int value = 0;
    if (node.next_ != nullptr) {
        value = 10 * LinkedListToInt(*node.next_);
    }
    return value + node.data_;
}	

int main() {
    ctcilib::LinkedListNode<int> lA1(9, nullptr, nullptr);
    lA1.push_back(9);
    lA1.push_back(9);
    
    ctcilib::LinkedListNode<int> lB1(1, nullptr, nullptr);
    lB1.push_back(0);
    lB1.push_back(0);
    
    //auto list3 = SumLists(lA1, lB1);
    //auto list3 = SumListsTwoPass(lA1, lB1);
    //auto list3 = *SumListsRecursive(&lA1, &lB1, 0);
    auto list3 = *SumListsForward(&lA1, &lB1);
    
    std::cout << "  " << lA1.print_forward() << std::endl;	
    std::cout << "+ " << lB1.print_forward() << std::endl;	
    std::cout << "= " << list3.print_forward() << std::endl;			
    
    int l1 = LinkedListToInt(lA1);
    int l2 = LinkedListToInt(lB1);
    int l3 = LinkedListToInt(list3);
    
    std::cout << std::to_string(l1) << " + " << l2 << " = " << l3 << std::endl;
    std::cout << std::to_string(l1) << " + " << l2 << " = " << (l1 + l2) << std::endl;	
}