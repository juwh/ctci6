#ifndef STACKWITHSTACKMIN_H_
#define STACKWITHSTACKMIN_H_

#include "../introduction/MyStack.h"

template<typename T>
class StackWithStackMin : public MyStack<T> {
    private:
        MyStack<T> mins_;
    public:
        T pop();
        void push(T item);
        T min();
};

template<typename T>
T StackWithStackMin<T>::pop() {
    if (!mins_.is_empty() && min() == MyStack<T>::peek()) {
        mins_.pop();
    }
    return MyStack<T>::pop();
}

template<typename T>
void StackWithStackMin<T>::push(T item) {
    if (mins_.is_empty() || item <= min()) {
        mins_.push(item);
    }
    MyStack<T>::push(item);
}

template<typename T>
T StackWithStackMin<T>::min() {
    return mins_.is_empty() ? std::numeric_limits<T>::max() : mins_.peek();
}

#endif // STACKWITHSTACKMIN_H_