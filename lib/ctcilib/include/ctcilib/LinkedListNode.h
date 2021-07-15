#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

#include <string>
#include <type_traits>

namespace ctcilib {
	template<
		typename T, //real type
		typename = std::enable_if<std::is_arithmetic<T>::value, T>::type
	>
	struct LinkedListNode {
		LinkedListNode<T>* next_;
		LinkedListNode<T>* prev_;
		LinkedListNode<T>* last_; // invariant not maintained in original Java?
		T data_;

		LinkedListNode(T d, LinkedListNode<T>* n, LinkedListNode<T>* p) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{d} {
			set_next(n);
			set_previous(p);
		};

		LinkedListNode(T d) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{d} {}

		LinkedListNode() : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{} {}

		~LinkedListNode() {
			delete next_;
		}

		void set_next(LinkedListNode<T>* n) {
			next_ = n;
			if (this == last_) {
				last_ = n;
			}
			if (n && n->prev_ != this) {
				n->set_previous(this);
			}
		}

		void set_previous(LinkedListNode<T>* p) {
			prev_ = p;
			if (p && p->next_ != this) {
				p->set_next(this);
			}
		}

		std::string print_forward() {
			if (next_) {
				return std::to_string(data_) + "->" + next_->print_forward();
			} else {
				return std::to_string(data_);
			}
		}

		/* LinkedListNode clone()
		* Formally function for copied object initialization, the method has been converted to be
		* a copy constructor
		*/
		LinkedListNode(const LinkedListNode<T>& linked_list_node) : next_{nullptr}, prev_{nullptr}, last_{nullptr}, data_{linked_list_node.data_} {
			LinkedListNode<T>* new_ptr{next_};
			for (auto copy_ptr=linked_list_node.next_; copy_ptr; copy_ptr=copy_ptr->next_) {
				new_ptr = new LinkedListNode(copy_ptr->data_);
				new_ptr->prev_ = this;
				new_ptr=new_ptr->next_;
			}
		}

		const LinkedListNode<T>& operator= (const LinkedListNode<T> & rhs) {
			if (this != &rhs)
			{
				LinkedListNode<T> tmp(rhs);
				std::swap(this->next_, tmp.next_);
			}
			return *this;
		}
	};
}

#endif // LINKEDLISTNODE_H_