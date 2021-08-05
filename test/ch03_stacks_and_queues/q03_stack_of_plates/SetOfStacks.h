#ifndef SETOFSTACKS_H_
#define SETOFSTACKS_H_

#include <stdexcept>
#include <stack>
#include <string>
#include <vector>

template<typename T>
class SetOfStacks {
    private:
        std::vector<std::stack<T>> stacks_;
        T left_shift(size_t index);
        std::string to_string_recursive(size_t index) const;
    public:
        size_t capacity_;
        SetOfStacks(size_t capacity);
        std::stack<T>& get_last_stack();
        void push(T v);
        T pop();
        T pop_at(size_t index);
        bool is_empty();
        std::string to_string();
};

template<typename T>
T SetOfStacks<T>::left_shift(size_t index) {
    if (index < stacks_.size()) {
        std::stack<T> copy{stacks_.at(index)};
        std::stack<T> reversed{};
        while (!copy.empty()) {
            reversed.push(copy.top());
            copy.pop();
        }
        // SetOfStacks should maintain invariant of minimum single element for any
        // existing stack in vector stacks_
        T value{reversed.top()};
        reversed.pop();
        while (!reversed.empty()) {
            copy.push(reversed.top());
            reversed.pop();
        }
        if (index + 1 < stacks_.size()) {
            T next_value{left_shift(index + 1)};
            copy.push(next_value);
        }
        if (copy.size() == 0) {
            stacks_.pop_back();
        } else {
            stacks_.at(index) = copy;
        }
        return value;
    } else {
        throw std::invalid_argument("Index argument must be less than the vector size.");
    }
}

template<typename T>
std::string SetOfStacks<T>::to_string_recursive(size_t index) const {
    std::string out;
    if (index == stacks_.size()) {
        return out;
    }
    std::stack<T> copy{stacks_.at(index)};
    std::stack<T> reversed{};
    while (!copy.empty()) {
        reversed.push(copy.top());
        copy.pop();
    }
    while (!reversed.empty()) {
        out = out + "->" + std::to_string(reversed.top());
        reversed.pop();
    }
    out += to_string_recursive(index + 1);
    return out;
}

template<typename T>
SetOfStacks<T>::SetOfStacks(size_t capacity) : capacity_{capacity} {}

template<typename T>
std::stack<T>& SetOfStacks<T>::get_last_stack() {
    return stacks_.back();
}

template<typename T>
void SetOfStacks<T>::push(T v) {
    std::stack<T>& stack{get_last_stack()};
    if (stacks_.size() == 0 || stack.size() == capacity_) {
        std::stack<T> new_stack;
        new_stack.push(v);
        stacks_.push_back(new_stack);
    } else {
        stack.push(v);
    }
}

template<typename T>
T SetOfStacks<T>::pop() {
    if (is_empty()) {
        throw std::range_error("Stack is empty.");
    }
    std::stack<T>& stack{get_last_stack()};
    T value{stack.top()};
    stack.pop();
    if (stack.size() == 0) {
        stacks_.pop_back();
    }
    return value;
}

template<typename T>
T SetOfStacks<T>::pop_at(size_t index) {
    if (index >= stacks_.size()) {
       throw std::invalid_argument("Index argument must be less than the vector size.");
    }
    std::stack<T>& stack{stacks_.at(index)};
    T value{stack.top()};
    stack.pop();
    T shifted{left_shift(index + 1)};
    stack.push(shifted);
    return value;
}

template<typename T>
bool SetOfStacks<T>::is_empty() {
    return stacks_.size() == 0;
}

template<typename T>
std::string SetOfStacks<T>::to_string() {
    return to_string_recursive(0);
}

#endif // SETOFSTACKS_H_