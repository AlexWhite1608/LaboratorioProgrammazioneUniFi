#ifndef LABORATORIOPROGRAMMAZIONE_CART_H
#define LABORATORIOPROGRAMMAZIONE_CART_H

#include "List.h"

class Cart : public List{
public:
    explicit Cart(const std::string &name);

    void printList() const override;

    void addProduct(Product *product) override;

    void removeProduct(Product *product) override;

    Product *searchProduct(Product *product) override;

};


#endif //LABORATORIOPROGRAMMAZIONE_CART_H
