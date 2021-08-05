#include "AnimalQueue.h"

void AnimalQueue::enqueue(Dog d) {
    d.set_order(order_++);
    dogs_.push_back(d);
}

void AnimalQueue::enqueue(Cat c) {
    c.set_order(order_++);
    cats_.push_back(c);
}

std::unique_ptr<Animal> AnimalQueue::dequeue_any() {
    if (!size()) {
        throw std::range_error("AnimalQueue is empty.");
    }
    std::unique_ptr<Animal> dog(new Dog(dogs_.front()));
    std::unique_ptr<Animal> cat(new Cat(cats_.front()));
    if (dog->is_older_than(cat.get())) {
        dogs_.pop_front();
        return dog;
    }
    cats_.pop_front();
    return cat;
}

std::unique_ptr<Animal> AnimalQueue::peek() {
    if (!size()) {
        throw std::range_error("AnimalQueue is empty.");
    }
    std::unique_ptr<Animal> dog(new Dog(dogs_.front()));
    std::unique_ptr<Animal> cat(new Cat(cats_.front()));
    if (dog->is_older_than(cat.get())) {
        return dog;
    }
    return cat;
}

size_t AnimalQueue::size() {
    return dogs_.size() + cats_.size();
}

Dog AnimalQueue::dequeue_dogs() {
    if (!dogs_.size()) {
        throw std::range_error("Dog queue is empty.");
    }
    auto dog{peek_dogs()};
    dogs_.pop_front();
    return dog;
}

Dog AnimalQueue::peek_dogs() {
    if (!dogs_.size()) {
        throw std::range_error("Dog queue is empty.");
    }
    return dogs_.front();
}

Cat AnimalQueue::dequeue_cats() {
    if (!cats_.size()) {
        throw std::range_error("Cat queue is empty.");
    }
    auto cat{peek_cats()};
    cats_.pop_front();
    return cat;
}

Cat AnimalQueue::peek_cats() {
    if (!cats_.size()) {
        throw std::range_error("Cat queue is empty.");
    }
    return cats_.front();
}