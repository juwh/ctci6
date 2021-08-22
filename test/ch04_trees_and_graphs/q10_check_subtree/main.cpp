#pragma region Interview Question
/*
4.10 Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine if T2 is a subtree of Tl.

A tree T2 is a subtree ofTi if there exists a node n in Ti such that the subtree of n is identical to T2.
That is, if you cut off the tree at node n, the two trees would be identical.  
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#4. If T2 is a subtree of Tl, how will its in-order traversal compare to Tl's? What about its
pre-order and post-order traversal? 

#11. The in-order traversals won't tell us much. After all, every binary search tree with the
same values (regardless of structure) will have the same in-order traversal. This is what
in-order traversal means: contents are in-order. (And if it won't work in the specific case
of a binary search tree, then it certainly won't work for a general binary tree.) The pre-
order traversal, however, is much more indicative. 

#18. You may have concluded that if T2.preorderTraversal() is a substring of
Tl.preorderTraversal(), then T2 is a subtree of Tl. This is almost true, except
that the trees could have duplicate values. Suppose Tl and T2 have all duplicate values
but different structures. The pre-order traversals will look the same even though T2 is
not a subtree of Tl. How can you handle situations like this? 

#31. Although the problem seems like it stems from duplicate values, it's really deeper than
that. The issue is that the pre-order traversal is the same only because there are null
nodes that we skipped over (because they're null). Consider inserting a placeholder
value into the pre-order traversal string whenever you reach a null node. Register the
null node as a "real" node so that you can distinguish between the different structures. 

#37. Alternatively, we can handle this problem recursively. Given a specific node within T1,
can we check to see if its subtree matches T2?  
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <iostream>
#include <string>
#include <vector>

std::string get_order_string(ctcilib::TreeNode<int>* node) {
    if (!node) {
        return "X";
    }
    return std::to_string(node->data_) + " " + get_order_string(node->left_) + " " + get_order_string(node->right_);
}

bool contains_tree_string(ctcilib::TreeNode<int>* t1, ctcilib::TreeNode<int>* t2) {
    std::string string1{get_order_string(t1)};
    std::string string2{get_order_string(t2)};
    return string1.find(string2) != std::string::npos;
}

bool match_tree(ctcilib::TreeNode<int>* r1, ctcilib::TreeNode<int>* r2) {
    if (!r1 && !r2) {
        return true; // nothing left in the subtree
    } else if (!r1 || !r2) {
        return false; // exactly one tree is empty, therefore trees don't match
    } else if (r1->data_ != r2->data_) {
        return false; // data doesn't match
    } else {
        return match_tree(r1->left_, r2->left_) && match_tree(r1->right_, r2->right_);
    }
}

bool subtree(ctcilib::TreeNode<int>* r1, ctcilib::TreeNode<int>* r2) {
    if (!r1) {
        return false; // big tree empty & subtree still not found
    }
    if (r1->data_ == r2->data_ && match_tree(r1, r2)) {
        return true;
    }
    return subtree(r1->left_, r2) || subtree(r1->right_, r2);
}

bool contains_tree(ctcilib::TreeNode<int>* t1, ctcilib::TreeNode<int>* t2) {
    if (!t2) {
        return true; // The empty tree is always a subtree
    }
    return subtree(t1, t2);
}

int main() {
    // t2 is a subtree of t1
    std::vector<int> array1{{1, 2, 1, 3, 1, 1, 5}};
    std::vector<int> array2{{2, 3, 1}};
    
    ctcilib::TreeNode<int> t1(array1);
    ctcilib::TreeNode<int> t2(array2);
    
    /*
    t1.print();
    t2.print();
    std::cout << get_order_string(&t1) << std::endl;
    std::cout << get_order_string(&t2) << std::endl;
    */

    if (contains_tree(&t1, &t2)) {
        std::cout << "t2 is a subtree of t1" << std::endl;
    } else {
        std::cout << "t2 is not a subtree of t1" << std::endl;
    }

    // t4 is not a subtree of t3
    std::vector<int> array3{{1, 2, 1}};
    ctcilib::TreeNode<int> t3(array1);
    ctcilib::TreeNode<int> t4(array3);

    if (contains_tree(&t3, &t4)) {
        std::cout << "t4 is a subtree of t3" << std::endl;
    } else {
        std::cout << "t4 is not a subtree of t3" << std::endl;
    }
}