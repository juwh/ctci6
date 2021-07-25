#ifndef FIXEDMULTISTACK_H_
#define FIXEDMULTISTACK_H_

#include <ctcilib/assorted_methods.h>

#include <exception>
#include <string>
#include <vector>

template<typename T>
class FixedMultiStack {
    private:
        size_t number_of_stacks_{3};
        size_t stack_capacity_;
        std::vector<T> values_;
        std::vector<size_t> sizes_;

    public:
        FixedMultiStack(size_t stack_size);
        /* Push value onto stack. */
        void push(size_t stack_num, T value);
        /* Pop item from top stack. */
        T pop(size_t stack_num);
        /* Return top element. */
        T peek(size_t stack_num);
        /* Return if stack is empty. */
        bool is_empty(size_t stack_num);
        /* Return if stack is full. */
        bool is_full(size_t stack_num);
        /* Returns index of the top of the stack. */
        size_t index_of_top(size_t stack_num);
        std::vector<T> get_values();
        std::vector<T> get_stack_values(size_t stack_num);
        std::string stack_to_string(size_t stack_num);
};

template<typename T>
FixedMultiStack<T>::FixedMultiStack(size_t stack_size) : stack_capacity_{stack_size}, values_(number_of_stacks_ * stack_capacity_), sizes_(number_of_stacks_) {}

template<typename T>
void FixedMultiStack<T>::push(size_t stack_num, T value) {
    /* Check that we have space for the next element */
    if (is_full(stack_num)) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is full.");
    }
    /* Increment stack pointer and then update top value. */		
    sizes_.at(stack_num)++;
    values_.at(index_of_top(stack_num)) = value;
}

template<typename T>
T FixedMultiStack<T>::pop(size_t stack_num) {
    if (is_empty(stack_num)) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is empty.");
    }
    auto out = values_.at(index_of_top(stack_num));
    values_.at(index_of_top(stack_num)) = T{};
    sizes_.at(stack_num)--;
    return out;
}

template<typename T>
T FixedMultiStack<T>::peek(size_t stack_num) {
    if (is_empty(stack_num)) {
        throw std::range_error("Stack " + std::to_string(stack_num) + " is empty.");
    }
    return values_.at(index_of_top(stack_num));
}

template<typename T>
bool FixedMultiStack<T>::is_empty(size_t stack_num) {
    return !sizes_.at(stack_num);
}

template<typename T>
bool FixedMultiStack<T>::is_full(size_t stack_num) {
    return sizes_.at(stack_num) == stack_capacity_;
}

template<typename T>
size_t FixedMultiStack<T>::index_of_top(size_t stack_num) {
    return stack_num * stack_capacity_ + sizes_.at(stack_num) - 1;
}

template<typename T>
std::vector<T> FixedMultiStack<T>::get_values() {
    return values_;
}

template<typename T>
std::vector<T> FixedMultiStack<T>::get_stack_values(size_t stack_num) {
    auto first = values_.begin() + stack_num * stack_capacity_;
    auto last = values_.begin() + stack_num * stack_capacity_ + sizes_.at(stack_num);
    return std::vector(first, last);
}

template<typename T>
std::string FixedMultiStack<T>::stack_to_string(size_t stack_num) {
    auto items{get_stack_values(stack_num)};
    return ctcilib::array_to_string(items);
}

#endif // FIXEDMULTISTACK_H_