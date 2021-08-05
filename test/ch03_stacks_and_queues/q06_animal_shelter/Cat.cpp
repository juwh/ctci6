#include "Cat.h"

Cat::Cat(std::string n) : Animal(n) {}
std::string Cat::name() {return "Cat: " + name_;}