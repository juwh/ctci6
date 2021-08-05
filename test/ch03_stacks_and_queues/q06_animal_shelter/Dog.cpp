#include "Dog.h"

Dog::Dog(std::string n) : Animal(n) {}
std::string Dog::name() {return "Dog: " + name_;}