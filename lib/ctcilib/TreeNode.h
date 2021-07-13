#ifndef TREENODE_H_
#define TREENODE_H_

#include "BTreePrinter.h"

#include <vector>

namespace ctcilib {
    /* One node of a binary tree. The data element stored is a single 
    * character.
    */
    template<typename T>
    class TreeNode {
        private:
            size_t size_;
            void set_left_child(TreeNode<T>* left);
            void set_right_child(TreeNode<T>* right);
            /* Helper function for added copy constructor */
            void copy_node_recursive(TreeNode<T>* &to, const TreeNode<T>* from, TreeNode<T>* parent);
            /* static TreeNode<T>* createMinimalBST(std::vector<T> arr, size_t start, size_t end)
            * Formally static function for object initialization, the method has been converted to be
            * a constructor to better manage memory allocation, class invariants
            */
            TreeNode(std::vector<T> arr, size_t start, size_t end);
        public:
            T data_;
            TreeNode<T>* left_;
            TreeNode<T>* right_;
            TreeNode<T>* parent_;
            TreeNode(T d);
            TreeNode(const TreeNode<T>& tree_node);
            ~TreeNode();
            const TreeNode<T>& operator= (const TreeNode<T> & rhs);
            void insert_in_order(T d);
            size_t size() const;
            bool is_bst() const;
            size_t height() const;
            TreeNode<T>* find(T d) const;
            /* static TreeNode<T>* createMinimalBST(std::vector<T> array)
            * Formally static function for object initialization, the method has been converted to be
            * a constructor to better manage memory allocation, class invariants
            */
            TreeNode(std::vector<T> array);
            void print() const;
    };
}

using namespace ctcilib;

template<typename T>
void TreeNode<T>::set_left_child(TreeNode<T>* left) {
	left_ = left;
	if (left != nullptr) {
		left->parent = this;
	}
}

template<typename T>
void TreeNode<T>::set_right_child(TreeNode<T>* right) {
	right_ = right;
	if (right != nullptr) {
		right->parent = this;
	}
}

template<typename T>
void TreeNode<T>::copy_node_recursive(TreeNode<T>* &to, const TreeNode<T>* from, TreeNode<T>* parent) {
	if (from) {
		if (to) {
			delete to;
		}
		to = new TreeNode<T>(from->data_);
		to->size_ = from->size_;
		to->parent_ = parent;
		copy_node_recursive(to->left_, from->left_, to);
		copy_node_recursive(to->right_, from->right_, to);
	}
}

template<typename T>
TreeNode<T>::TreeNode(std::vector<T> arr, size_t start, size_t end) : size_{end - start}, left_{nullptr}, right_{nullptr}, parent_{nullptr} {
	if (end >= arr.size()) {
		throw std::invalid_argument("Final index argument must be less than the vector size.");
	}
	if (end < start) {
		throw std::invalid_argument("Vector range must include at least one data element.");
	}
	size_t mid {(start + end) / 2};
	data_ = arr[mid];
	if (mid - 1 > start) {
		left_ = new TreeNode(arr, start, mid - 1);
		left_->parent_ = this;
	}
	if (end > mid + 1) {
		right_ = new TreeNode(arr, mid + 1, end);
		right_->parent_ = this;
	}
}

template<typename T>
TreeNode<T>::TreeNode(T d) : size_{1}, data_{d}, left_{nullptr}, right_{nullptr}, parent_{nullptr} {}

template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& node) : size_{node.size_}, data_{node.data_}, left_{nullptr}, right_{nullptr}, parent_{nullptr}
{
	copy_node_recursive(left_, node.left_, this);
	copy_node_recursive(right_, node.right_, this);
}

template <typename T>
TreeNode<T>::~TreeNode()
{
	delete left_;
	delete right_;
}

template <typename T>
const TreeNode<T>& TreeNode<T>::operator= (const TreeNode<T>& rhs)
{
   if (this != &rhs)
   {
      TreeNode<T> tmp(rhs);
      std::swap(this->left_, tmp.left_);
      std::swap(this->right_, tmp.right_);
   }
   return *this;
}

template<typename T>
void TreeNode<T>::insert_in_order(T d) {
	if (d <= data_) {
		if (left_ == nullptr) {
			left_ = new TreeNode(d);
			left_->parent_ = this;
		} else {
			left_->insert_in_order(d);
		}
	} else {
		if (right_ == nullptr) {
			right_ = new TreeNode(d);
			right_->parent_ = this;
		} else {
			right_->insert_in_order(d);
		}
	}
	size_++;
}

template<typename T>
size_t TreeNode<T>::size() const {
	return size_;
}

template<typename T>
bool TreeNode<T>::is_bst() const {
	if (left_ != nullptr) {
		if (data_ < left_->data || !left_->is_bst()) {
			return false;
		}
	}
	
	if (right_ != nullptr) {
		if (data_ >= right_->data_ || !right_->is_bst()) {
			return false;
		}
	}		
	return true;
}

template<typename T>
size_t TreeNode<T>::height() const {
	int left_height = left_ != nullptr ? left_->height() : 0;
	int right_height = right_ != nullptr ? right_->height() : 0;
	return 1 + std::max(left_height, right_height);
}

template<typename T>
TreeNode<T>* TreeNode<T>::find(T d) const {
	if (d == data_) {
		return this;
	} else if (d <= data_) {
		return left_ != nullptr ? left_->find(d) : nullptr;
	} else if (d > data_) {
		return right_ != nullptr ? right_->find(d) : nullptr;
	}
	return nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(std::vector<T> array) : TreeNode(array, 0, array.length - 1) {}

template<typename T>
void TreeNode<T>::print() const {
	BTreePrinter::print_node(this);
}

#endif // TREENODE_H_