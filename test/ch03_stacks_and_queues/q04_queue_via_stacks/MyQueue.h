#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <stdexcept>
#include <stack>

template<typename T>
class MyQueue {
    private:
        std::stack<T> new_, old_;
        void shift();
    public:
        MyQueue();
        size_t size();
        void add(T value);
        T peek();
        T remove();
};

/* Move elements from stackNewest into stackOldest. This is usually done so that we can
 * do operations on stackOldest.
 */
template<typename T>
void MyQueue<T>::shift() {
    if (old_.empty()) {
        while (!new_.empty()) {
            old_.push(new_.top());
            new_.pop();
        }
    }
}

template<typename T>
MyQueue<T>::MyQueue() {}

template<typename T>
size_t MyQueue<T>::size() {
    return old_.size() + new_.size();
}

template<typename T>
void MyQueue<T>::add(T value) {
    new_.push(value);
}

template<typename T>
T MyQueue<T>::peek() {
    if (!size()) {
        throw std::range_error("Queue is empty.");
    }
    shift();
    return old_.top();
}

template<typename T>
T MyQueue<T>::remove() {
    if (!size()) {
        throw std::range_error("Queue is empty.");
    }
    shift();
    T value{old_.top()};
    old_.pop();
    return value;
}

#endif // MYQUEUE_H_