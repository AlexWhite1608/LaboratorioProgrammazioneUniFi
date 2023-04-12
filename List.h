#ifndef LABORATORIOPROGRAMMAZIONE_LIST_H
#define LABORATORIOPROGRAMMAZIONE_LIST_H

#include <string>
#include <list>
#include "Product.h"

class List {

public:
    explicit List(const std::string &name);

    const std::string &getName() const;

    int getNumberProducts() const;

    virtual void printList() const = 0;

    virtual void addProduct(Product* product) = 0;

    virtual void removeProduct(Product* product) = 0;

    virtual Product *searchProduct(Product* product) = 0;

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
