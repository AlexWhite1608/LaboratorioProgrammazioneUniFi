#include <iostream>
#include "ProductList.h"

ProductList::ProductList(const std::string &name) : List(name) {}

void ProductList::addProduct(Product *product) {
    if(searchProduct(product) != nullptr){
        for(auto product_ : this->products){
            if(product_->getName() == product->getName()){
                product_->editQuantity(product_->getQuantity() + 1);
                std::cout << "Il prodotto e' gia' presente, aumentata la quantita'!" << std::endl;
            }
        }
    } else
        products.push_back(product);
}

void ProductList::removeProduct(Product *product) {
    if(searchProduct(product) != nullptr){
        for(auto product_ : this->products){
            if(product_->getName() == product->getName()){
                if(product_->getQuantity() > 1){
                    product_->editQuantity(product_->getQuantity() - 1);
                    break;
                } else if (product_->getQuantity() == 1){
                    this->products.remove(product);
                    break;
                }
            }
        }
    } else
        std::cout << product->getName() << " non è presente nella lista!" << std::endl;
}

Product *ProductList::searchProduct(Product *product) {
    for(auto& i : this->products){
        if (i == product)
            return i;
    }

    return nullptr;
}

void ProductList::printList() const {
    if(products.empty())
        std::cout << "Lista vuota!" << std::endl;

    for(auto i : products){
        std::cout << "\nNome prodotto: " << i->getName() << std::endl
                  << "Categoria: " << i->getCategory() << std::endl
                  << "Quantita': " << i->getQuantity() << std::endl
                  << "-------------- " << std::endl;
    }
}