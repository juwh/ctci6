#include "Animal.h"

Animal::Animal(std::string n) : name_{n} {}
Animal::~Animal() {}
std::string Animal::name() {return "";}
void Animal::set_order(size_t ord) {order_ = ord;}
size_t Animal::get_order() {return order_;}
bool Animal::is_older_than(Animal* a) {return order_ < a->get_order();}