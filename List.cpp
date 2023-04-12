#include "List.h"

List::List(const std::string &name) : name(name) {}

const std::string &List::getName() const {
    return name;
}

int List::getNumberProducts() const{
    return products.size();
}

