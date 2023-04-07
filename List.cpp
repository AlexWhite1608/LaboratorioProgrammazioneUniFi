#include "List.h"

List::List(const std::string &name) : name(name) {}

const std::string &List::getName() const {
    return name;
}

std::list<Product *> &List::getProducts(){
    return products;
}

int List::getNumberProducts() {
    return products.size();
}

