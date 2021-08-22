#pragma region Interview Question
/*
4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one.
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#21. Think about the definition of a balanced tree. Can you check that condition for a single
node? Can you check it for every node? 

#33. If you've developed a brute force solution, be careful about its runtime. If you are
computing the height of the subtrees for each node, you could have a pretty inefficient
algorithm. 

#49. What if you could modify the binary tree node class to allow a node to store the height
of its subtree? 

#105. You don't need to modify the binary tree class to store the height of the subtree. Can
your recursive function compute the height of each subtree while also checking if a
node is balanced? Try having the function return multiple values. 

#124. Actually, you can just have a single checkHeight function that does both the height
computation and the balance check. An integer return value can be used to indicate
both.
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int get_height(ctcilib::TreeNode<int>* root) {
    if (!root) {
        return 0;
    }
    int height_left{get_height(root->left_)};
    int height_right{get_height(root->right_)};
    if (abs(height_left - height_right) > 1) {
        return std::numeric_limits<int>::min();
    } else {
        return std::max(height_left, height_right) + 1;
    }
}

bool is_balanced(ctcilib::TreeNode<int>* root) {
    return get_height(root) != std::numeric_limits<int>::min();
}

int main() {
    // Create balanced tree
    std::vector<int> array{{0, 1, 2, 3, 5, 6, 7, 8, 9, 10}};
    TreeNode<int> root(array);
    
    std::cout << "Is balanced? " + std::to_string(is_balanced(&root)) << std::endl;
    
    root.insert_in_order(4); // Add 4 to make it unbalanced

    std::cout << "Is balanced? " + std::to_string(is_balanced(&root)) << std::endl;
}