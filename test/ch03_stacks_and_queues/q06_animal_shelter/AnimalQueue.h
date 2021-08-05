#ifndef ANIMALQUEUE_H_
#define ANIMALQUEUE_H_

#include "Cat.h"
#include "Dog.h"

#include <list>
#include <memory>
#include <stdexcept>

class AnimalQueue {
    private:
        std::list<Dog> dogs_;
        std::list<Cat> cats_;
        size_t order_{0};
    public:
        void enqueue(Dog d);
        void enqueue(Cat c);
        std::unique_ptr<Animal> dequeue_any();
        std::unique_ptr<Animal> peek();
        size_t size();
        Dog dequeue_dogs();
        Dog peek_dogs();
        Cat dequeue_cats();
        Cat peek_cats();
};

#endif // ANIMALQUEUE_H_