#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

#include <string>

namespace ctcilib {
	template<typename T>
	struct LinkedListNode {
		LinkedListNode<T>* next_;
		LinkedListNode<T>* prev_;
		LinkedListNode<T>* last_; // invariant not maintained in original Java?
		T data_;
		LinkedListNode(T d, LinkedListNode<T>* n, LinkedListNode<T>* p);
		LinkedListNode(T d);
		LinkedListNode();
		~LinkedListNode();
		void set_next(LinkedListNode<T>* n);
		void set_previous(LinkedListNode<T>* p);
		std::string print_forward();
		/* LinkedListNode clone()
		* Formally function for copied object initialization, the method has been converted to be
		* a copy constructor
		*/
		LinkedListNode(const LinkedListNode<T>& linked_list_node);
		const LinkedListNode<T>& operator= (const LinkedListNode<T> & rhs);
	};
}

using namespace ctcilib;

template<typename T>
LinkedListNode<T>::LinkedListNode(T d, LinkedListNode<T>* n, LinkedListNode<T>* p) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{d} {
	set_next(n);
	set_previous(p);
}

template<typename T>
LinkedListNode<T>::LinkedListNode(T d) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{d} {}	

template<typename T>
LinkedListNode<T>::LinkedListNode() : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{} {}

template<typename T>
LinkedListNode<T>::~LinkedListNode() {
	delete next_;
}

template<typename T>
void LinkedListNode<T>::set_next(LinkedListNode<T>* n) {
	next_ = n;
	if (this == last_) {
		last_ = n;
	}
	if (n && n->prev_ != this) {
		n->set_previous(this);
	}
}

template<typename T>
void LinkedListNode<T>::set_previous(LinkedListNode<T>* p) {
	prev_ = p;
	if (p && p->next_ != this) {
		p->set_next(this);
	}
}	

template<typename T>
std::string LinkedListNode<T>::print_forward() {
	if (next_) {
		return data_ + "->" + next_->print_forward();
	} else {
		return "" + data_;
	}
}

template<typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode<T>& linked_list_node) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{linked_list_node.data_} {
	LinkedListNode<T>* new_ptr{next_};
	for (auto copy_ptr=linked_list_node.next_; copy_ptr; copy_ptr=copy_ptr->next_) {
		new_ptr = new LinkedListNode(copy_ptr->data_);
		new_ptr->prev_ = this;
		new_ptr=new_ptr->next_;
	}
}

template<typename T>
const LinkedListNode<T>& LinkedListNode<T>::operator= (const LinkedListNode<T> & rhs) {
	if (this != &rhs)
   {
      LinkedListNode<T> tmp(rhs);
      std::swap(this->next_, tmp.next_);
   }
   return *this;
}

#endif // LINKEDLISTNODE_H_