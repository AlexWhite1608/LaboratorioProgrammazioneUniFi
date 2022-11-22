//
// Created by aless on 22/11/2022.
//

#include "Product.h"

Product::Product(const std::string &name, const std::string &category, unsigned int quantity) : name(name),
                                                                                                category(category),
                                                                                                quantity(quantity) {}

const std::string &Product::getName() const {
    return name;
}

const std::string &Product::getCategory() const {
    return category;
}

unsigned int Product::getQuantity() const {
    return quantity;
}

Product::~Product() {

}
