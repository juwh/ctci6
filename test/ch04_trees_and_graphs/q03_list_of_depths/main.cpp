#pragma region Interview Question
/*
4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth 0, you'll have 0 linked lists). 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#107. Try modifying a graph search algorithm to track the depth from the root. 

#123. A hash table or array that maps from level number to nodes at that level might also be
useful.

#135. You should be able to come up with an algorithm involving both depth-first search and
breadth-first search. 
*/
#pragma endregion

#include <ctcilib/TreeNode.h>

#include <deque>
#include <list>
#include <vector>

std::vector<std::list<ctcilib::TreeNode<int>*>> create_level_linked_list_bfs(ctcilib::TreeNode<int>* root) {
    std::vector<std::list<ctcilib::TreeNode<int>*>> result;

    std::list<TreeNode<int>*> current;
    if (root) {
        current.push_back(root);
    }
    while (!current.empty()) {
        result.push_back(current);
        auto parents{current};
        current.clear();
        for (auto parent : parents) {
            if (parent->left_) {
                current.push_back(parent->left_);
            }
            if (parent->right_) {
                current.push_back(parent->right_);
            }
        }
    }
    return result;
}

void create_level_linked_list_dfs_recurse(ctcilib::TreeNode<int>* node, std::vector<std::list<ctcilib::TreeNode<int>*>>& lists, size_t level) {
    if (node) {
        if (lists.size() == level) {
            lists.push_back(std::list<TreeNode<int>*>());
        }
        lists.at(level).push_back(node);
        create_level_linked_list_dfs_recurse(node->left_, lists, level + 1);
        create_level_linked_list_dfs_recurse(node->right_, lists, level + 1);
    }
}

std::vector<std::list<ctcilib::TreeNode<int>*>> create_level_linked_list_dfs(ctcilib::TreeNode<int>* root) {
    std::vector<std::list<ctcilib::TreeNode<int>*>> result;
    create_level_linked_list_dfs_recurse(root, result, 0);
    return result;
}

void print_result(std::vector<std::list<ctcilib::TreeNode<int>*>> result){
    size_t depth{0};
    for(std::list<ctcilib::TreeNode<int>*> entry : result) {
        std::cout << "Link list at depth " + std::to_string(depth) + ":" << std::endl;
        std::for_each(entry.begin(), entry.end(), [](const TreeNode<int>* n) {std::cout << " " + std::to_string(n->data_);});
        std::cout << std::endl;
        depth++;
    }
}

int main() {
    std::vector<int> nodes_flattened{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    ctcilib::TreeNode<int> root(nodes_flattened);
    //std::vector<std::list<ctcilib::TreeNode<int>*>> list{create_level_linked_list_bfs(&root)};
    std::vector<std::list<ctcilib::TreeNode<int>*>> list{create_level_linked_list_dfs(&root)};
    print_result(list);
}