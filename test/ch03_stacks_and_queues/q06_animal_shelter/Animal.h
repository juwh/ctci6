#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
    private:
        size_t order_;
    protected:
        std::string name_;
    public:
        Animal(std::string n);
        virtual ~Animal();
        virtual std::string name() = 0;
        void set_order(size_t ord);
        size_t get_order();
        bool is_older_than(Animal* a);
};

#endif // ANIMAL_H_