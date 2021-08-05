#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog : public Animal {
    public:
        Dog(std::string n);
        std::string name();
};

#endif // DOG_H_