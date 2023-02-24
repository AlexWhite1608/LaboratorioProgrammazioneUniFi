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

}

void Product::editQuantity(const unsigned int newQuantity) {
    this->quantity = newQuantity;
}
