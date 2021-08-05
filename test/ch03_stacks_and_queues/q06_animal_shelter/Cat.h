#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

class Cat : public Animal {
    public:
        Cat(std::string n);
        std::string name();
};

#endif // CAT_H_