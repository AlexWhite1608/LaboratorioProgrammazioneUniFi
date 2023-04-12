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

void Product::editName(const std::string &newName) {
    this->name = newName;

}

void Product::editQuantity(const unsigned int newQuantity) {
    if(newQuantity > 0)
        this->quantity = newQuantity;
    else
        std::cout << "Quantità inserita negativa!"<<std::endl;
}
