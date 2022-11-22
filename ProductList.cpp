//
// Created by aless on 22/11/2022.
//

#include <iostream>
#include "ProductList.h"

ProductList::ProductList(const std::string &name) : List(name) {}

void ProductList::addProduct(Product *product) {

    if(search(product) != nullptr){
        for(auto product_ : products){
            if(product_->getName() == product->getName()){
                product_->editQuantity(product_->getQuantity() + 1);
                std::cout << "Il prodotto è già presente, aumentata la quantità!" << std::endl;
            }
        }
    } else
        products.push_back(product);

}

void ProductList::removeProduct(Product *product) {

    if(search(product) != nullptr){
        for(auto product_ : products){
            if(product_->getName() == product->getName() && product_->getQuantity() > 1){
                product_->editQuantity(product_->getQuantity() - 1);
                std::cout << "E' stato rimosso un articolo di " << product->getName() << ", ne rimangono " << product_->getQuantity() << std::endl;
            }
        }
    } else
        products.remove(product);

}

Product* ProductList::search(Product *product) {

    for(auto& i : products){
        if (i == product)
            return i;
    }

    return nullptr;
}
