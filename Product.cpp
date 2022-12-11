//
// Created by aless on 22/11/2022.
//

#include <iostream>
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

void Product::editName(const std::string &newName) {
    this->name = newName;

    std::cout << "\nIl nuovo nome del prodotto è " << this->getName();
}

void Product::editQuantity(const unsigned int newQuantity) {
    this->quantity = newQuantity;

    std::cout << "\nIl nuova quantità del prodotto è " << this->getQuantity();
}
