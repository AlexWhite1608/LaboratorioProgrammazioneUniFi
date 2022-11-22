//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_PRODUCT_H
#define LABORATORIOPROGRAMMAZIONE_PRODUCT_H

#include <string>

class Product {
public:
    Product(const std::string &name, const std::string &category, unsigned int quantity);

    virtual ~Product();

    const std::string &getName() const;

    const std::string &getCategory() const;

    unsigned int getQuantity() const;

private:
    std::string name;
    std::string category;
    unsigned int quantity = 0;

};


#endif //LABORATORIOPROGRAMMAZIONE_PRODUCT_H
