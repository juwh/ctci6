#pragma region Interview Question
/*
4.6 Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#79. Think about how an in-order traversal works and try to "reverse engineer" it. 

#91. Here's one step of the logic: The successor of a specific node is the leftmost node of the
right subtree. What if there is no right subtree, though? 
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <iostream>
#include <vector>

ctcilib::TreeNode<int>* left_most_child(ctcilib::TreeNode<int>* n) {
    if (!n) {return nullptr;}
    while (n->left_) {
        n = n->left_;
    }
    return n;
}

ctcilib::TreeNode<int>* inorder_succ(ctcilib::TreeNode<int>* n) {
    if (!n) {return nullptr;}
    if (n->right_) {
        return left_most_child(n->right_);
    } else {
        auto parent{n->parent_};
        while (parent && parent->right_ == n) {
            parent = parent->parent_;
            n = n->parent_;
        }
        return parent;
    }
}

int main() {
    // if no right child, up parent until not left child, return parent data
    // if right child has left, get left-most to get successor
    std::vector<int> array{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
	ctcilib::TreeNode<int> root(array);
	for (size_t i = 0; i < array.size(); i++) {
		ctcilib::TreeNode<int>* node = root.find(array[i]);
		ctcilib::TreeNode<int>* next = inorder_succ(node);
		if (next != nullptr) {
			std::cout << std::to_string(node->data_) + "->" + std::to_string(next->data_) << std::endl;
		} else {
			std::cout << std::to_string(node->data_) + "-> N/A" << std::endl;
		}
	}
}