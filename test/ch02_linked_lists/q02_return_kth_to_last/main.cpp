#pragma region Interview Question
/*
2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a
singly linked list.
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#8. What if you knew the linked list size? What is the difference between finding the
Kth-to-last element and finding the Xth element?

#25. If you don't know the linked list size, can you compute it? How does this impact the
runtime?

#41. Try implementing it recursively. If you could find the (K-1)th to last element, can
you find the Kth element?

#67. You might find it useful to return multiple values. Some languages don't directly
support this, but there are workarounds in essentially any language. What are some of
those workarounds?

#126. Can you do it iteratively? Imagine if you had two pointers pointing to adjacent
nodes and they were moving at the same speed through the linked list. When one hits the
end of the linked list, where will the others be?
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/LinkedListNode.h>

#include <iostream>
#include <vector>

ctcilib::LinkedListNode<int>* KthToLastRecursive(ctcilib::LinkedListNode<int>* head, size_t k, size_t& i) {
	if (!head) {
		return nullptr;
	}
	auto node = KthToLastRecursive(head->next_, k, i);
	i += 1;
	if (i == k) {
		return head;
	}
	return node;
}

// k beyond linked list size returns nullptr
ctcilib::LinkedListNode<int>* KthToLast(ctcilib::LinkedListNode<int>* head, size_t k) {
	size_t i = 0;
	return KthToLastRecursive(head, k, i);
}

ctcilib::LinkedListNode<int>* KthToLastIterative(ctcilib::LinkedListNode<int>* head, size_t k) {
	if (k == 0) {
		return nullptr;
	}

	ctcilib::LinkedListNode<int>* cur_ptr{head};
	ctcilib::LinkedListNode<int>* run_ptr{head};
	for (size_t i = 1; i < k; i++) {
		if (!cur_ptr->next_) {
			return nullptr;
		}
		cur_ptr = cur_ptr->next_;
	}

	while (cur_ptr->next_) {
		cur_ptr = cur_ptr->next_;
		run_ptr = run_ptr->next_;
	}
	return run_ptr;
}

int main() {
	std::vector<int> array = {0, 1, 2, 3, 4, 5, 6};
	ctcilib::LinkedListNode<int> head = ctcilib::create_linked_list_from_array(array);
	for (size_t i = 0; i <= array.size() + 1; i++) {
		ctcilib::LinkedListNode<int>* node = KthToLast(&head, i);
		//ctcilib::LinkedListNode<int>* node = KthToLastIterative(&head, i);
		std::string node_value = !node ? "nullptr" : std::to_string(node->data_);
		std::cout << std::to_string(i) + ": " + node_value << std::endl;
	}
}
