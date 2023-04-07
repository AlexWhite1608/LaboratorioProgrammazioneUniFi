#ifndef LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
#define LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H

#include "List.h"

class ProductList : public List{
public:
    explicit ProductList(const std::string &name);

    void printList() override;
};


#endif //LABORATORIOPROGRAMMAZIONE_PRODUCTLIST_H
