//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_CART_H
#define LABORATORIOPROGRAMMAZIONE_CART_H


#include "List.h"

class Cart : public List{
public:
    explicit Cart(const std::string &name);

    void addProduct(Product *product) override;

    void removeProduct(Product *product) override;

    Product * search(Product *product) override;

    void printList() override;

};


#endif //LABORATORIOPROGRAMMAZIONE_CART_H
