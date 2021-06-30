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
            size_t m_size;
            void set_left_child(TreeNode<T>* left);
            void set_right_child(TreeNode<T>* right);
            /* Helper function for added copy constructor */
            void copy_node_recursive(TreeNode<T>* &to, const TreeNode<T>* from, const TreeNode<T>* parent);
            /* static TreeNode<T>* createMinimalBST(std::vector<T> arr, size_t start, size_t end)
            * Formally static function for object initialization, the method has been converted to be
            * a constructor to better manage memory allocation, class invariants
            */
            TreeNode(std::vector<T> arr, size_t start, size_t end);
        public:
            T m_data;
            TreeNode<T>* m_left;
            TreeNode<T>* m_right;
            TreeNode<T>* m_parent;
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
	m_left = left;
	if (left != nullptr) {
		left->parent = this;
	}
}

template<typename T>
void TreeNode<T>::set_right_child(TreeNode<T>* right) {
	m_right = right;
	if (right != nullptr) {
		right->parent = this;
	}
}

template<typename T>
void TreeNode<T>::copy_node_recursive(TreeNode<T>* &to, const TreeNode<T>* from, const TreeNode<T>* parent) {
	if (from) {
		if (to) {
			delete to;
		}
		to = new TreeNode<T>(from->m_data);
		to->m_size = from->m_size;
		to->m_parent = parent;
		copy_node_recursive(to->m_left, from->m_left, to);
		copy_node_recursive(to->m_right, from->m_right, to);
	}
}

template<typename T>
TreeNode<T>::TreeNode(std::vector<T> arr, size_t start, size_t end) : m_size{end - start} {
	if (end >= arr.size()) {
		throw std::invalid_argument("Final index argument must be less than the vector size.");
	}
	if (end < start) {
		throw std::invalid_argument("Vector range must include at least one data element.");
	}
	size_t mid {(start + end) / 2};
	m_data = arr[mid];
	m_left = mid - 1 > start ? new TreeNode(arr, start, mid - 1) : nullptr;
	m_right = end > mid + 1 ? new TreeNode(arr, mid + 1, end) : nullptr;
}

template<typename T>
TreeNode<T>::TreeNode(T d) : m_size{1}, m_data{d}, m_left{nullptr}, m_right{nullptr}, m_parent{nullptr} {}

template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& node) : m_size{node.m_size}, m_data{node.m_data}, m_left{nullptr}, m_right{nullptr}, m_parent{nullptr}
{
	copy_node_recursive(m_left, node.m_left, this);
	copy_node_recursive(m_right, node.m_right, this);
}

template <typename T>
TreeNode<T>::~TreeNode()
{
	delete m_left;
	delete m_right;
}

template <typename T>
const TreeNode<T>& TreeNode<T>::operator= (const TreeNode<T>& rhs)
{
   if (this != &rhs)
   {
      TreeNode<T> tmp(rhs);
      std::swap(this->m_left, tmp.m_left);
      std::swap(this->m_right, tmp.m_right);
   }
   return *this;
}

template<typename T>
void TreeNode<T>::insert_in_order(T d) {
	if (d <= m_data) {
		if (m_left == nullptr) {
			m_left = new TreeNode(d);
		} else {
			m_left->insert_in_order(d);
		}
	} else {
		if (m_right == nullptr) {
			m_right = new TreeNode(d);
		} else {
			m_right->insert_in_order(d);
		}
	}
	m_size++;
}

template<typename T>
size_t TreeNode<T>::size() const {
	return m_size;
}

template<typename T>
bool TreeNode<T>::is_bst() const {
	if (m_left != nullptr) {
		if (m_data < m_left->data || !m_left->is_bst()) {
			return false;
		}
	}
	
	if (m_right != nullptr) {
		if (m_data >= m_right->m_data || !m_right->is_bst()) {
			return false;
		}
	}		
	return true;
}

template<typename T>
size_t TreeNode<T>::height() const {
	int left_height = m_left != nullptr ? m_left->height() : 0;
	int right_height = m_right != nullptr ? m_right->height() : 0;
	return 1 + std::max(left_height, right_height);
}

template<typename T>
TreeNode<T>* TreeNode<T>::find(T d) const {
	if (d == m_data) {
		return this;
	} else if (d <= m_data) {
		return m_left != nullptr ? m_left->find(d) : nullptr;
	} else if (d > m_data) {
		return m_right != nullptr ? m_right->find(d) : nullptr;
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