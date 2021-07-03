#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

#include <string>

namespace ctcilib {
	template<typename T>
	struct LinkedListNode {
		LinkedListNode<T>* m_next;
		LinkedListNode<T>* m_prev;
		LinkedListNode<T>* m_last; // invariant not maintained in original Java?
		T m_data;
		LinkedListNode(T d, LinkedListNode<T>* n, LinkedListNode<T>* p);
		LinkedListNode(T d);
		LinkedListNode();
		~LinkedListNode();
		void set_next(const LinkedListNode<T>* n);
		void set_previous(const LinkedListNode<T>* p);
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
LinkedListNode<T>::LinkedListNode(T d, LinkedListNode<T>* n, LinkedListNode<T>* p) : m_next{nullptr}, m_prev{nullptr}, m_last{nullptr}, m_data{d} {
	set_next(n);
	set_previous(p);
}

template<typename T>
LinkedListNode<T>::LinkedListNode(T d) : m_next{nullptr}, m_prev{nullptr}, m_last{nullptr}, m_data{d} {}	

template<typename T>
LinkedListNode<T>::LinkedListNode() : m_next{nullptr}, m_prev{nullptr}, m_last{nullptr}, m_data{} {}

template<typename T>
LinkedListNode<T>::~LinkedListNode() {
	delete m_next;
}

template<typename T>
void LinkedListNode<T>::set_next(const LinkedListNode<T>* n) {
	m_next = n;
	if (this == m_last) {
		m_last = n;
	}
	if (n && n->m_prev != this) {
		n->set_previous(this);
	}
}

template<typename T>
void LinkedListNode<T>::set_previous(const LinkedListNode<T>* p) {
	m_prev = p;
	if (p && p->m_next != this) {
		p->set_next(this);
	}
}	

template<typename T>
std::string LinkedListNode<T>::print_forward() {
	if (m_next) {
		return m_data + "->" + m_next->print_forward();
	} else {
		return (std::string)m_data;
	}
}

template<typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode<T>& linked_list_node) : m_next{nullptr}, m_prev{nullptr}, m_last{nullptr}, m_data{linked_list_node.m_data} {
	LinkedListNode<T>* new_ptr{m_next};
	for (auto copy_ptr=linked_list_node.m_next; copy_ptr; copy_ptr=copy_ptr->m_next) {
		new_ptr = new LinkedListNode(copy_ptr->m_data);
		new_ptr->m_prev = this;
		new_ptr=new_ptr->m_next;
	}
}

template<typename T>
const LinkedListNode<T>& LinkedListNode<T>::operator= (const LinkedListNode<T> & rhs) {
	if (this != &rhs)
   {
      LinkedListNode<T> tmp(rhs);
      std::swap(this->m_next, tmp.m_next);
   }
   return *this;
}

#endif // LINKEDLISTNODE_H_