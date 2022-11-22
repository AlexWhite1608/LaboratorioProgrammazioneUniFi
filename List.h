//
// Created by aless on 22/11/2022.
//

#ifndef LABORATORIOPROGRAMMAZIONE_LIST_H
#define LABORATORIOPROGRAMMAZIONE_LIST_H


#include <string>
#include <list>
#include "Product.h"

class List {


private:
    std::string name;
    unsigned int numberOfElements = 0;
    std::list<Product*> products;
};


#endif //LABORATORIOPROGRAMMAZIONE_LIST_H
