#ifndef LABORATORIOPROGRAMMAZIONE_LIST_H
#define LABORATORIOPROGRAMMAZIONE_LIST_H

#include <string>
#include <list>
#include "Product.h"

class List {

public:
    explicit List(const std::string &name);

    const std::string &getName() const;

    virtual void printList() = 0;

    int getNumberProducts();

    std::list<Product *> &getProducts();

    virtual ~List() {
        for(auto product : products){
            delete product;
        }
    };

protected:
    std::string name;
    std::list<Product*> products;
};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
