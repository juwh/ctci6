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

#include <iostream>
using namespace std;

struct node {
	node * next;
	int data;
};

node* nthToLast(node* head, int k, int& i) {
	if (head == NULL) {
		return NULL;
	}
	node * nd = nthToLast(head->next, k, i);
	i = i + 1;
	if (i == k) {
		return head;
	}
	return nd;
}

node* nthToLast(node* head, int k) {
	int i = 0;
	return nthToLast(head, k, i);
}

node* createList(int count) {
	node* head = new node();
	head->data = 0;
	node* last = head;
	for (int i = 1; i < count; i++) {
		node* n = new node();
		n->data = i;
		last->next = n;
		last = n;
	}
	return head;
}

void printList(node* head) {
	while (head != NULL) {
		printf("%d", head->data);
		head = head->next;
	}
}

int main() {
	int count = 5;
	node* head = createList(count);
	printList(head);
	printf("\n");
	for (int k = 0; k <= count; k++) {
		node* n = nthToLast(head, k);
		if (n != NULL) {
			int data = n->data;
			printf("%d: ", k);
			printf("%d", n->data);
			printf("\n");
		}
	}
	return 0;
}
