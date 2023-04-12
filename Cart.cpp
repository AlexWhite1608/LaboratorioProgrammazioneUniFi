#include <iostream>
#include "Cart.h"

Cart::Cart(const std::string &name) : List(name) {}

void Cart::printList() const {
    if(products.empty())
        std::cout << "Carrello vuoto!" << std::endl;

    for(auto i : products){
        std::cout << "\nNome prodotto: " << i->getName() << std::endl
                  << "Categoria: " << i->getCategory() << std::endl
                  << "Quantita': " << i->getQuantity() << std::endl
                  << "-------------- " << std::endl;
    }
}

void Cart::addProduct(Product *product) {
    if(searchProduct(product) != nullptr){
        for(auto product_ : this->products){
            if(product_->getName() == product->getName()){
                product_->editQuantity(product_->getQuantity() + 1);
                std::cout << "Il prodotto e' gia' presente nel carrello, aumentata la quantita'!" << std::endl;
            }
        }
    } else
        products.push_back(product);
}

void Cart::removeProduct(Product *product) {
    if(searchProduct(product) != nullptr){
        for(auto _product : this->products){
            if(_product->getName() == product->getName()){
                if(_product->getQuantity() > 1){
                    _product->editQuantity(_product->getQuantity() - 1);
                    break;
                } else if (_product->getQuantity() == 1){
                    this->products.remove(product);
                    break;
                }
            }
        }
    } else
        std::cout << product->getName() << " non è presente nel carrello!" << std::endl;
}

Product *Cart::searchProduct(Product *product) {
    for(auto& i : this->products){
        if (i == product)
            return i;
    }

    return nullptr;
}

