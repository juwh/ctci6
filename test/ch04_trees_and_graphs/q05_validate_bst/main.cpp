#pragma region Interview Question
/*
4.5 Validate BST: Implement a function to check if a binary tree is a binary search tree. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#35. If you traversed the tree using an in-order traversal and the elements were truly in
the right order, does this indicate that the tree is actually in order? What happens for
duplicate elements? If duplicate elements are allowed, they must be on a specific side
(usually the left). 

#57. To be a binary search tree, it's not sufficient that the left.value <= current.
value < right.value for each node. Every node on the left must be less than the
current node, which must be less than all the nodes on the right. 

#86. If every node on the left must be less than or equal to the current node, then this is really
the same thing as saying that the biggest node on the left must be less than or equal to
the current node. 

#113. Rather than validating the current node's value against leftTree.max and
rightTree.min, can we flip around the logic? Validate the left tree's nodes to ensure
that they are smaller than current.value.  

#128. Think about the checkBST function as a recursive function that ensures each node is
within an allowable (min J max) range. At first, this range is infinite. When we traverse
to the left, the min is negative infinity and the max is root. value. Can you implement
this recursive function and properly adjust these ranges as you traverse the tree? 
*/
#pragma endregion

#include <ctcilib/assorted_methods.h>
#include <ctcilib/TreeNode.h>

#include <iostream>
#include <limits>
#include <vector>

bool check_bst_inorder_recurse(ctcilib::TreeNode<int>* node, int*& last_printed) {
    if (!node) {
        return true;
    }
    if (!check_bst_inorder_recurse(node->left_, last_printed)) {
        return false;
    };
    if (last_printed && node->data_ < *last_printed) {
        return false;
    }
    last_printed = &node->data_;
    if (!check_bst_inorder_recurse(node->right_, last_printed)) {
        return false;
    };
    return true;
}

bool check_bst_inorder(ctcilib::TreeNode<int>* node) {
    int* init_ptr{nullptr};
    return check_bst_inorder_recurse(node, init_ptr);
}

bool check_bst_recurse(ctcilib::TreeNode<int>* n, int min, int max) {
    if (!n) {
        return true;
    }
    // account for overflow of int range
    if (n->data_ == std::numeric_limits<int>::max() && n->right_) {
        return false;
    }
    return n->data_ >= min && n->data_ <= max && check_bst_recurse(n->left_, min, n->data_) && check_bst_recurse(n->right_, n->data_ + 1, max);
}

bool check_bst(ctcilib::TreeNode<int>* n) {
    return check_bst_recurse(n, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

/* Create a tree that may or may not be a BST */
TreeNode<int> create_test_tree() {
    /* Create a random BST */
    TreeNode<int> head{ctcilib::random_bst(10, -10, 10)}; 
    
    /* Insert an element into the BST and potentially ruin the BST property */
    TreeNode<int>* node{&head};
    do {
        int n{ctcilib::random_int_in_range(-10, 10)};
        int rand{ctcilib::random_int_in_range(0, 5)};
        if (rand == 0) {
            node->data_ = n;
        } else if (rand == 1) {
            node = node->left_;
        } else if (rand == 2) {
            node = node->right_;
        } else if (rand == 3 || rand == 4) {
            break;
        }
    } while (node != nullptr);	
    
    return head;
}

void test() {
    bool condition;
    std::cout << "test cases for equals condition." << std::endl;

	/* Expect true: for left child: node.data <= last_printed.
   2
  / \
 /   \
 2   3
      \
      4
	*/

    std::vector<int> array2{{1, 2, 3, 4}};
    ctcilib::TreeNode<int> node2(array2);
    node2.left_->data_ = 2;
    node2.print();
    condition = check_bst_inorder(&node2);
    std::cout << "should be true: " + std::to_string(condition) << std::endl;

	/* Expect false: for right child: node.data <= last_printed.
   2
  / \
 /   \
 1   2
      \
      4
    */
    std::vector<int> array3{{1, 2, 3, 4}};
    ctcilib::TreeNode<int> node3(array3);
    node3.right_->data_ = 2;
    node3.print();
    condition = check_bst_inorder(&node3);
    std::cout << "should be false: " + std::to_string(condition) << std::endl;
}

int main() {
    std::vector<int> array{{std::numeric_limits<int>::min(), std::numeric_limits<int>::max() - 2, std::numeric_limits<int>::max() - 1, std::numeric_limits<int>::max()}};
    ctcilib::TreeNode<int> node(array);
    //node.left->data_ = 5;
    //node.left->right_->data = 3;
    std::cout << check_bst_inorder(&node) << std::endl;

    test();

    /* Simple test -- create one */
    std::vector<int> array2{{std::numeric_limits<int>::min(), 3, 5, 6, 10, 13, 15, std::numeric_limits<int>::max()}};
    ctcilib::TreeNode<int> node2(array2);
    //node.left_->data_ = 6; // "ruin" the BST property by changing one of the elements
    node2.print();
    bool is_bst{check_bst(&node2)};
    std::cout << std::to_string(is_bst) <<std::endl;
    
    /* More elaborate test -- creates 100 trees (some BST, some not) and compares the outputs of various methods. */
    /*for (int i = 0; i < 100; i++) {
        TreeNode<int> head{create_test_tree()};
        
        // Compare results 
        bool is_bst1 = check_bst(&head);
        bool is_bst2 = check_bst_inorder(&head);
        
        if (is_bst1 != is_bst2) {
            std::cout << "*********************** ERROR *******************" << std::endl;
            std::cout << std::to_string(is_bst1) + " | " + std::to_string(is_bst2) << std::endl;
            head.print();
            break;
        } else {
            std::cout << std::to_string(is_bst1) + " | " + std::to_string(is_bst2) << std::endl;
            head.print();
        }
    }*/
}