#ifndef LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
#define LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H

#include "List.h"

class ProductList : public List{
public:
    explicit ProductList(const std::string &name);

    void addProduct(Product *product) override;

    void removeProduct(Product *product) override;

    Product* search(Product *product) override;

    Product* search(const std::string& name) override;

    void printList() override;
};


#endif //LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
