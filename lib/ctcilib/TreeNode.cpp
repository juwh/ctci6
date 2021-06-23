#include "TreeNode.h"
using namespace ctcilib;

template<typename T>
void TreeNode<T>::setLeftChild(TreeNode left) {
	this.left = left;
	if (left != null) {
		left.parent = this;
	}
}

template<typename T>
void TreeNode<T>::setRightChild(TreeNode right) {
	this.right = right;
	if (right != null) {
		right.parent = this;
	}
}

template<typename T>
TreeNode<T> TreeNode<T>::createMinimalBST(std::vector< T > arr, int start, int end){
	if (end < start) {
		return null;
	}
	int mid = (start + end) / 2;
	TreeNode n = new TreeNode(arr[mid]);
	n.setLeftChild(createMinimalBST(arr, start, mid - 1));
	n.setRightChild(createMinimalBST(arr, mid + 1, end));
	return n;
}

template<typename T>
TreeNode<T>::TreeNode(T d) {
	data = d;
	size = 1;
}

template<typename T>
void TreeNode<T>::insertInOrder(T d) {
	if (d <= data) {
		if (left == null) {
			setLeftChild(new TreeNode(d));
		} else {
			left.insertInOrder(d);
		}
	} else {
		if (right == null) {
			setRightChild(new TreeNode(d));
		} else {
			right.insertInOrder(d);
		}
	}
	size++;
}

template<typename T>
size_t TreeNode<T>::size() const {
	return size;
}

template<typename T>
bool TreeNode<T>::isBST() const {
	if (left != null) {
		if (data < left.data || !left.isBST()) {
			return false;
		}
	}
	
	if (right != null) {
		if (data >= right.data || !right.isBST()) {
			return false;
		}
	}		
	
	return true;
}

template<typename T>
size_t TreeNode<T>::height() const {
	int leftHeight = left != null ? left.height() : 0;
	int rightHeight = right != null ? right.height() : 0;
	return 1 + Math.max(leftHeight, rightHeight);
}

template<typename T>
TreeNode<T>& TreeNode<T>::find(T d) const {
	if (d == data) {
		return this;
	} else if (d <= data) {
		return left != null ? left.find(d) : null;
	} else if (d > data) {
		return right != null ? right.find(d) : null;
	}
	return null;
}

template<typename T>
TreeNode<T> TreeNode<T>::createMinimalBST(std::vector< T > array) {
	return createMinimalBST(array, 0, array.length - 1);
}

template<typename T>
void TreeNode<T>::print() const {
	BTreePrinter.printNode(this);
}