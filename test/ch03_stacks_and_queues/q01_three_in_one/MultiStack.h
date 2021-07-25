#ifndef MULTISTACK_H_
#define MULTISTACK_H_

#include <ctcilib/assorted_methods.h>

#include <exception>
#include <string>
#include <vector>

template<typename T>
class MultiStack {
    private:
        /* StackInfo is a simple class that holds a set of data about 
         * each stack. It does not hold the actual items in the stack. 
         * We could have done this with just a bunch of individual 
         * variables, but that’s messy and doesn’t gain us much. */
        struct StackInfo {
            int start_;
            size_t size_, capacity_;
            const MultiStack<T>* parent_;
            StackInfo(int start, size_t capacity, const MultiStack<T>* parent);
            /* Check if an index on the full array is within the stack
             * boundaries. The stack can wrap around to the start of 
             * the array. */
            bool is_within_stack_capacity(int index) const;
            int last_capacity_index() const;
            int last_element_index() const;
            bool is_full() const;
            bool is_empty() const;
        };

        std::vector<StackInfo> info_;
        std::vector<T> values_;

        /* Adjust index to be within the range of 0 -> length - 1. */
        int adjust_index(int index) const;
        /* Get index after this index, adjusted for wrap around. */
        int next_index(int index) const;
        /* Get index before this index, adjusted for wrap around. */
        int previous_index(int index) const;
        /* Shift items in stack over by one element. If we have 
        * available capacity, then we'll end up shrinking the stack 
        * by one element. If we don't have available capacity, then
        * we'll need to shift the next stack over too. */
        void shift(size_t stack_num);
        /* Expand stack by shifting over other stacks */
        void expand(size_t stack_num);

    public:
        MultiStack(size_t number_of_stacks, size_t default_size);
        /* Returns the number of items actually present in stack. */
	    size_t number_of_elements() const;
        /* Returns true is all the stacks are full. */
	    bool all_stacks_are_full() const;
        /* Push value onto stack num, shifting/expanding stacks as 
	     * necessary. Throws exception if all stacks are full. */
        void push(size_t stack_num, T value);
        /* Remove value from stack. */
        T pop(size_t stack_num);
        /* Get top element of stack.*/
        T peek(size_t stack_num) const;
        std::vector<T> get_values() const;
        std::vector<T> get_stack_values(size_t stack_num) const;
        std::string stack_to_string(size_t stack_num) const;
};

template<typename T>
MultiStack<T>::StackInfo::StackInfo(int start, size_t capacity, const MultiStack<T>* parent) : start_{start}, size_{0}, capacity_{capacity}, parent_{parent} {}

template<typename T>
bool MultiStack<T>::StackInfo::is_within_stack_capacity(int index) const {
    /* If outside of bounds of array, return false. */
    if (index >= static_cast<int>(parent_->values_.size())) {
        return false;
    }
    
    /* If index wraps around, adjust it. */
    int contiguous_index = index < start_ ? index + parent_->values_.size() : index;
    int end = start_ + capacity_;
    return start_ <= contiguous_index && contiguous_index < end;
}

template<typename T>
int MultiStack<T>::StackInfo::last_capacity_index() const {
    return parent_->adjust_index(start_ + capacity_ - 1);
}

template<typename T>
int MultiStack<T>::StackInfo::last_element_index() const {
    return parent_->adjust_index(start_ + size_ - 1);
}		

template<typename T>
bool MultiStack<T>::StackInfo::is_full() const {
    return size_ == capacity_;
}

template<typename T>
bool MultiStack<T>::StackInfo::is_empty() const {
    return !size_;
}

template<typename T>
int MultiStack<T>::adjust_index(int index) const {
    int max{static_cast<int>(values_.size())};
    return ((index % max) + max) % max;
}

template<typename T>
int MultiStack<T>::next_index(int index) const {
    return adjust_index(index + 1);
}

template<typename T>
int MultiStack<T>::previous_index(int index) const {
    return adjust_index(index - 1);
}

template<typename T>
void MultiStack<T>::shift(size_t stack_num) {
    std::cout << "/// Shifting " + std::to_string(stack_num) << std::endl;
    StackInfo& stack{info_[stack_num]};
    
    /* If this stack is at its full capacity, then you need
     * to move the next stack over by one element. This stack
     * can now claim the freed index. */
    if (stack.size_ >= stack.capacity_) {
        size_t next_stack{(stack_num + 1) % info_.size()};
        shift(next_stack); 
        stack.capacity_++; // claim index that next stack lost
    }
    
    /* Shift all elements in stack over by one. */
    int index{stack.last_capacity_index()};
    while (stack.is_within_stack_capacity(index)) {
        values_[index] = values_[previous_index(index)];
        index = previous_index(index);
    }
    
    /* Adjust stack data. */
    values_[stack.start_] = 0; // Clear item
    stack.start_ = next_index(stack.start_); // move start
    stack.capacity_--; // Shrink capacity
}

template<typename T>
void MultiStack<T>::expand(size_t stack_num) {
    std::cout << "/// Expanding stack " + std::to_string(stack_num) << std::endl;
    
    shift((stack_num + 1) % info_.size());
    info_[stack_num].capacity_++;
}

template<typename T>
MultiStack<T>::MultiStack(size_t number_of_stacks, size_t default_size) : values_(number_of_stacks * default_size) {
    for (size_t i = 0; i < number_of_stacks; i++) {
        info_.push_back(StackInfo(default_size * i, default_size, this));
    }
}

template<typename T>
size_t MultiStack<T>::number_of_elements() const {
    size_t size{0};
    for (StackInfo sd : info_) {
        size += sd.size_;
    }
    return size;
}

template<typename T>
bool MultiStack<T>::all_stacks_are_full() const {
    return number_of_elements() == values_.size();
}

template<typename T>
void MultiStack<T>::push(size_t stack_num, T value) {
    std::cout << "/// Pushing stack " + std::to_string(stack_num) + ": " + std::to_string(value) << std::endl;
    if (all_stacks_are_full()) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is full.");
    }
    
    /* If this stack is full, expand it. */
    StackInfo& stack{info_.at(stack_num)};
    if (stack.is_full()) {
        expand(stack_num);
    }
    
    /* Find the index of the top element in the array + 1, 
     * and increment the stack pointer */	
    stack.size_++;	
    values_.at(stack.last_element_index()) = value;	
}

template<typename T>
T MultiStack<T>::pop(size_t stack_num) {
    std::cout << "/// Popping stack " + std::to_string(stack_num) << std::endl;
    StackInfo& stack{info_.at(stack_num)};		
    if (stack.is_empty()) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is empty.");
    }

    /* Remove last element. */
    T value{values_.at(stack.last_element_index())};
    values_.at(stack.last_element_index()) = 0; // Clear item
    stack.size_--; // Shrink size
    return value;
}

template<typename T>
T MultiStack<T>::peek(size_t stack_num) const {
    StackInfo stack = info_.at(stack_num);	
    if (stack.is_empty()) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is empty.");
    }
    return values_.at(stack.last_element_index());
}

template<typename T>
std::vector<T> MultiStack<T>::get_values() const {
    return values_;
}

template<typename T>
std::vector<T> MultiStack<T>::get_stack_values(size_t stack_num) const {
    StackInfo stack{info_[stack_num]};
    std::vector<T> items(stack.size_);
    for (size_t i = 0; i < items.size(); i++) {
        items.at(i) = values_.at(adjust_index(stack.start_ + i));
    }
    return items;
}

template<typename T>
std::string MultiStack<T>::stack_to_string(size_t stack_num) const {
    std::vector<T> items{get_stack_values(stack_num)};
    return std::to_string(stack_num) + ": " + ctcilib::array_to_string(items);
}

#endif // MULTISTACK_H_