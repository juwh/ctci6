#ifndef STACKWITHNODEMIN_H_
#define STACKWITHNODEMIN_H_

#include "NodeWithMin.h"

#include <stack>

template<typename T>
class StackWithNodeMin : public std::stack<NodeWithMin<T>> {
    public:
        T pop();
        void push(T item);
        T min();
};

template<typename T>
T StackWithNodeMin<T>::pop() {
    T value{std::numeric_limits<T>::max()};
    if (!std::stack<NodeWithMin<T>>::empty()) {
        value = std::stack<NodeWithMin<T>>::top().value_;
        std::stack<NodeWithMin<T>>::pop();
    }
    return value;
}

template<typename T>
void StackWithNodeMin<T>::push(T item) {
    T cur_min{min()};
    std::stack<NodeWithMin<T>>::push({item, item < cur_min ? item : cur_min});
}

template<typename T>
T StackWithNodeMin<T>::min() {
    return std::stack<NodeWithMin<T>>::empty() ? std::numeric_limits<T>::max() : std::stack<NodeWithMin<T>>::top().min_;
}

#endif // STACKWITHNODEMIN_H_