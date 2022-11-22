//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
#define LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H

#include "List.h"

class ProductList : public List{
public:
    explicit ProductList(const std::string &name);

    void addProduct(Product *product) override;

    void removeProduct(Product *product) override;

    bool search(Product *product) override;
};


#endif //LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
