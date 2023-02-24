#include <iostream>
#include "Cart.h"

Cart::Cart(const std::string &name) : List(name) {}

void Cart::addProduct(Product *product) {
    if(search(product) != nullptr){
        for(auto product_ : products){
            if(product_->getName() == product->getName()){
                product_->editQuantity(product_->getQuantity() + 1);
                std::cout << "Il prodotto e' gia' presente, aumentata la quantita'!" << std::endl;
            }
        }
    } else
        products.push_back(product);

}

void Cart::removeProduct(Product *product) {

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

Product *Cart::search(Product *product) {

    for(auto& i : products){
        if (i == product)
            return i;
    }

    return nullptr;
}

void Cart::printList() {
    if(products.empty())
        std::cout << "Carrello vuoto!" << std::endl;

    for(auto i : products){
        std::cout << "\nNome prodotto: " << i->getName() << std::endl
                  << "Categoria: " << i->getCategory() << std::endl
                  << "Quantita': " << i->getQuantity() << std::endl
                  << "-------------- " << std::endl;
    }
}

Product *Cart::search(const std::string &name) {

    for(auto i : products){
        if (i->getName() == name)
            return i;
    }
    return nullptr;
}
