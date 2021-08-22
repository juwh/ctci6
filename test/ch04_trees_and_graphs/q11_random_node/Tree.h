#ifndef TREE_H_
#define TREE_H_

#include <ctcilib/TreeNode.h>

#include <memory>
#include <random>

class Tree {
    private:
        std::unique_ptr<ctcilib::TreeNode<int>> root_;
        ctcilib::TreeNode<int>* get_ith_node(size_t i, ctcilib::TreeNode<int>* node);
    public:
        Tree();
        void insert_in_order(int value);
        size_t size();
        ctcilib::TreeNode<int>* get_random_node();
        void print();
};

#endif // TREE_H_