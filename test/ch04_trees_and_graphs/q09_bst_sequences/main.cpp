#pragma region Interview Question
/*
4.9 BST Sequences: A binary search tree was created by traversing through an array from left to right
and inserting each element. Given a binary search tree with distinct elements, print all possible
arrays that could have led to this tree.

EXAMPLE
Input: {{}, {1, 3}, {}}
Output: {2, 1, 3}, {2, 3, 1} 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#39. What is the very first value that must be in each array? 

#48. The root is the very first value that must be in every array. What can you say about the
order of the values in the left subtree as compared to the values in the right subtree? Do
the left subtree values need to be inserted before the right subtree? 

#66. The relationship between the left subtree values and the right subtree values is, essen-
tially, anything. The left subtree values could be inserted before the right subtree, or the
reverse (right values before left), or any other ordering. 

#82. Break this down into subproblems. Use recursion. If you had all possible sequences for
the left subtree and the right subtree, how could you create all possible sequences for
the entire tree? 
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <iostream>
#include <list>
#include <vector>

/* Weave lists toegther in all possible ways. This algorithm works by removing the
 * head from one list, recursing, and then doing the same thing with the other
 * list. */
void weave_lists(std::list<int>& left, std::list<int>& right, std::vector<std::list<int>>& results, std::list<int>& prefix) {
    /* One list is empty. Add the remainder to [a cloned] prefix and
     * store result. */
    if (left.size() == 0 || right.size() == 0) {
        std::list<int> result{prefix};
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        results.push_back(result);
        return;
    }
    
    /* Recurse with head of first added to the prefix. Removing the
     * head will damage first, so we’ll need to put it back where we
     * found it afterwards. */
    int head_left{left.front()};
    left.pop_front();
    prefix.push_back(head_left);
    weave_lists(left, right, results, prefix);
    prefix.pop_back();
    left.push_front(head_left);
    
    /* Do the same thing with second, damaging and then restoring
     * the list.*/
    int head_right{right.front()};
    right.pop_front();
    prefix.push_back(head_right);
    weave_lists(left, right, results, prefix);
    prefix.pop_back();
    right.push_front(head_right);
}

std::vector<std::list<int>> all_sequences(ctcilib::TreeNode<int>* node) {
    std::vector<std::list<int>> result;
    if (!node) {
        return {{}};
    }

    std::list<int> prefix{{node->data_}};

    /* Recurse on left and right subtrees. */
    auto seq_left{all_sequences(node->left_)};
    auto seq_right{all_sequences(node->right_)};

    /* Weave together each list from the left and right sides. */
    for (auto left : seq_left) {
        for (auto right : seq_right) {
            std::vector<std::list<int>> weaved;
            weave_lists(left, right, weaved, prefix);
            result.insert(result.end(), weaved.begin(), weaved.end());
        }
    }
    return result;
}

int main() {
    ctcilib::TreeNode<int> node(100);
    std::vector<int> array{{100, 50, 20, 75, 150, 120, 170}};
    for (auto a : array) {
        node.insert_in_order(a);
    }
    node.print();
    std::vector<std::list<int>> all_seq{all_sequences(&node)};
    for (auto list : all_seq) {
        std::cout << "{";
        for (auto item : list) {
            std::cout << std::to_string(item) << ", ";
        }
        std::cout << "}" << std::endl;
    }
    std::cout << std::to_string(all_seq.size()) << std::endl;
}