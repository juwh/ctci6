#include "Tree.h"

ctcilib::TreeNode<int>* Tree::get_ith_node(size_t i, ctcilib::TreeNode<int>* node) {
    if (!node || i >= node->size()) {
        return nullptr;
    }
    size_t size_left{node->left_ ? node->left_->size() : 0};
    if (i < size_left) {
        return get_ith_node(i, node->left_);
    } else if (i == size_left) {
        return node;
    } else {
        return get_ith_node(i - size_left - 1, node->right_);
    }
}

Tree::Tree() : root_{nullptr} {}

void Tree::insert_in_order(int value) {
    if (root_) {
        root_->insert_in_order(value);
    } else {
        root_ = std::make_unique<TreeNode<int>>(value);
    }
}

size_t Tree::size() {
    return root_ ? root_->size() : 0;
}
        
ctcilib::TreeNode<int>* Tree::get_random_node() {
    if (!root_) {
        return nullptr;
    }
    std::default_random_engine generator;
    generator.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, root_->size()-1);
    return get_ith_node(distribution(generator), root_.get());
}

void Tree::print() {
    if (root_) {
        root_->print();
    }
}