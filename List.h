//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LIST_H
#define LABORATORIOPROGRAMMAZIONE_LIST_H

#include <string>
#include <list>
#include "Product.h"

class List {

public:
    explicit List(const std::string &name);

    virtual void addProduct(Product* product) = 0;

    virtual void removeProduct(Product* product) = 0;

    const std::string &getName() const;

    virtual Product* search(Product*) = 0;

    virtual Product* search(const std::string& name) = 0;

    virtual void printList() = 0;

    virtual ~List();

protected:
    std::string name;
    std::list<Product*> products;
};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
